#ifndef TAKEDEFENDINGPOSITION_H

#define TAKEDEFENDINGPOSITION_H

#include "../../action.h"
#include "../../../Stadium/stadium.h"

class TakeDefendingPosition : public Action
{
public:
	TakeDefendingPosition(Random* r, Language* lang):Action(r,lang){};
	int checkPreconditions(SquadPosition*, Stadium*);
	bool execute(SquadPosition* , Stadium*);
};

#endif