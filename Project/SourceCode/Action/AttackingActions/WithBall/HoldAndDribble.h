#ifndef HOLDANDRIBBLE_H

#define HOLDANDRIBBLE_H

#include "../../action.h"
#include "../../../Stadium/stadium.h"

class HoldAndDribble : public Action
{
public:
	HoldAndDribble(Random* r, Language* lang):Action(r,lang){};
	int checkPreconditions(SquadPosition*, Stadium*);
	bool execute(SquadPosition* , Stadium*);
};

#endif