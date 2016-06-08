#ifndef WAIT_H

#define WAIT_H

#include "../../action.h"
#include "../../../Stadium/stadium.h"

class Wait : public Action
{
public:
	Wait(Random* r, Language* lang):Action(r,lang){};
	int checkPreconditions(SquadPosition*, Stadium*);
	bool execute(SquadPosition* , Stadium*);
};

#endif