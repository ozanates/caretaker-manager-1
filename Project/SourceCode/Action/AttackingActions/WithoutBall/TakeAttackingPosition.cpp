#include "TakeAttackingPosition.h"
#include "../../../util.h"
#include <iostream>
#include "../../../Club/club.h"

#define _USE_MATH_DEFINES
#include "math.h"

int TakeAttackingPosition::checkPreconditions(SquadPosition* player, Stadium* stadium)
{
	return 100;
};

bool TakeAttackingPosition::execute(SquadPosition* player, Stadium* stadium)
{
	Club* hisclub = player->club;
	Footballer* footballer = player->get_footballer();
	float stadium_width = stadium->playArea.width;
	float stadium_height = stadium->playArea.height;
	float goalEffect = (hisclub->onTheRightGoal)?(-1.0):(1.0);
	float travelOverFrame;

	// Calcuate position
	float target_x, target_y;

	float howFar_leftmost = (hisclub->onTheRightGoal)?
		(hisclub->currentLeftmost):(stadium_width - hisclub->currentLeftmost);
	target_x = hisclub->currentLeftmost + howFar_leftmost * player->tactical_x * goalEffect;

	float y_pos = (hisclub->onTheRightGoal)?(1.0-player->tactical_y):player->tactical_y;
	target_y = hisclub->currentUppermost + hisclub->currentWidth * y_pos;

	stadium->makeItInside(&target_x,&target_y);
	
	// Calculate speed.
	float target_theta = atan2( (target_y-player->y), (target_x-player->x) );
	float difference_theta = abs(target_theta - player->theta);

	while (difference_theta > M_PI){ difference_theta -= 2*M_PI; }
	while (difference_theta < -M_PI){ difference_theta += 2*M_PI; }

	float max_speed = footballer->getMaxSpeed();
	float agility_effect = 0.2 + 0.3 * footballer->agility / 100;
	max_speed *= (agility_effect + (1-agility_effect)* abs(M_PI-difference_theta) / M_PI);

	float change_of_speed = footballer->getMaxAcceleration();
	travelOverFrame = player->lastMotion + change_of_speed;
	if (travelOverFrame>max_speed) travelOverFrame=max_speed;

	// Go towards the calculated position
	player->lastMotion = player->goTowardsPoint(target_x,target_y,travelOverFrame);
	player->theta = (player->club->onTheRightGoal)?M_PI:0;

	if(DEBUG_SHOWACTIONDECISIONS) 
		std::wcout << player->get_footballer()->shortName_shown << ": taking attacking position. ///" << std::endl;
	return true;
};