#include "ControlThePass.h"
#include "../../../util.h"
#include <iostream>

#include "../../../Club/club.h"
//#include "../../SquadPosition/squadPosition.h"

int ControlThePass::checkPreconditions(SquadPosition* player, Stadium* stadium)
{
	if (player->club->sinceBallIsPassed==0)
		return 0;

	// If player is far from ball, he cannot control the pass.
	float player_to_ball = distanceBetween(player->getPosition(),stadium->ball->getPosition2());
	if ( player_to_ball > REACHING_DISTANCE ) 
		return 0;

	float player_to_source = distanceBetween(player->getPosition(),player->club->ballPassedFrom);

	if (player->get_footballer()->number == 36)
		int kdnef = 2+2;

	if ( player_to_source < 3.0 * REACHING_DISTANCE )
		return 0;

	return 700;
};

bool ControlThePass::execute(SquadPosition* player, Stadium* stadium)
{
	player->club->sinceBallIsPassed = 0; // Pass is taken.
	player->sinceBallIsControlled = 1.0/60.0; // Start the counter for the reaction after control.

	stadium->ball->setLinearVelocity(sf::Vector3f(random->get_float(0,0.5),random->get_float(0,0.5),random->get_float(0,0.5)));
	stadium->lastTeamTouchedTheBall = player->club->isAway;
	player->club->someoneGettingBall = false;

	stadium->commentator = player->get_footballer()->fullName_shown + language->ACTION_00001;

	player->countdown_showName = 180;

	if(DEBUG_SHOW_WITHBALLDECISIONS) 
		std::wcout << player->get_footballer()->shortName_shown << ": controlling the pass. ///" << std::endl;
	return true;
};