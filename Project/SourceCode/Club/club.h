#ifndef CLUB_H
#define CLUB_H

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

#include "../SquadPosition/squadPosition.h"
#include "../Headers/clubIDs.h"
#include "../util.h"
#include "../Action/actionPile.h"

class Stadium;
class SquadPosition;

typedef std::vector<Action*> ActionVector;
typedef std::map<float,Action*> ActionMap;
typedef std::pair<float,Action*> ActionPair;

class Club
{
	ActionVector attackingActions;
	ActionVector defendingActions;
	ActionVector goalkeepingActions;
	void initializeActions();

	Stadium* stadium;

	// CLUB INITIALIZATIONS
	void debug_init();
	void init_c_leicester16();
	void init_c_manunited16();
	void assignFootballer(SquadPosition* sp, int id, MainPosition mP, AligningPosition aP);

public:
	Club();
	Club(Stadium*, int, bool);
	~Club();

	// CLUB PROPERTIES
	wchar_t* fullName;
	wchar_t* shortName; // maximum 6 characters
	int id;
	sf::Color colorDark;
	sf::Color colorLight;
	sf::Color home_color0;
	sf::Color home_color1;
	sf::Color away_color0;
	sf::Color away_color1;
	
	// CLUB ATTRIBUTES

	// CLUB PROPERTIES IN THE MATCH
	bool isAway;
	
	// CLUB SQUADS
	SquadPosition* lineUp[11];
	SquadPosition* subs[12];
	SquadPosition* reserves[12];
	void assignClubs(); // Let every footballer know that they belong to this club.
	int squadSize;
	int subsSize;
	int reservesSize;
	void sortLineUp(); // Sort the lineup for visualization
	
	// CLUB INSTRUCTIONS (0.1 to 1)
	int taker_leftCornerKick, taker_rightCornerKick, taker_leftFreeKick, taker_rightFreeKick, taker_penalty;
	float mentality, defensiveLine; // general
	float defendingWidth; // defensive
	float attackingWidth, buildUpSpeed_ownHalf, buildUpSpeed_oppositeHalf; // attacking

	// CLUB VARIABLES CHANGE OVER THE MATCH
	bool onTheRightGoal; // Does team defend the goal on the right hand side?
	float currentDefensiveLine; // The x position of defensive line at the moment.
	float currentLeftmost; // The x position of fictional leftmost player with tactical_x=0
	float currentUppermost; // The y position of fictional leftmost player with tactical_y=0
	float currentWidth; // The width of team (attacking or defending)

	float sinceBallIsPassed; // How much time passed since the ball is kicked.
	sf::Vector2f ballPassedFrom; // The coordinates of source of the pass.
	bool someoneGettingBall;
	SquadPosition* playerGettingBall; // The index of player getting the ball. -1 if nobody is getting.
	SquadPosition* closestPlayer; // The index of player closest to ball.
	void findClosestPlayer();

	void updateTeamValues(); // Update following values that are only changed by tactical changes.
	
	// float defaultTeamLength; // Default team length, from leftmost player to the rightmost player. 

	// STADIUM FUNCTIONS
	void takeKickOffPositions(bool weStart);
	void takeGoalKickPositions(bool weTake);
	void takeCornerKickPositions(bool weTake);
	void takeFreeKickPositions(bool weTake);
	void takeThrowInPositions(bool weTake);

	void updateAttackingPlay();
	void updateDefendingPlay();

	bool isSomeoneThere_rect(float left, float right, float top, float bottom); // Returns if any player is in the rect.
	bool isSomeoneThere_points(sf::Vector2f point1, sf::Vector2f point2, float margin); // Returns if any player is in the rect.

};

#endif