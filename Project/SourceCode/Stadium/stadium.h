#ifndef STADIUM

#define STADIUM

#include "ball.h"
#include "../Headers/enum.h"
#include "../random.h"
#include "../Language/language.h"

class Club;

enum RefDecision
{
	DECISION_NO,
	DECISION_GOAL,
	DECISION_CORNERKICK,
	DECISION_GOALKICK,
	DECISION_THROWIN,
};

class Stadium 
{
	// BULLET VARIABLES THAT WILL BE USED JUST FOR DEALLOCATION
	btBroadphaseInterface* broadphase;
	btDefaultCollisionConfiguration* collisionConfiguration;
	btCollisionDispatcher* dispatcher;
	btSequentialImpulseConstraintSolver* solver;
	btDefaultMotionState* groundMotionState, *goalPost00_MotionState, *goalPost01_MotionState, *goalPost10_MotionState, *goalPost11_MotionState;
	btRigidBody *groundRigidBody, *goalPost00_RigidBody, *goalPost01_RigidBody, *goalPost10RigidBody, *goalPost11_RigidBody;

	// BULLET VARIABLES AND FUNCTIONS
	btDiscreteDynamicsWorld* dynamicsWorld;
	btCollisionShape *ground, *goalPost00, *goalPost01, *goalPost10, *goalPost11;
	void InitializeBulletWorld();

	void initClubs(); // Choosing clubs FOR DEBUGGING
	void init();
	void deallocate();
	void reset();
public:
	Stadium(Random *r, Language *lang);
	~Stadium();
	btVector3 goalPostPositions[6]; // [0]=left0, [1]=right0, [2]=left1, [3]=right1, [4]=top0, [5]=top1.
	
	// OWNED CLASSES
	Random* random;
	Language* language;
	Ball* ball;
	Club* club0;
	sf::Color* club0_color0;
	sf::Color* club0_color1;
	Club* club1;
	sf::Color* club1_color0;
	sf::Color* club1_color1;

	// AREAS IN THE STADIUM
	sf::FloatRect playArea;
	sf::Vector2f centerSpot;
	sf::FloatRect penaltyArea0;
	sf::Vector2f penaltySpot0;
	sf::FloatRect penaltyArea1;
	sf::Vector2f penaltySpot1;
	sf::Vector2f goal0;
	sf::Vector2f goal1;
	float goalHeight, goalWidth;

	sf::FloatRect throwInArea0;
	sf::FloatRect throwInArea1;
	sf::FloatRect goalKickArea0;
	sf::FloatRect goalKickArea1;
	sf::FloatRect goalArea0;
	sf::FloatRect goalArea1;

	sf::Vector2f goalKickSpot00;
	sf::Vector2f goalKickSpot01;
	sf::Vector2f goalKickSpot10;
	sf::Vector2f goalKickSpot11;

	// GENERAL FUNCTIONS
	void StepBulletWorld();
	void ResetBall(sf::Vector3f);

	// VARIABLES CHANGE OVER THE MATCH
	std::wstring commentator;
	bool whoHasTheBall; // false=0=homeTeam  true=1=awayTeam
	bool gameIsOn;
	bool lastTeamTouchedTheBall; // false=0=homeTeam  true=1=awayTeam
	int score0, score1; // Scores
	float elapsedSeconds; // Time
	e_matchState matchState; // State of the match

	void restrictBallPosition();

	// MATCH ENGINE FUNCTIONS
	bool checkBallIsInArea(float left, float right, float top, float bottom);
	bool IsBallInPlayArea(); // Returns if the ball is in play area.
	int IsBallInPenaltyArea(); // Returns 0 or 1 (club) if the ball is in penalty area. Returns -1 otherwise.
	void makeItInside(float* x, float* y);

	bool IsThrowIn(); // Returns restarting point if the ball is out for throw in. Returns -1s otherwise.
	bool IsGoalKick(); // Returns restarting point if the ball is out for throw in. Returns -1s otherwise.
	int IsGoal(); // Returns -1 if it is not a goal. Returns 0 for a home goal, 1 for an away goal.
	bool isCornerKick;
	sf::Vector3f restartingPoint;
	int countdown_refDecision; // countdown for delaying the change of state.
	RefDecision refDecision;
};

#endif