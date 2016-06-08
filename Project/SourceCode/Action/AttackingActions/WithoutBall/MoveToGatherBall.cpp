#include "MoveToGatherBall.h"
#include "../../../util.h"
#include <iostream>
#include "../../../Club/club.h"

#define _USE_MATH_DEFINES
#include "math.h"

int MoveToGatherBall::checkPreconditions(SquadPosition* player, Stadium* stadium)
{
	if (player->club->someoneGettingBall)
	{
		SquadPosition* getting = player->club->playerGettingBall;
		// If you decided to get earlier, continue
		if (getting==player)
			float dkgjsl = 4; //return 2000;
		// If someone getting the ball, don't try to get it
		else
			return 0;
	}

	// If player is already close to ball
	float player_to_ball = distanceBetween(player->getPosition(),stadium->ball->getPosition2());
	if ( player_to_ball<=REACHING_DISTANCE)
		return 0;

	// TODO: Remove this
	sf::Vector3f velo3f = stadium->ball->getLinearVelocity();
	float velo = distanceBetween(sf::Vector2f(velo3f.x,velo3f.z),sf::Vector2f(0,0));
	if ( (velo<5.0) && (player->club->closestPlayer==player)  )
	{
		player->destination = stadium->ball->getPosition2();
		player->currentDuty = moveToGatherBall;
		return 2000;
	}

	// If player cannot react yet
	Footballer* footballer = player->get_footballer();
	float reaction_effect = (footballer->concentration+footballer->reaction)/2;

	float reaction_time = 0.3+((100.0-reaction_effect)/50.0);

	if (player->club->sinceBallIsPassed<reaction_time)
		return 0;

	// If player cannot catch the ball
	sf::Vector2f* source = &player->club->ballPassedFrom;
	sf::Vector2f* current = &stadium->ball->getPosition2();
	sf::Vector2f intersection;

	float a_ballLine = (current->y - source->y)/(current->x - source->x); // y=ax+b line for the ball
	float b_ballLine = current->y - current->x * a_ballLine;
	float a_playerLine = -1 * a_ballLine; // y=ax+b line for the player to intercept the ball
	float b_playerLine = player->y - player->x * a_playerLine;
	intersection.x = (b_ballLine-b_playerLine)/(a_playerLine-a_ballLine);
	intersection.y = intersection.x * a_ballLine + b_ballLine;

	// Ball is getting away from player
	if( !isBetweenTwoPoints(*current,*source,intersection) )
		return 0;

	float player_to_destination = distanceBetween(intersection,sf::Vector2f(player->x,player->y));
	float ball_to_destination = distanceBetween(intersection,*current); 
	float ball_from_source = distanceBetween(*source,*current);
	
	float maxsp = footballer->getMaxSpeed();

	float estimatedtime_ball = player->club->sinceBallIsPassed * ball_to_destination / ball_from_source;
	float estimatedtime_player = player_to_destination / (maxsp*60.0);
	if (estimatedtime_ball<estimatedtime_player)
		return 0;

	// TODO: Intersection should be in the play area.

	player->destination = intersection;
	player->currentDuty = moveToGatherBall;

	return 4000;
};

bool MoveToGatherBall::execute(SquadPosition* player, Stadium* stadium)
{
	if (player->currentDuty != moveToGatherBall)
		cout << "ERROR: Duty is not moveToGatherBall" << endl;

	// Calculate speed
	float travelOverFrame;

	sf::Vector2f target = player->destination;
	Footballer* footballer = player->get_footballer();

	float target_theta = atan2( (target.y-player->y), (target.x-player->x) );
	float difference_theta = abs(target_theta - player->theta);
	while (difference_theta > M_PI){
		difference_theta -= M_PI;}

	float max_speed = footballer->getMaxSpeed();
	float agility_effect = 0.2 + 0.3 * footballer->agility / 100;
	max_speed *= (agility_effect + (1-agility_effect)* abs(M_PI-difference_theta) / M_PI);

	float change_of_speed = footballer->getMaxAcceleration();
	travelOverFrame = player->lastMotion + change_of_speed;
	if (travelOverFrame>max_speed) travelOverFrame=max_speed;

	// Go towards the calculated position
	player->lastMotion = player->goTowardsPoint(target.x,target.y,travelOverFrame);
	if (abs(difference_theta-player->theta)<0.1)
		player->theta = difference_theta;
	else
	{
		difference_theta = difference_theta-player->theta;
		player->theta = player->theta + 0.1 * abs(difference_theta) / difference_theta;
	}
	player->club->someoneGettingBall = true; //TODO: Maybe we can remove it so that more than one player can go to the ball.
	player->club->playerGettingBall = player;

	if(DEBUG_SHOWACTIONDECISIONS) 
		std::wcout << player->get_footballer()->shortName_shown << ": moving to gather the ball. ///" << std::endl;
	return true;
};