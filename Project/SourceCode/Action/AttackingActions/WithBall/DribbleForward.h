#ifndef DRIBBLEFORWARD_H

#define DRIBBLEFORWARD_H

#include "../../action.h"
#include "../../../Stadium/stadium.h"

class DribbleForward : public Action
{
public:
	DribbleForward(Random* r, Language* lang):Action(r,lang){};
	int checkPreconditions(SquadPosition*, Stadium*);
	bool execute(SquadPosition* , Stadium*);
};

#endif