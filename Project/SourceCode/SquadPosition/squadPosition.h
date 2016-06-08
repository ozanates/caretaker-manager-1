#ifndef SQUADPOSITION_H

#define SQUADPOSITION_H

#include "../Footballer/footballer.h"
#include "SFML\Graphics.hpp"

class Club;

enum MainPosition
{
	Main_GK, // DEFAULT = 0.1 // 0.05 <= tactical_x <= 0.15
	Main_D, // DEFAULT = 0.3 // 0.2 <= tactical_x < 0.35
	Main_DM, // DEFAULT = 0.4 // 0.35 <= tactical_x <= 0.45
	Main_M, // DEFAULT 0.5 // 0.45 < tactical_x < 0.55
	Main_AM, // DEFAULT 0.6 // 0.55 <= tactical_x <= 0.65
	Main_F, // DEFAULT 0.7 // 0.65 < tactical_x <= 0.85
	Main_SUB,
	Main_RESERVE
};

enum AligningPosition
{
	Aligning_R, // 0.65 <= tactical_x < 1
	Aligning_L, // 0 < tactical_y <= 0.33
	Aligning_C // 0.35 < tactical_y < 0.67
};

enum Duty
{
	noDuty,
	moveToGatherBall,
	dribble
};

class SquadPosition
{
	Footballer* footballer;
	
	void UpdatePositions();

	sf::FloatRect teamSheetBound;
	sf::FloatRect formationBound;
	
public:
	SquadPosition();
	~SquadPosition();
	void set_footballer(Footballer* f){footballer=f;}
	Footballer* get_footballer(){return footballer;}

	Club* club;
	bool isClubAway; // Returns if player's club is away on the ground.
	
	// STADIUM VARIABLES (THAT CHANGE OVER THE MATCH)
	float x, y, theta; // position and latest orientation
	int countdown_showName;
	float lastMotion; // last change in position
	sf::Vector2f destination; // player's destination to move.
	sf::Vector2f destinationDribbling; // player's destination for dribbling.
	Duty currentDuty; // player's current duty
	SquadPosition* target_simplePass;
	float sinceBallIsControlled; // the time passed since player controlled the ball

	// STADIUM FUNCTIONS
	void setPosition(float x2, float y2){x=x2; y=y2;}
	sf::Vector2f getPosition(){return sf::Vector2f(x,y);}
	float goTowardsPoint(float dest_x, float dest_y, float amount); // Make player to go towards point.

	// TACTICAL PROPERTIES
	float tactical_x; // between 0 and 1
	float tactical_y; // between 0 and 1
	float defending_x; // between 0 and 1
	float defending_y; // between 0 and 1
	MainPosition mainPosition;
	AligningPosition aligningPosition;
	void set_tactical(float, float);
	void add_tactical(float, float);
	void set_defending(float, float);
	void add_defending(float, float);
	wstring getstring_mainPosition();
	wstring getstring_aligningPosition();

	// PLAYER INSTRUCTIONS (0.1 to 1)
	float freq_shooting, freq_dribblingPast, freq_dribblingForward, freq_riskyPassing, freq_crossing;
	//TODO: freq_runBehindDefend, freq_getIntoBox;

	void set_teamSheetBound(sf::FloatRect bound){teamSheetBound=bound;}
	sf::FloatRect get_teamSheetBound(){return teamSheetBound;}
	void set_formationBound(sf::FloatRect bound){formationBound=bound;}
	sf::FloatRect get_formationBound(){return formationBound;}
};

#endif SQUADPOSITION_H