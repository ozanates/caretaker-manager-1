#ifndef CONTROLTHEPASS_H

#define CONTROLTHEPASS_H

#include "../../action.h"
#include "../../../Stadium/stadium.h"

class ControlThePass : public Action
{
public:
	ControlThePass(Random* r, Language* lang):Action(r,lang){};
	int checkPreconditions(SquadPosition*, Stadium*);
	bool execute(SquadPosition* , Stadium*);
};

#endif