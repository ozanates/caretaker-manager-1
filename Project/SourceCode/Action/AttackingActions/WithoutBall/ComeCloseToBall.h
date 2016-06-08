#ifndef COMECLOSETOBALL_H

#define COMECLOSETOBALL_H

#include "../../action.h"
#include "../../../Stadium/stadium.h"

class ComeCloseToBall : public Action
{
public:
	ComeCloseToBall(Random* r, Language* lang):Action(r,lang){};
	int checkPreconditions(SquadPosition*, Stadium*);
	bool execute(SquadPosition* , Stadium*);
};

#endif