#include "RiskyPass.h"
#include "../../../util.h"
#include <iostream>

#include "../../../Club/club.h"

int RiskyPass::checkPreconditions(SquadPosition* player, Stadium* stadium)
{
	// If player is far from ball, he cannot kick the ball.
	if ( distanceBetween(player->getPosition(),stadium->ball->getPosition2()) > REACHING_DISTANCE ) 
		return 0;

	// If player didn't control the ball, he won't kick the ball (for now).
	if (player->club->sinceBallIsPassed>0)
		return 0;

	// Calculate reaction time.
	float reaction_time = 1.2 - (player->get_footballer()->reaction * 0.01 * 0.6);
	if (player->sinceBallIsControlled>0 && player->sinceBallIsControlled<reaction_time)
		return 0;

	// Look for pass opportunities
	SquadPosition** team = player->club->lineUp;
	Club* otherClub = (stadium->club0==player->club)?stadium->club1:stadium->club0;
	SquadPosition* target;
	Footballer* footballer = player->get_footballer();
	std::multimap<float,int> possibilities;
	for (int i=0; i<11; i++)
	{
		target = team[i];
		float distance = distanceBetween(target->getPosition(),player->getPosition());
		float skill_effect = (footballer->concentration + 5.0*footballer->passingVision)/600.0;
		float visionDistance = skill_effect*70.0;
		if (target!=player && distance>10 && distance<visionDistance && !otherClub->isSomeoneThere_points(player->getPosition(),target->getPosition(),2))
		{
			float howAdvancedTargetIs = target->getPosition().x;
			if (player->club->onTheRightGoal) howAdvancedTargetIs = stadium->playArea.width - howAdvancedTargetIs;
			possibilities.insert( std::pair<float,int>(random->get_float(-1.5,-0.5)*(howAdvancedTargetIs+distance),i) );
		}
	}

	if (possibilities.size()==0)
		return 0;
	player->target_simplePass = team[possibilities.begin()->second];

	return (750 - 10 * (0.5-player->freq_riskyPassing) + random->get_int(0,100) );
};

bool RiskyPass::execute(SquadPosition* player, Stadium* stadium)
{
	player->sinceBallIsControlled = 0;

	sf::Vector2f ball = stadium->ball->getPosition2();
	Club* otherclub = (player->club->isAway)?stadium->club0 : stadium->club1;

	SquadPosition* targetPlayer = player->target_simplePass;

	float destination_x = targetPlayer->x;
	float destination_y = targetPlayer->y;
	float difx = (destination_x - ball.x);
	float dify = (destination_y - ball.y);

	float angle = atan2(dify,difx); // it is the ideal angle.
	float distance = distanceBetween(sf::Vector2f(destination_x,destination_y),ball);
	int short_passing = player->get_footballer()->shortPassing;
	int long_passing = player->get_footballer()->longPassing;
	int skill_effect = (distance<40)?short_passing:long_passing;
	float sd = 0.2 - (0.15 * skill_effect * 0.01);
	angle += random->get_normald(0,sd);

	difx = distance*cos(angle);
	dify = distance*sin(angle);

	player->club->sinceBallIsPassed = 1.0/60.0;
	player->club->ballPassedFrom = sf::Vector2f(ball);

	sf::Vector2f new_impulse = CalculatePassImpulse(sf::Vector2f(difx,dify));
	stadium->ball->applyImpulse(sf::Vector3f(new_impulse.x,random->get_float(1.0,2.5),new_impulse.y),sf::Vector3f(0,0,0));
	stadium->lastTeamTouchedTheBall = player->club->isAway;

	if (distanceBetween(player->getPosition(),ball)>40)
		stadium->commentator = player->get_footballer()->fullName_shown + language->ACTION_00005 + targetPlayer->get_footballer()->fullName_shown + L".";
	else
		stadium->commentator = player->get_footballer()->fullName_shown + language->ACTION_00003;

	player->countdown_showName = 180;

	if(DEBUG_SHOW_WITHBALLDECISIONS) 
		wcout << player->get_footballer()->shortName_shown << ": pass to " << targetPlayer->get_footballer()->shortName_shown << ".///" << endl;
	return true;
};