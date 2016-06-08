#define _USE_MATH_DEFINES

#include "club.h"
#include <iostream>
#include <map>
#include "math.h"
#include "../Stadium/stadium.h"
#include "../SquadPosition/squadPosition.h"

Club::Club(Stadium *s, int _id, bool _goal)
{
	stadium = s;
	onTheRightGoal = _goal;

	sinceBallIsPassed = 0;
	someoneGettingBall = false;

	SquadPosition* sqp;
	for (int i=0; i<11; i++)
	{
		sqp = new SquadPosition;
		lineUp[i] = sqp;
	}
	
	for (int i=0; i<12; i++)
	{
		sqp = new SquadPosition;
		subs[i] = sqp;
	}	

	for (int i=0; i<12; i++)
	{
		sqp = new SquadPosition;
		reserves[i] = sqp;
	}

	switch(_id)
	{
	case ID_LEICESTER16:
		init_c_leicester16();
		break;
	case ID_MANUNITED16:
		init_c_manunited16();
		break;
	default:
		cout << "Error at club initialization. Wrong ID." << endl;
	}

	sortLineUp();
	assignClubs();
	initializeActions();
}

Club::~Club()
{
	for (int i=0; i<reservesSize; i++)
	{
		delete reserves[i]->get_footballer();
		delete reserves[i];
	}

	for (int i=0; i<subsSize; i++)
	{
		delete subs[i]->get_footballer();
		delete subs[i];
	}

	for (int i=0; i<11; i++)
	{
		delete lineUp[i]->get_footballer();
		delete lineUp[i];
	}
}

void Club::assignClubs()
{
	for (int i=0; i<11; i++)
	{
		lineUp[i]->club=this;
	}

	for (int i=0; i<subsSize; i++)
	{
		subs[i]->club=this;
	}

	for (int i=0; i<reservesSize; i++)
	{
		reserves[i]->club=this;
	}
}

void Club::assignFootballer(SquadPosition* sp, int id, MainPosition mP, AligningPosition aP) 
{ 
	Footballer* temp = new Footballer(id);
	sp->set_footballer(temp);
	sp->mainPosition=mP;
	sp->aligningPosition=aP;
};

void Club::sortLineUp()
{
	std::multimap<int,SquadPosition*> sorted;
	for (int i=0; i<11; i++)
	{
		int value = (lineUp[i]->mainPosition *100) + lineUp[i]->aligningPosition;
		sorted.insert( std::pair<int,SquadPosition*>(value,lineUp[i]) );
	}
	int counter=0;
	for (std::multimap<int,SquadPosition*>::iterator it=sorted.begin(); it!=sorted.end(); it++)
	{
		lineUp[counter] = it->second;
		counter++;
	}
};

void Club::initializeActions()
{
	// PUSH BACK ATTACKING ACTIONS

	// WITH BALL
	Action* simplePass = new SimplePass(stadium->random, stadium->language);
	attackingActions.push_back(simplePass);

	Action* riskyPass = new RiskyPass(stadium->random, stadium->language);
	attackingActions.push_back(riskyPass);

	Action* wait = new Wait(stadium->random, stadium->language);
	attackingActions.push_back(wait);

	Action* controlThePass = new ControlThePass(stadium->random, stadium->language);
	attackingActions.push_back(controlThePass);

	Action* holdAndDribble = new HoldAndDribble(stadium->random, stadium->language);
	attackingActions.push_back(holdAndDribble);

	Action* dribbleForward = new DribbleForward(stadium->random, stadium->language);
	attackingActions.push_back(dribbleForward);

	Action *cross = new Cross(stadium->random, stadium->language);
	attackingActions.push_back(cross);

	Action *shoot = new Shoot(stadium->random, stadium->language);
	attackingActions.push_back(shoot);

	// WITHOUT BALL
	Action* takeAttackingPosition = new TakeAttackingPosition(stadium->random, stadium->language);
	attackingActions.push_back(takeAttackingPosition);

	Action* goForward = new GoForward(stadium->random, stadium->language);
	attackingActions.push_back(goForward);

	Action* comeCloseToBall = new ComeCloseToBall(stadium->random, stadium->language);
	attackingActions.push_back(comeCloseToBall);

	Action* moveToGatherBall = new MoveToGatherBall(stadium->random, stadium->language);
	attackingActions.push_back(moveToGatherBall);

	Action* getIntoBox = new GetIntoBox(stadium->random, stadium->language);
	attackingActions.push_back(getIntoBox);

	Action* runBehindDefence = new RunBehindDefence(stadium->random, stadium->language);
	attackingActions.push_back(runBehindDefence);

	// PUSH BACK DEFENDING ACTIONS

	// NEAR BALL

	// FAR FROM BALL
	Action* takeDefendingPosition = new TakeDefendingPosition(stadium->random, stadium->language);
	defendingActions.push_back(takeDefendingPosition);

};

void Club::takeKickOffPositions(bool weStart)
{
	float stadium_width = stadium->playArea.width;
	float stadium_height = stadium->playArea.height;
	float goalEffect = (onTheRightGoal)?(-1.0):(1.0);
	sf::Vector2f ball_pos = stadium->centerSpot;

	SquadPosition* player;
	float target_x, target_y;

	if (weStart)
	{
		// Update currentDefensiveLine
		currentDefensiveLine = 0.12 * log(31.0*(ball_pos.x/stadium->playArea.width)+1.0) / ( log(2) * ((1.0/-0.9) * (defensiveLine-1.0) +1.0) );
		if(onTheRightGoal) currentDefensiveLine = 1 - currentDefensiveLine;
		currentDefensiveLine *= stadium->playArea.width;
	
		// Update currentLeftmost
		float minX = 2.0;
		for (int i=1; i<11; i++)
		{
			if (lineUp[i]->tactical_x<minX) minX = lineUp[i]->tactical_x;
		}
	
		float howFar_defLine = ((onTheRightGoal)?(currentDefensiveLine):(stadium->playArea.width-currentDefensiveLine));
		currentLeftmost = currentDefensiveLine - goalEffect * ( (minX * howFar_defLine) / (0.9-minX));

		// Update currentUppermost
		currentWidth = 0.7 + 0.3 * attackingWidth;
		currentUppermost = ball_pos.y * (1.0-currentWidth);
		if (onTheRightGoal) currentUppermost = stadium->playArea.height - currentUppermost;

		for (int i=0; i<9; i++)
		{
			player = lineUp[i];

			target_x = player->tactical_x * 0.7 + RandomBetween(-0.01,0.01);
			if (target_x >= 0.5) target_x=0.49; // if the player is on the opponent's half, take him back.
			if (onTheRightGoal) target_x = 1 - target_x;
			target_x *= stadium->playArea.width;

			float team_width = currentWidth * stadium_height;
			target_y = currentUppermost + team_width * player->tactical_y * goalEffect;

			lineUp[i]->setPosition(target_x, target_y);
			lineUp[i]->theta = (onTheRightGoal)?M_PI:0;
			lineUp[i]->lastMotion = 0;
		}

		// Last two player will start the game.
		lineUp[9]->setPosition(ball_pos.x,ball_pos.y-1);
		lineUp[9]->theta = (onTheRightGoal)?(3*M_PI/2):(M_PI/2);
		lineUp[9]->lastMotion = 0;
		lineUp[10]->setPosition(ball_pos.x,ball_pos.y+1);
		lineUp[10]->theta = (onTheRightGoal)?(M_PI/2):(3*M_PI/2);
		lineUp[10]->lastMotion = 0;

	}
	else
	{
		// Update currentDefensiveLine
		currentDefensiveLine = 0.8 * 0.12 * log(31.0*(ball_pos.x/stadium->playArea.width)+1.0) / ( log(2) * ((1.0/-0.9) * (defensiveLine-1.0) +1.0) );
		if(onTheRightGoal) currentDefensiveLine = 1 - currentDefensiveLine;
		currentDefensiveLine *= stadium->playArea.width;

		// Update currentLeftmost
		float minX = 2.0;
		for (int i=1; i<11; i++)
		{
			if (lineUp[i]->defending_x<minX) minX = lineUp[i]->defending_x;
		}
		float howFar_defLine = ((onTheRightGoal)?(currentDefensiveLine):(stadium->playArea.width-currentDefensiveLine));
		currentLeftmost = currentDefensiveLine - goalEffect * ( (minX * howFar_defLine) / (1.0-minX));

		// Update currentUppermost
		currentWidth = 0.7 + 0.3 * defendingWidth;
		currentUppermost = ball_pos.y * (1.0-currentWidth);
		if (onTheRightGoal) currentUppermost = stadium->playArea.height - currentUppermost;

		for (int i=0; i<11; i++)
		{
			player = lineUp[i];

			target_x = (player->defending_x) * 0.7 + RandomBetween(-0.01,0.01);
			if (target_x > 0.5) target_x=0.49; // if the player is on the opponent's half, take him back.
			if (onTheRightGoal)	target_x = 1 - target_x;
			target_x *= stadium->playArea.width;

			float team_width = currentWidth * stadium_height;
			target_y = currentUppermost + team_width * player->defending_y * goalEffect;

			if (distanceBetween(sf::Vector2f(target_x,target_y),stadium->centerSpot)<9.15)
			{ // if the player is in the center circle, take him out of there.
				float yDifference = sqrt ( pow(9.15,2) - pow(target_x - stadium->centerSpot.x,2) );
				if (target_y>stadium->centerSpot.y) target_y=stadium->centerSpot.y+yDifference;
				else target_y=stadium->centerSpot.y-yDifference;
			}
			
			lineUp[i]->setPosition(target_x, target_y);
			lineUp[i]->theta = (onTheRightGoal)?M_PI:0;
			lineUp[i]->lastMotion = 0;
		}
	}
};

void Club::takeGoalKickPositions(bool weTake)
{
	float stadium_width = stadium->playArea.width;
	float stadium_height = stadium->playArea.height;
	float goalEffect = (onTheRightGoal)?(-1.0):(1.0);
	float target_x, target_y;
	SquadPosition* player;
	sf::Vector2f ball_pos = stadium->ball->getPosition2();
	sf::Vector2f relative_ball_pos = ball_pos;
	if (onTheRightGoal) 
	{
		relative_ball_pos.x = stadium->playArea.width - relative_ball_pos.x;
		relative_ball_pos.y = stadium->playArea.height - relative_ball_pos.y;
	}

	// Update currentDefensiveLine
	currentDefensiveLine = 0.12 * log(31.0*(relative_ball_pos.x/stadium->playArea.width)+1.0) / ( log(2) * ((1.0/-0.9) * (defensiveLine-1.0) +1.0) );
	if (weTake) currentDefensiveLine *=3.0;
	if(onTheRightGoal) currentDefensiveLine = 1.0 - currentDefensiveLine;
	currentDefensiveLine *= stadium->playArea.width;

	if (weTake)
	{
		// Update currentLeftmost
		float minX = 2.0;
		for (int i=1; i<11; i++)
		{
			if (lineUp[i]->tactical_x<minX) minX = lineUp[i]->tactical_x;
		}
	
		float howFar_defLine = ((onTheRightGoal)?(currentDefensiveLine):(stadium->playArea.width-currentDefensiveLine));
		currentLeftmost = currentDefensiveLine - goalEffect * ( (minX * howFar_defLine) / (0.9-minX));

		// Update currentUppermost
		currentWidth = 0.5 + 0.4 * attackingWidth;
		currentUppermost = ball_pos.y * (1.0-currentWidth);
		currentWidth *= stadium_height;
		//if (onTheRightGoal) currentUppermost = stadium->playArea.height - currentUppermost;

		for (int i=1; i<11; i++)
		{
			player = lineUp[i];

			float howFar_leftmost = (onTheRightGoal)?(currentLeftmost):(stadium_width - currentLeftmost);
			target_x = currentLeftmost + howFar_leftmost * player->tactical_x * goalEffect;

			float y_pos = (onTheRightGoal)?(1.0-player->tactical_y):player->tactical_y;
			target_y = currentUppermost + currentWidth * y_pos;

			stadium->makeItInside(&target_x,&target_y);
			player->setPosition(target_x,target_y);
			player->theta = (onTheRightGoal)?M_PI:0;
			player->lastMotion = 0;
		}

		// Goalkeeper will start the game.
		lineUp[0]->setPosition(ball_pos.x-1,ball_pos.y);
		lineUp[0]->theta = (onTheRightGoal)?(3*M_PI/2):(M_PI/2);
		lineUp[0]->lastMotion = 0;
	}
	else
	{ // DEFENDING TEAM
		if (onTheRightGoal)	currentDefensiveLine = stadium->playArea.width - (0.8 * (stadium->playArea.width-currentDefensiveLine));
		else currentDefensiveLine *= 0.8;

		// Update currentLeftmost
		float minX = 2.0;
		for (int i=1; i<11; i++)
		{
			if (lineUp[i]->defending_x<minX) minX = lineUp[i]->defending_x;
		}
		float howFar_defLine = ((onTheRightGoal)?(currentDefensiveLine):(stadium->playArea.width-currentDefensiveLine));
		currentLeftmost = currentDefensiveLine - goalEffect * ( (minX * howFar_defLine) / (1.0-minX));

		// Update currentUppermost
		currentWidth = 0.5 + 0.4 * defendingWidth;
		currentUppermost = ball_pos.y * (1.0-currentWidth);
		currentWidth *= stadium_height;

		for (int i=0; i<11; i++)
		{
			player = lineUp[i];

			float howFar_leftmost = (onTheRightGoal)?(currentLeftmost-0.2*stadium_width):(0.8*stadium_width - currentLeftmost);
			target_x = currentLeftmost + howFar_leftmost * player->defending_x * goalEffect;
			
			float y_pos = (onTheRightGoal)?(1.0-player->defending_y):player->defending_y;
			target_y = currentUppermost + currentWidth * y_pos; //* goalEffect;

			stadium->makeItInside(&target_x,&target_y);
			player->setPosition(target_x,target_y);
			player->setPosition(target_x, target_y);
			player->theta = (onTheRightGoal)?M_PI:0;
			player->lastMotion = 0;
		}
	}
}

void Club::takeCornerKickPositions(bool weTake)
{
	float stadium_width = stadium->playArea.width;
	float stadium_height = stadium->playArea.height;
	float goalEffect = (onTheRightGoal)?(-1.0):(1.0);
	float target_x, target_y;
	SquadPosition* player;
	sf::Vector2f ball_pos = stadium->ball->getPosition2();
	sf::Vector2f relative_ball_pos = ball_pos;
	if (onTheRightGoal) 
	{
		relative_ball_pos.x = stadium->playArea.width - relative_ball_pos.x;
		relative_ball_pos.y = stadium->playArea.height - relative_ball_pos.y;
	}

	// Update currentDefensiveLine
	currentDefensiveLine = 0.12 * log(31.0*(relative_ball_pos.x/stadium->playArea.width)+1.0) / ( log(2) * ((1.0/-0.9) * (defensiveLine-1.0) +1.0) );
	if(onTheRightGoal) currentDefensiveLine = 1.0 - currentDefensiveLine;
	currentDefensiveLine *= stadium->playArea.width;
	
	if (weTake)
	{
		// Corner kick is in the which side for the club?
		bool is_pointDown = (stadium->restartingPoint.z > (stadium->playArea.height/2.0)) ? true:false;
		bool is_right = is_pointDown ^ onTheRightGoal;
		int taker_index = is_right?taker_rightCornerKick:taker_leftCornerKick;

		// Update currentLeftmost
		float minX = 2.0;
		for (int i=1; i<11; i++)
		{
			if (lineUp[i]->tactical_x<minX) minX = lineUp[i]->tactical_x;
		}
	
		float howFar_defLine = ((onTheRightGoal)?(currentDefensiveLine):(stadium->playArea.width-currentDefensiveLine));
		currentLeftmost = currentDefensiveLine - goalEffect * ( (minX * howFar_defLine) / (0.9-minX));

		// Update currentUppermost
		currentWidth = 0.5 + 0.4 * attackingWidth;
		currentUppermost = ball_pos.y * (1.0-currentWidth);
		currentWidth *= stadium_height;

		for (int i=0; i<11; i++)
		{
			player = lineUp[i];

			if (i!=taker_index)
			{
				float howFar_leftmost = (onTheRightGoal)?(currentLeftmost):(stadium_width - currentLeftmost);
				target_x = currentLeftmost + howFar_leftmost * player->tactical_x * goalEffect;
	
				float y_pos = (onTheRightGoal)?(1.0-player->tactical_y):player->tactical_y;
				target_y = currentUppermost + currentWidth * y_pos;

				stadium->makeItInside(&target_x,&target_y);
				player->setPosition(target_x,target_y);
				player->theta = (onTheRightGoal)?M_PI:0;
				player->lastMotion = 0;
			}
		}
		float taker_x = stadium->restartingPoint.x;
		float taker_y = stadium->restartingPoint.z;

		if (taker_x<3)
			taker_x -= 0.1;
		else if (taker_x>3)
			taker_x += 0.1;

		if (taker_y<3)
			taker_y -= 0.5;
		else if (taker_y>3)
			taker_y += 0.5;

		lineUp[taker_index]->setPosition(taker_x,taker_y);
		player->theta = (onTheRightGoal)?0:M_PI;
		player->lastMotion = 0;
	}
	else
	{ // DEFENDING TEAM
		if (onTheRightGoal)	currentDefensiveLine = stadium->playArea.width - (0.1 * (stadium->playArea.width-currentDefensiveLine));
		else currentDefensiveLine *= 0.1;

		// Update currentLeftmost
		float minX = 2.0;
		for (int i=1; i<11; i++)
		{
			if (lineUp[i]->defending_x<minX) minX = lineUp[i]->defending_x;
		}
		float howFar_defLine = ((onTheRightGoal)?(currentDefensiveLine):(stadium->playArea.width-currentDefensiveLine));
		currentLeftmost = currentDefensiveLine - goalEffect * ( (minX * howFar_defLine) / (1.0-minX));

		// Update currentUppermost
		currentWidth = 0.5 + 0.4 * defendingWidth;
		currentUppermost = ball_pos.y * (1.0-currentWidth);
		currentWidth *= stadium_height;

		for (int i=0; i<11; i++)
		{
			player = lineUp[i];

			//float howFar_leftmost = (onTheRightGoal)?(currentLeftmost):(stadium_width - currentLeftmost);
			float howFar_leftmost = (onTheRightGoal)?(currentLeftmost-0.2*stadium_width):(0.8*stadium_width - currentLeftmost);
			target_x = currentLeftmost + howFar_leftmost * player->defending_x * goalEffect;

			float y_pos = (onTheRightGoal)?(1.0-player->defending_y):player->defending_y;
			target_y = currentUppermost + currentWidth * y_pos;

			stadium->makeItInside(&target_x,&target_y);
			player->setPosition(target_x,target_y);
		}
	}
};

void Club::takeFreeKickPositions(bool weTake)
{

};

void Club::takeThrowInPositions(bool weTake)
{
	float stadium_width = stadium->playArea.width;
	float stadium_height = stadium->playArea.height;
	float goalEffect = (onTheRightGoal)?(-1.0):(1.0);
	float target_x, target_y;
	SquadPosition* player;
	sf::Vector2f ball_pos = stadium->ball->getPosition2();
	sf::Vector2f relative_ball_pos = ball_pos;
	if (onTheRightGoal) 
	{
		relative_ball_pos.x = stadium->playArea.width - relative_ball_pos.x;
		relative_ball_pos.y = stadium->playArea.height - relative_ball_pos.y;
	}

	// Update currentDefensiveLine
	currentDefensiveLine = 0.12 * log(31.0*(relative_ball_pos.x/stadium->playArea.width)+1.0) / ( log(2) * ((1.0/-0.9) * (defensiveLine-1.0) +1.0) );
	if(onTheRightGoal) currentDefensiveLine = 1.0 - currentDefensiveLine;
	currentDefensiveLine *= stadium->playArea.width;
	
	if (weTake)
	{
		// Player on which side will take the throw in?
		bool is_pointDown = (stadium->restartingPoint.z > (stadium->playArea.height/2.0)) ? true:false;
		bool is_right = is_pointDown ^ onTheRightGoal;
		AligningPosition align_pos = is_right?Aligning_R:Aligning_L;
		int taker=-1;

		// Update currentLeftmost
		float minX = 2.0;
		for (int i=1; i<11; i++)
		{
			if (lineUp[i]->tactical_x<minX) minX = lineUp[i]->tactical_x;
		}
		float howFar_defLine = ((onTheRightGoal)?(currentDefensiveLine):(stadium->playArea.width-currentDefensiveLine));
		currentLeftmost = currentDefensiveLine - goalEffect * ( (minX * howFar_defLine) / (0.9-minX));

		// Update currentUppermost
		currentWidth = 0.5 + 0.4 * attackingWidth;
		currentUppermost = ball_pos.y * (1.0-currentWidth);
		currentWidth *= stadium_height;

		for (int i=0; i<11; i++)
		{
			player = lineUp[i];

			if ((taker<0) && (player->aligningPosition==align_pos))
				taker = i;
			else
			{
				float howFar_leftmost = (onTheRightGoal)?(currentLeftmost):(stadium_width - currentLeftmost);
				target_x = currentLeftmost + howFar_leftmost * player->tactical_x * goalEffect;

				float y_pos = (onTheRightGoal)?(1.0-player->tactical_y):player->tactical_y;
				target_y = currentUppermost + currentWidth * y_pos;

				stadium->makeItInside(&target_x,&target_y);
				player->setPosition(target_x,target_y);
				player->theta = (onTheRightGoal)?M_PI:0;
				player->lastMotion = 0;
			}
		}

		if (taker<1)
		{ // No player is on that side to take throw in.
			taker = 0;
			if (is_right)
			{
				for (int j=1; j<11; j++)
				{
					if (lineUp[j]->tactical_y > lineUp[taker]->tactical_y)
						taker = j;
				}
			}
			else
			{
				for (int j=1; j<11; j++)
				{
					if (lineUp[j]->tactical_y < lineUp[taker]->tactical_y)
						taker = j;
				}
			}
		}
		lineUp[taker]->setPosition(stadium->restartingPoint.x,stadium->restartingPoint.z);
	}

	else
	{ // DEFENDING TEAM
		//if (onTheRightGoal)	currentDefensiveLine = stadium->playArea.width - (0.8 * (stadium->playArea.width-currentDefensiveLine));
		//else currentDefensiveLine *= 0.8;

		// Update currentLeftmost
		float minX = 2.0;
		for (int i=1; i<11; i++)
		{
			if (lineUp[i]->defending_x<minX) minX = lineUp[i]->defending_x;
		}
		float howFar_defLine = (onTheRightGoal)?(currentDefensiveLine):(stadium->playArea.width-currentDefensiveLine);
		currentLeftmost = currentDefensiveLine - goalEffect * ( (minX * howFar_defLine) / (1.0-minX));

		// Update currentUppermost
		currentWidth = 0.5 + 0.4 * defendingWidth;
		currentUppermost = ball_pos.y * (1.0-currentWidth);
		currentWidth *= stadium_height;

		for (int i=0; i<11; i++)
		{
			player = lineUp[i];

			float howFar_leftmost = (onTheRightGoal)?(currentLeftmost-0.2*stadium_width):(0.8*stadium_width - currentLeftmost);
			target_x = currentLeftmost + howFar_leftmost * player->defending_x * goalEffect;
			
			float y_pos = (onTheRightGoal)?(1.0-player->defending_y):player->defending_y;
			target_y = currentUppermost + currentWidth * y_pos; //* goalEffect;

			stadium->makeItInside(&target_x,&target_y);
			player->setPosition(target_x,target_y);
		}
	}
};

void Club::updateAttackingPlay()
{
	if (!stadium->gameIsOn)	return;

	float stadium_width = stadium->playArea.width;
	float stadium_height = stadium->playArea.height;
	float goalEffect = (onTheRightGoal)?(-1.0):(1.0);
	sf::Vector2f ball_pos = stadium->ball->getPosition2();
	sf::Vector2f relative_ball_pos = ball_pos;
	if (onTheRightGoal) 
	{
		relative_ball_pos.x = stadium->playArea.width - relative_ball_pos.x;
		relative_ball_pos.y = stadium->playArea.height - relative_ball_pos.y;
	}

	// Update currentDefensiveLine
	currentDefensiveLine = 0.12 * log(31.0*(relative_ball_pos.x/stadium->playArea.width)+1.0) /
		( log(2) * ((1.0/-0.9) * (defensiveLine-1.0) +1.0) );
	if(onTheRightGoal) currentDefensiveLine = 1.0 - currentDefensiveLine;
	currentDefensiveLine *= stadium->playArea.width;
	
	// Update currentLeftmost
	float minX = 2.0;
	for (int i=1; i<11; i++)
	{
		if (lineUp[i]->tactical_x<minX) minX = lineUp[i]->tactical_x;
	}
	
	float howFar_defLine = onTheRightGoal?currentDefensiveLine:(stadium->playArea.width-currentDefensiveLine);
	currentLeftmost = currentDefensiveLine - goalEffect * ( (minX * howFar_defLine) / (0.9-minX));
	currentWidth = 0.5 + 0.4 * attackingWidth;
	currentUppermost = ball_pos.y * (1.0-currentWidth);
	currentWidth *= stadium_height;

	findClosestPlayer();

	// If someone kicked the ball in the earlier frame, increase the time passed since the ball is kicked.
	if (sinceBallIsPassed>0) 
		sinceBallIsPassed += 1.0/60.0;

	SquadPosition* player;
	for (int j=0; j<11; j++)
	{
		player = lineUp[j];
		ActionMap possibleActions;
		for (int i=0; i<attackingActions.size(); i++)
		{
			float weight = attackingActions[i]->checkPreconditions(player,stadium);
			if (weight>0)
				possibleActions.insert( ActionPair(-1.0*weight,attackingActions[i]) );
		}
		if (possibleActions.size()>0)
			possibleActions.begin()->second->execute(player,stadium);
	}

};

void Club::updateDefendingPlay()
{
	if (!stadium->gameIsOn)
		return;

	findClosestPlayer();

	float stadium_width = stadium->playArea.width;
	float stadium_height = stadium->playArea.height;
	float goalEffect = (onTheRightGoal)?(-1.0):(1.0);
	sf::Vector2f ball_pos = stadium->ball->getPosition2();
	sf::Vector2f relative_ball_pos = ball_pos;
	if (onTheRightGoal) 
	{
		relative_ball_pos.x = stadium->playArea.width - relative_ball_pos.x;
		relative_ball_pos.y = stadium->playArea.height - relative_ball_pos.y;
	}

	// Update currentDefensiveLine
	currentDefensiveLine = 0.08 * log(31.0*(relative_ball_pos.x/stadium->playArea.width)+1.0) / ( log(2) * ((1.0/-0.9) * (defensiveLine-1.0) +1.0) );
	if(onTheRightGoal) currentDefensiveLine = 1 - currentDefensiveLine;
	currentDefensiveLine *= stadium->playArea.width;

	// Update currentLeftmost
	float minX = 2.0;
	for (int i=1; i<11; i++)
	{
		if (lineUp[i]->defending_x<minX) minX = lineUp[i]->defending_x;
	}
	float howFar_defLine = ((onTheRightGoal)?(currentDefensiveLine):(stadium->playArea.width-currentDefensiveLine));
	currentLeftmost = currentDefensiveLine - goalEffect * ( (minX * howFar_defLine) / (1.0-minX));

	// Update currentUppermost
	currentWidth = 0.5 + 0.4 * defendingWidth;
	currentUppermost = ball_pos.y * (1.0-currentWidth);
	currentWidth *= stadium_height;

	SquadPosition* player;
	for (int j=0; j<11; j++)
	{
		player = lineUp[j];
		ActionMap possibleActions;
		for (int i=0; i<defendingActions.size(); i++)
		{
			float weight = defendingActions[i]->checkPreconditions(player,stadium);
			if (weight>0)
				possibleActions.insert( ActionPair(-weight,defendingActions[i]) );
		}
		if (possibleActions.size()>0)
			possibleActions.begin()->second->execute(player,stadium);
	}
};

void Club::findClosestPlayer()
{
	float min_distance = 1000;
	float distance_to_ball;

	for (int i=0; i<11; i++)
	{
		distance_to_ball = distanceBetween( lineUp[i]->getPosition(),stadium->ball->getPosition2() );
		if ( distance_to_ball<min_distance)
		{
			min_distance = distance_to_ball;
			closestPlayer = lineUp[i];
		}
	}
	//wcout << "closest: " << closestPlayer->get_footballer()->shortName_shown << endl;
};

void Club::updateTeamValues()
{
	//cout << "INITIAL DL: " << defensiveLine << endl;
	//float greatestDefLine = 0.6 / ( log(2) * ((1.0/-0.9) * (defensiveLine-1.0) +1.0) );
	//cout << "INITIAL GDL: " << greatestDefLine << endl;
//	defaultTeamLength = stadium->playArea.width * (1.0 - greatestDefLine);
	//cout << "INITIAL TL: " << defaultTeamLength << endl;
}

bool Club::isSomeoneThere_rect(float left, float right, float top, float bottom)
{
	for (int i=0; i<11; i++)
	{
		if (lineUp[i]->x>=left && lineUp[i]->x<=right && lineUp[i]->y>=top && lineUp[i]->y<=bottom)
			return true;
	}
	return false;
};

bool Club::isSomeoneThere_points(sf::Vector2f point1, sf::Vector2f point2, float margin)
{
	float slope = (point2.y-point1.y)/(point2.x-point1.x);
	for (int i=0; i<11; i++)
	{
		sf::Vector2f player_pos = lineUp[i]->getPosition();
		if (isPointBetween(player_pos,point1,point2,margin))
			return true;
		//if ( abs (point1.x * slope + extra_term - point1.y) < margin)
			//return true;
	}
	return false;
};