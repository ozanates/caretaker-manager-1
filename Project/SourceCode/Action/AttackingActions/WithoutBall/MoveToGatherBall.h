#ifndef MOVETOGATHERBALL_H

#define MOVETOGATHERBALL_H

#include "../../action.h"
#include "../../../Stadium/stadium.h"

class MoveToGatherBall : public Action
{
public:
	MoveToGatherBall(Random* r, Language* lang):Action(r,lang){};
	int checkPreconditions(SquadPosition*, Stadium*);
	bool execute(SquadPosition* , Stadium*);
};

#endif