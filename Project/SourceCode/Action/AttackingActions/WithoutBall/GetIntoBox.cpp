#include "GetIntoBox.h"
//#include "../../util.h"
#include <iostream>

int GetIntoBox::checkPreconditions(SquadPosition* player, Stadium* stadium)
{
	
	return 0;
};

bool GetIntoBox::execute(SquadPosition* player, Stadium* stadium)
{
	if(DEBUG_SHOWACTIONDECISIONS) std::cout << "TAKING ATTACKING POSITION" << std::endl;
	return true;
};