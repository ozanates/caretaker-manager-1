#ifndef CROSS_H

#define CROSS_H

#include "../../action.h"
#include "../../../Stadium/stadium.h"

class Cross : public Action
{
public:
	Cross(Random* r, Language* lang):Action(r,lang){};
	int checkPreconditions(SquadPosition*, Stadium*);
	bool execute(SquadPosition* , Stadium*);
};

#endif