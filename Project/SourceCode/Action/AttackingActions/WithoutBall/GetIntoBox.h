#ifndef GETINTOBOX_H

#define GETINTOBOX_H

#include "../../action.h"
#include "../../../Stadium/stadium.h"

class GetIntoBox : public Action
{
public:
	GetIntoBox(Random* r, Language* lang):Action(r,lang){};
	int checkPreconditions(SquadPosition*, Stadium*);
	bool execute(SquadPosition* , Stadium*);
};

#endif