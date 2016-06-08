#ifndef RISKYPASS_H

#define RISKYPASS_H

#include "../../action.h"
#include "../../../Stadium/stadium.h"

class RiskyPass : public Action
{
public:
	RiskyPass(Random* r, Language* lang):Action(r,lang){};
	int checkPreconditions(SquadPosition*, Stadium*);
	bool execute(SquadPosition* , Stadium*);
};

#endif