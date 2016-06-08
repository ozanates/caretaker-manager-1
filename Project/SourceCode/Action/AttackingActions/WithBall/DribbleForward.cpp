#include "DribbleForward.h"
#include "../../../util.h"
#include <iostream>
#include "../../../Club/club.h"

#define _USE_MATH_DEFINES
#include "math.h"

int DribbleForward::checkPreconditions(SquadPosition* player, Stadium* stadium)
{
	// Don't try to dribble near the touchline
	sf::Vector2f ball_pos = stadium->ball->getPosition2();
	if(ball_pos.y<0.1 || ball_pos.y>stadium->playArea.height)
		return 0;

	sf::Vector2f player_pos = player->getPosition();
	// If player is far from ball, he cannot dribble.
	if ( distanceBetween(player_pos,ball_pos) > REACHING_DISTANCE ) 
		return 0;

	float velocity_magnitude = stadium->ball->getMagnitude_2DLinearVelocity();
	// If player didn't control the fast ball, he won't try to dribble.
	if (player->club->sinceBallIsPassed>0 && velocity_magnitude>3.0 )
		return 0;

	// Calculate reaction time.
	float reaction_time = 1.2 - (player->get_footballer()->reaction * 0.01 * 0.6);
	if (player->sinceBallIsControlled>0 && player->sinceBallIsControlled<reaction_time)
		return 0;

	float dribbling_distance = 10.0;

	float dribbling_weight = 850 + 10 * (0.5-player->freq_dribblingForward) + random->get_int(0,100);
	
	// Find space. Return 0 if there is not
	float alpha = player->club->onTheRightGoal ? M_PI : 0;
	sf::Vector2f target;
	target.x = player_pos.x + ( dribbling_distance * cos(alpha) );
	target.y = player_pos.y + ( dribbling_distance * sin(alpha) );
	// Look for middle
	Club* otherClub = (stadium->club0==player->club)?stadium->club1:stadium->club0;
	if ( !otherClub->isSomeoneThere_points( player_pos, target,10.0) )
	{ // Middle is free
		player->destination = target;
		player->currentDuty = dribble;
		return dribbling_weight;
	}
	else 
	{
		alpha = random->get_float(0.1,1.0);
		target.x = player_pos.x + ( dribbling_distance * cos(alpha) );
		target.y = player_pos.y + ( dribbling_distance * sin(alpha) );
		if ( !otherClub->isSomeoneThere_points( player_pos, target,2) )
		{ // right is free
			player->destinationDribbling = target;
			return dribbling_weight;
		}
		else
		{
			alpha = random->get_float(-1.0,-0.1);
			target.x = player_pos.x + ( dribbling_distance * cos(alpha) );
			target.y = player_pos.y + ( dribbling_distance * sin(alpha) );
			if ( !otherClub->isSomeoneThere_points( player_pos, target,2) )
			{ // left is free
				player->destinationDribbling = target;
				return dribbling_weight;
			}
		}
	}
	return 0;
};

bool DribbleForward::execute(SquadPosition* player, Stadium* stadium)
{
	float target_y = player->destinationDribbling.y;
	float target_x = player->destinationDribbling.x;
	sf::Vector2f ball = stadium->ball->getPosition2();

	Footballer* footballer = player->get_footballer();	

	if( distanceBetween(player->getPosition(),ball) > 0.05 && isBetweenTwoPoints(ball,player->getPosition(),sf::Vector2f(target_x,target_y)) )
	{ // if the ball is not in your feet, go towards ball.

		// Calculate speed.
		float travelOverFrame;
		float target_theta = atan2( (target_y-player->y), (target_x-player->x) );
		float difference_theta = abs(target_theta - player->theta);

		while (difference_theta > M_PI){
			difference_theta -= 2*M_PI;
		}
		while (difference_theta < -M_PI){
			difference_theta += 2*M_PI;
		}

		float max_speed = footballer->getMaxSpeed();
		float agility_effect = 0.2 + 0.3 * footballer->agility / 100;
		max_speed *= (agility_effect + (1-agility_effect)* abs(M_PI-difference_theta) / M_PI);

		float change_of_speed = footballer->getMaxAcceleration();
		travelOverFrame = player->lastMotion + change_of_speed;
		if (travelOverFrame>max_speed) travelOverFrame=max_speed;

		// Go towards the calculated position
		player->lastMotion = player->goTowardsPoint(target_x,target_y,travelOverFrame);
		player->theta = (player->club->onTheRightGoal)?M_PI:0;
	}
	else
	{ // if the ball is in your feet, kick the ball just a little forward. 

		float kicking_speed = 2.0 ; // - player->dribbling

		float difx = (target_x - ball.x);
		float dify = (target_y - ball.y);
		float magnitude_dif = sqrt ( pow(difx,2)+pow(dify,2) );

		float random_change = random->get_float(2.5,5.5);

		difx *= random_change/magnitude_dif;
		dify *= random_change/magnitude_dif;

		stadium->ball->setLinearVelocity(sf::Vector3f(difx,0.1,dify));

		//sf::Vector2f new_impulse = CalculatePassImpulse(sf::Vector2f(difx,dify));
		//stadium->ball->applyImpulse(sf::Vector3f(new_impulse.x,0.1,new_impulse.y),sf::Vector3f(0,0,0));
		stadium->lastTeamTouchedTheBall = player->club->isAway;
	}

	stadium->commentator = player->get_footballer()->fullName_shown + language->ACTION_00004;

	return true;
};