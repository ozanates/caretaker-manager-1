#ifndef SHOOT_H

#define SHOOT_H

#include "../../action.h"
#include "../../../Stadium/stadium.h"

class Shoot : public Action
{
public:
	Shoot(Random* r, Language* lang):Action(r,lang){};
	int checkPreconditions(SquadPosition*, Stadium*);
	bool execute(SquadPosition* , Stadium*);
};

#endif