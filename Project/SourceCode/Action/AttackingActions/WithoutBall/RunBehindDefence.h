#ifndef RUNBEHINDDEFENCE_H

#define RUNBEHINDDEFENCE_H

#include "../../action.h"
#include "../../../Stadium/stadium.h"

class RunBehindDefence : public Action
{
public:
	RunBehindDefence(Random* r, Language* lang):Action(r,lang){};
	int checkPreconditions(SquadPosition*, Stadium*);
	bool execute(SquadPosition* , Stadium*);
};

#endif