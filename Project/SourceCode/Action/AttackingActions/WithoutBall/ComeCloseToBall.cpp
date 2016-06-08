#include "ComeCloseToBall.h"
//#include "../../util.h"
#include <iostream>

int ComeCloseToBall::checkPreconditions(SquadPosition* player, Stadium* stadium)
{
	
	return 0;
};

bool ComeCloseToBall::execute(SquadPosition* player, Stadium* stadium)
{
	if(DEBUG_SHOWACTIONDECISIONS) std::cout << "TAKING ATTACKING POSITION" << std::endl;
	return true;
};