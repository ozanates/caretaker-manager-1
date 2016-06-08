#include "Cross.h"
#include "../../../util.h"
#include <iostream>

#include "../../../Club/club.h"

int Cross::checkPreconditions(SquadPosition* player, Stadium* stadium)
{
	// If player is far from ball, he cannot shoot.
	if ( distanceBetween(player->getPosition(),stadium->ball->getPosition2()) > REACHING_DISTANCE ) 
		return 0;

	return 0;
};

bool Cross::execute(SquadPosition* player, Stadium* stadium)
{
	
	return true;
};