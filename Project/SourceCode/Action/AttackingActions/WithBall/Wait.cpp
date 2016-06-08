#include "Wait.h"
#include "../../../util.h"
#include <iostream>

#include "../../../Club/club.h"

int Wait::checkPreconditions(SquadPosition* player, Stadium* stadium)
{
	// If player is far from ball, he cannot wait with the ball.
	if ( distanceBetween(player->getPosition(),stadium->ball->getPosition2()) > REACHING_DISTANCE ) 
		return 0;

	return 2000;
};

bool Wait::execute(SquadPosition* player, Stadium* stadium)
{
	if (player->sinceBallIsControlled==0)
		wcout << "error: ball is not controlled. player(" << player->get_footballer()->shortName_shown << ")" << endl;

	player->sinceBallIsControlled += 1.0/60.0;
	

	if(DEBUG_SHOW_WITHBALLDECISIONS) 
		std::wcout << player->get_footballer()->shortName_shown << ": waiting. ///" << std::endl;
	return true;
};