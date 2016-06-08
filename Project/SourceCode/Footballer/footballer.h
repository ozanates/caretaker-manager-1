#ifndef FOOTBALLER_H

#define FOOTBALLER_H

#include <string>

using namespace std;

class Footballer
{
public:
	Footballer(int);
	~Footballer();
	void debug_initFootballer(int);
	void init_shownNames();

	// FOOTBALLER PROPERTIES
	wstring name;
	wstring surname;
	wstring fullName;
	bool hasNickname;
	wstring nickname;
	bool usesFirstName;
	wstring fullName_shown;
	wstring shortName_shown;

	int birthYear;
	int number;

	// CLUB-SPECIFIC FOOTBALLER INITIALIZATION FUNCTIONS
	void default_skills();
	void init_f_leicester16(int);
	void init_f_manunited16(int);

	// FOOTBALLER SKILLS
	// TECHNIQUE
	int shortPassing, longPassing, firstTouch, dribbling;

	// PHYSICAL
	int maximumSpeed, acceleration, agility, reaction;

	// MENTAL
	int tacticalDiscipline, concentration;

	// MENTAL ATTACKING
	int attackingPositioning, passingVision;

	// FUNCTIONS
	float getMaxSpeed(); // Returns the maximum speed (meter/frame) that he could go.
	float getMaxAcceleration(); // Returns the maximum speed (meter/frame) change in a frame.
};

#endif