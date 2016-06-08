#ifndef ACTION_H

#define ACTION_H

#include "../SquadPosition/squadposition.h"
#include "../Stadium/stadium.h"
#include "../random.h"

#include "..\debugoptions.h"

class Action
{
public:
	Random* random;
	Language* language;

	Action(Random* r,Language* lang):random(r),language(lang){};
	virtual int checkPreconditions(SquadPosition*, Stadium*)=0;
	virtual bool execute(SquadPosition* , Stadium*)=0;
};

#endif