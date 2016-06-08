#ifndef GOFORWARD_H

#define GOFORWARD_H

#include "../../action.h"
#include "../../../Stadium/stadium.h"

class GoForward : public Action
{
public:
	GoForward(Random* r, Language* lang):Action(r,lang){};
	int checkPreconditions(SquadPosition*, Stadium*);
	bool execute(SquadPosition* , Stadium*);
};

#endif