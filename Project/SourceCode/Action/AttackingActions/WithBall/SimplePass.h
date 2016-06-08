#ifndef SIMPLEPASS_H

#define SIMPLEPASS_H

#include "../../action.h"
#include "../../../Stadium/stadium.h"

class SimplePass : public Action
{
public:
	SimplePass(Random* r, Language* lang):Action(r,lang){};
	int checkPreconditions(SquadPosition*, Stadium*);
	bool execute(SquadPosition* , Stadium*);
};

#endif