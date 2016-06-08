#include "RunBehindDefence.h"
#include <iostream>

int RunBehindDefence::checkPreconditions(SquadPosition* player, Stadium* stadium)
{
	
	return 0;
};

bool RunBehindDefence::execute(SquadPosition* player, Stadium* stadium)
{
	if(DEBUG_SHOWACTIONDECISIONS) std::cout << "TAKING ATTACKING POSITION" << std::endl;
	return true;
};