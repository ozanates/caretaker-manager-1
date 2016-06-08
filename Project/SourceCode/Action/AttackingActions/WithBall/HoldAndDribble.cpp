#include "HoldAndDribble.h"
#include "../../../util.h"
#include <iostream>

#include "../../../Club/club.h"

int HoldAndDribble::checkPreconditions(SquadPosition* player, Stadium* stadium)
{
	// If player is far from ball, he cannot hold the ball.
	if ( distanceBetween(player->getPosition(),stadium->ball->getPosition2()) > REACHING_DISTANCE ) 
		return 0;


	return 0;
};

bool HoldAndDribble::execute(SquadPosition* player, Stadium* stadium)
{
	return true;
};