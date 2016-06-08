#ifndef ACTIONPILE_H

#define ACTIONPILE_H

#include "AttackingActions\WithBall\SimplePass.h"
#include "AttackingActions\WithBall\RiskyPass.h"
#include "AttackingActions\WithBall\Wait.h"
#include "AttackingActions\WithBall\ControlThePass.h"
#include "AttackingActions\WithBall\HoldAndDribble.h"
#include "AttackingActions\WithBall\DribbleForward.h"
#include "AttackingActions\WithBall\Cross.h"
#include "AttackingActions\WithBall\Shoot.h"

#include "AttackingActions\WithoutBall\TakeAttackingPosition.h"
#include "AttackingActions\WithoutBall\GoForward.h"
#include "AttackingActions\WithoutBall\ComeCloseToBall.h"
#include "AttackingActions\WithoutBall\MoveToGatherBall.h"
#include "AttackingActions\WithoutBall\RunBehindDefence.h"
#include "AttackingActions\WithoutBall\GetIntoBox.h"

#include "DefendingActions\FarFromBall\TakeDefendingPosition.h"

#define REACHING_DISTANCE 1.0

#endif