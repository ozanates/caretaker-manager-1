#include "stadium.h"
#include "../Club/club.h"
#include <iostream>

Stadium::Stadium(Random *r, Language *lang):random(r),language(lang)
{
	goalWidth = 7.32;
	goalHeight = 2.44;
	// INITIALIZE AREAS AND POINTS IN THE STADIUM
	playArea = sf::FloatRect(0, 0, 105, 68);
	centerSpot = sf::Vector2f(playArea.width/2.0, playArea.height/2.0);
	penaltyArea0 = sf::FloatRect(0, 13.85, 16.5, 40.3);
	penaltySpot0 = sf::Vector2f(12.34, centerSpot.y);
	penaltyArea1 = sf::FloatRect(playArea.width-16.5, 13.85, 16.5, 40.3);
	penaltySpot1 = sf::Vector2f(playArea.width-12.34, centerSpot.y);

	throwInArea0 =  sf::FloatRect(playArea.left, playArea.top-0.25-2.00, playArea.width, 2.00);
	throwInArea1 =  sf::FloatRect(playArea.left, playArea.top+playArea.height+0.25, playArea.width, 2.00);
	goalKickArea0 =  sf::FloatRect(playArea.left-0.25-2.00, playArea.top, 2.00, playArea.height);
	goalKickArea1 =  sf::FloatRect(playArea.left+playArea.width+0.25, playArea.top, 2.00, playArea.height);
	goalArea0 = sf::FloatRect(-0.5, centerSpot.y-(goalWidth/2.0), 0.25, goalWidth);
	goalArea1 = sf::FloatRect(playArea.left+playArea.width+0.25, centerSpot.y-(goalWidth/2.0), 0.5, goalWidth);
	goal0 = sf::Vector2f(0,playArea.height/2.0);
	goal1 = sf::Vector2f(playArea.width,playArea.height/2.0);

	goalKickSpot00 = sf::Vector2f(5.0, 25.0);
	goalKickSpot01 = sf::Vector2f(5.0, 42.0);;
	goalKickSpot10 = sf::Vector2f(playArea.width-5.0, 25.0);
	goalKickSpot11 = sf::Vector2f(playArea.width-5.0, 42.0);

	commentator = L"";
	
	init();
}

Stadium::~Stadium()
{
	deallocate();
}

void Stadium::init()
{
	initClubs();

	InitializeBulletWorld();
	
	ball = new Ball (centerSpot.x, 0, centerSpot.y); // Initializing the position of the ball
	dynamicsWorld->addRigidBody(ball->rigidBody);

	// INITIALIZE VARIABLES CHANGE OVER THE MATCH
	matchState = kickoff;
	elapsedSeconds = 0;
	score0 = 0; score1 = 0;

	refDecision=DECISION_NO;
	gameIsOn=true;
	countdown_refDecision = -1;
}

void Stadium::deallocate()
{
	delete club0; 
	delete club1;
	delete ball;

	delete groundRigidBody;
	delete groundMotionState;
	delete ground;
	delete dynamicsWorld;
	delete solver;
	delete dispatcher;
	delete collisionConfiguration;
	delete broadphase;
}

void Stadium::reset()
{
	deallocate();
	init();
}

void Stadium::initClubs()
{
	club0 = new Club(this,ID_MANUNITED16,false); // Leicester will be the first club.
	club0_color0 = &club0->home_color0;
	club0_color1 = &club0->home_color1;
	club0->isAway = false;
	club1 = new Club(this,ID_LEICESTER16,true); // Man United will be the second club.
	club1_color0 = &club0->away_color0;
	club1_color1 = &club0->away_color1;
	club1->isAway = true;

	//whoHasTheBall = 0; // DEBUG: To determine the starting team.
	whoHasTheBall = rand()%2;

	// TODO: compare and choose the colors of kits.
}

void Stadium::InitializeBulletWorld()
{
	// Necessary initializations for the world
	broadphase = new btDbvtBroadphase(); // bounding boxes algorithm for collusions
	collisionConfiguration = new btDefaultCollisionConfiguration(); // collusion configurations
    dispatcher = new btCollisionDispatcher(collisionConfiguration);
	solver = new btSequentialImpulseConstraintSolver; // solver that takes into account gravity, game logic supplied forces, collisions, and hinge constraints

	// Creating the world
	dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver, collisionConfiguration); //DEFINED IN CLASS
	dynamicsWorld->setGravity(btVector3(0, -9.8, 0)); // Setting gravity

	// Collision shape for Ground = Static plan shape 
	ground = new btStaticPlaneShape(btVector3(0, 1, 0), 1); //DEFINED IN CLASS

	// Rigid body instance for Ground // USE FOR RENDERING
	groundMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, -1, 0)));
	btRigidBody::btRigidBodyConstructionInfo groundRigidBodyCI(0, groundMotionState, ground, btVector3(0, 0, 0));
    groundRigidBody = new btRigidBody(groundRigidBodyCI);
	
	groundRigidBody->setRestitution(0.79); // to bounce
	groundRigidBody->setHitFraction(1.5); // to slow down when it hits
	groundRigidBody->setRollingFriction(12.0); // to slow down when it is rolling
	
	dynamicsWorld->addRigidBody(groundRigidBody);

	// 4 goal posts
	btCollisionShape* goalPosts[6];
	btRigidBody* goalPosts_rigidBody[6];
	btDefaultMotionState* goalPosts_motionState[6];
	float post_radius = 0.11;

	goalPostPositions[0] = btVector3( 0, 0, (playArea.height/2.0)+(goalWidth/2.0)+post_radius); // left goal post of goal 0
	goalPostPositions[1] = btVector3( 0, 0, (playArea.height/2.0)-(goalWidth/2.0)-post_radius); // right goal post of goal 0
	goalPostPositions[2] = btVector3(playArea.width, 0, (playArea.height/2.0)-(goalWidth/2.0)-post_radius); // left goal post of goal 1
	goalPostPositions[3] = btVector3(playArea.width, 0, (playArea.height/2.0)+(goalWidth/2.0)+post_radius); // right goal post of goal 1
	goalPostPositions[4] = goalPostPositions[0] + btVector3(0,goalHeight,0); // up goal post of goal 0
	goalPostPositions[5] = goalPostPositions[2] + btVector3(0,goalHeight,0); // up goal post of goal 1


	for (int i=0; i<6; i++)
	{
		if (i<4)
			goalPosts[i] = new btCylinderShape( btVector3(post_radius,goalHeight/2,post_radius) );
		else
			goalPosts[i] = new btCylinderShape( btVector3(post_radius,(goalWidth/2)+post_radius,post_radius) );

		goalPosts_motionState[i] = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), goalPostPositions[i]));
		btRigidBody::btRigidBodyConstructionInfo rigidBodyCI(0, goalPosts_motionState[i], goalPosts[i], btVector3(0, 0, 0));
		goalPosts_rigidBody[i] = new btRigidBody(rigidBodyCI);

		goalPosts_rigidBody[i]->setRestitution(0.79); // to bounce
		goalPosts_rigidBody[i]->setHitFraction(1.5); // to slow down when it hits
		goalPosts_rigidBody[i]->setRollingFriction(12.0); // to slow down when it is rolling

		dynamicsWorld->addRigidBody(goalPosts_rigidBody[i]);
	}
}

void Stadium::StepBulletWorld()
{
	if (countdown_refDecision>0) // don't change the state yet. visual delay is needed.
		countdown_refDecision--;
	else
	{
		int goal_check = IsGoal();
		if (goal_check>=0)
		{
			if (goal_check) score1++;
			else score0++;
			refDecision = DECISION_GOAL;
			countdown_refDecision = 180;
			commentator += language->COMMENTATOR_00006;
			club0->sinceBallIsPassed=0; club1->sinceBallIsPassed=0;
			gameIsOn = false;
		}
		else if (IsThrowIn())
		{
			countdown_refDecision = 180;
			refDecision = DECISION_THROWIN;
			commentator += L" " + language->COMMENTATOR_00001;
			club0->sinceBallIsPassed=0; club1->sinceBallIsPassed=0;
			gameIsOn = false;
		}
		else if (IsGoalKick())
		{
			if (isCornerKick)
			{
				// IT'S A CORNER KICK
				countdown_refDecision = 180;
				refDecision = DECISION_CORNERKICK;
				commentator += L" " + language->COMMENTATOR_00004;
				club0->sinceBallIsPassed=0; club1->sinceBallIsPassed=0;
				gameIsOn = false;
			}
			else
			{
				// IT'S A GOAL KICK
				countdown_refDecision = 180;
				refDecision = DECISION_GOALKICK;
				commentator += L" " + language->COMMENTATOR_00005;
				club0->sinceBallIsPassed=0; club1->sinceBallIsPassed=0;
				gameIsOn = false;
			}
		}
	}

	if (countdown_refDecision == 0)
	{
		switch(refDecision){
		case DECISION_NO:
			cout << "Error: Countdown is over but there is no ref decision." << endl;
			break;
		case DECISION_GOAL:
			matchState=kickoff;
			break;
		case DECISION_CORNERKICK:
			matchState=cornerKick;
			break;
		case DECISION_GOALKICK:
			matchState=goalKick;
			break;
		case DECISION_THROWIN:
			matchState=throwIn;
			break;
		}
		countdown_refDecision = -1;
	}

	if (matchState==openPlay)
	{
		if (whoHasTheBall)
		{
			club1->updateAttackingPlay();
			club0->updateDefendingPlay();
		}
		else
		{
			club0->updateAttackingPlay();
			club1->updateDefendingPlay();
		}
	}
	else if (matchState==kickoff)
	{
		if (elapsedSeconds>60) 
		{
			elapsedSeconds += random->get_int(50,80);
			commentator = language->COMMENTATOR_00003;
		}
		else
			commentator = language->COMMENTATOR_00002;

		ResetBall(sf::Vector3f(centerSpot.x,0.0,centerSpot.y));
		club0->takeKickOffPositions(!whoHasTheBall);
		club1->takeKickOffPositions(whoHasTheBall);
		matchState=openPlay;
		gameIsOn = true;
	}
	else if (matchState==goalKick)
	{
		elapsedSeconds += random->get_int(7,20);
		ResetBall(restartingPoint);
		club0->takeGoalKickPositions(!whoHasTheBall);
		club1->takeGoalKickPositions(whoHasTheBall);
		matchState=openPlay;
		gameIsOn = true;
	}
	else if (matchState==cornerKick)
	{
		elapsedSeconds += random->get_int(10,20);
		ResetBall(restartingPoint);
		club0->takeCornerKickPositions(!whoHasTheBall);
		club1->takeCornerKickPositions(whoHasTheBall);
		matchState=openPlay;
		gameIsOn = true;
		//matchState=cornerKickPlay;
	}
	else if (matchState==throwIn)
	{
		elapsedSeconds += random->get_int(2,5);
		ResetBall(restartingPoint);
		club0->takeThrowInPositions(!whoHasTheBall);
		club1->takeThrowInPositions(whoHasTheBall);
		matchState=openPlay;
		gameIsOn = true;
	}
	else if (matchState==freeKick)
	{
		elapsedSeconds += random->get_int(5,12);
		ResetBall(restartingPoint);
		club0->takeFreeKickPositions(!whoHasTheBall);
		club1->takeFreeKickPositions(whoHasTheBall);
		matchState=openPlay;
		gameIsOn = true;
		//matchState=freeKickPlay;
	}
	else if (matchState==cornerKickPlay)
	{

	}
	else if (matchState==freeKickPlay)
	{

	}
	else
	{
		cout << "MATCH ENGINE ERROR: Undefined match state." << endl;
	}

	dynamicsWorld->stepSimulation(1/60.0,10);
	elapsedSeconds += 1/60.0;

	restrictBallPosition();
}

void Stadium::ResetBall(sf::Vector3f new_position)
{
	dynamicsWorld->removeRigidBody(ball->rigidBody);
	delete ball;
	ball = new Ball (new_position); // Initializing the position of the ball
	dynamicsWorld->addRigidBody(ball->rigidBody);
};

void Stadium::restrictBallPosition()
{
	sf::Vector2f ball_pos = ball->getPosition2();
	bool change = false;

	if (ball_pos.x < -5.0)
	{
		change = true;
		ball_pos.x = -4.0;
	}
	else if (ball_pos.x > 110.0)
	{
		change = true;
		ball_pos.x = 109.0;
	}

	if (ball_pos.y < -5.0)
	{
		change = true;
		ball_pos.y = -4.0;
	}
	else if (ball_pos.y > 73.0)
	{
		change = true;
		ball_pos.y = 72.0;
	}

	if (change)
		ResetBall( sf::Vector3f(ball_pos.x,0,ball_pos.y));

};

bool Stadium::checkBallIsInArea(float left, float right, float top, float bottom)
{
	sf::Vector2f ball_pos = ball->getPosition2();
	if (ball_pos.x >= left && ball_pos.x <= right && ball_pos.y >= top && ball_pos.y <= bottom)
		return true;

	return false;
};

bool Stadium::IsBallInPlayArea()
{
	return playArea.contains( ball->getPosition2());
}

int Stadium::IsBallInPenaltyArea()
{
	if ( penaltyArea0.contains( ball->getPosition2() ) )
		return 0;
	else if ( penaltyArea1.contains( ball->getPosition2() ) )
		return 1;
	else
		return -1;
}

bool Stadium::IsThrowIn()
{
	sf::Vector2f ball_position = ball->getPosition2();
	if ( throwInArea0.contains(ball_position) )
	{
		restartingPoint = sf::Vector3f(ball_position.x,1.9,0);
		whoHasTheBall = !lastTeamTouchedTheBall;
		return true;
	}
	else if ( throwInArea1.contains(ball_position) )
	{
		restartingPoint = sf::Vector3f(ball_position.x,1.9,playArea.height);
		whoHasTheBall = !lastTeamTouchedTheBall;
		return true;
	}
	else
		return false;
}

bool Stadium::IsGoalKick()
{
	bool rightHandSideArea;
	sf::Vector2f ball_position = ball->getPosition2();

	// LEFT OR RIGHT?
	if ( goalKickArea0.contains(ball_position) )
		rightHandSideArea = false;
	else if ( goalKickArea1.contains(ball_position) )
		rightHandSideArea = true;
	else
		return false;

	// WHO TOUCHED THE BALL LAST?
	Club* lastClubTouched = (lastTeamTouchedTheBall)?club1:club0;
	if (lastClubTouched->onTheRightGoal == rightHandSideArea)
		isCornerKick = true;
	else
		isCornerKick = false;

	whoHasTheBall = !lastTeamTouchedTheBall;
	countdown_refDecision = 300;
	// RETURN STARTING POINT
	if (isCornerKick)
	{
		refDecision = DECISION_CORNERKICK;

		if (!rightHandSideArea)
		{
			if (ball_position.y > playArea.height / 2.0)
				restartingPoint = sf::Vector3f(0.707,0,playArea.height-0.707);
			else
				restartingPoint = sf::Vector3f(0.707,0,0.707);
		}
		else
		{ // 	restartingPoint = sf::Vector3f(playArea.width-0.707,0,playArea.height-0.707);
			if (ball_position.y > playArea.height / 2.0)
				restartingPoint = sf::Vector3f(playArea.width-0.707,0,playArea.height-0.707);
			else
				restartingPoint = sf::Vector3f(playArea.width-0.707,0,0.707);
		}
	}
	else
	{
		refDecision = DECISION_GOALKICK;

		if (!rightHandSideArea)
		{
			if (ball_position.y > playArea.height / 2.0)
				restartingPoint = vector2f_to_3f(goalKickSpot01);
			else
				restartingPoint = vector2f_to_3f(goalKickSpot00);
		}
		else
		{
			if (ball_position.y > playArea.height / 2.0)
				restartingPoint = vector2f_to_3f(goalKickSpot11);
			else
				restartingPoint = vector2f_to_3f(goalKickSpot10);
		}
	}
	return true;
}

int Stadium::IsGoal()
{
	int homeGoal = club0->onTheRightGoal;

	sf::Vector2f ball_position = ball->getPosition2();
	if (ball->getPosition3().getY()>goalHeight)
		return -1;

	if( goalArea0.contains(ball_position) )
		return !homeGoal;
	else if( goalArea1.contains(ball_position) )
		return homeGoal;

	return -1;
}

void Stadium::makeItInside(float* x, float* y)
{
	if (*x<0) *x=0;
	else if (*x > playArea.width) *x = playArea.width;
	if (*y<0) *y=0;
	else if (*y > playArea.height) *y = playArea.height;

	return;
};