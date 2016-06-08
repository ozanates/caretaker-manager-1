#ifndef TAKEATTACKINGPOSITION_H

#define TAKEATTACKINGPOSITION_H

#include "../../action.h"
#include "../../../Stadium/stadium.h"

class TakeAttackingPosition : public Action
{
public:
	TakeAttackingPosition(Random* r, Language* lang):Action(r,lang){};
	int checkPreconditions(SquadPosition*, Stadium*);
	bool execute(SquadPosition* , Stadium*);
};

#endif