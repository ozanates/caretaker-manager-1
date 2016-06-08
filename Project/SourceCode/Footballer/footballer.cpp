#include "footballer.h"
#include "../Headers/clubIDs.h"
#include <iostream>

Footballer::Footballer(int id)
{
	debug_initFootballer(id);
}

Footballer::~Footballer()
{
	
}

void Footballer::init_shownNames()
{
	if (hasNickname)
	{
		fullName_shown = nickname;
		shortName_shown = nickname;
	}
	else
	{
		if(usesFirstName) 
			shortName_shown = name + L" " + surname[0] + L".";
		else
		{
			wstring wstr = L". " + surname;
			shortName_shown = name[0] + wstr;
		}
		fullName_shown = name + L" " + surname;
	}
};

void Footballer::debug_initFootballer(int id)
{
	hasNickname = false;
	usesFirstName = false;
	int teamID = id/100;
	switch(teamID)
	{
	case ID_LEICESTER16:
		init_f_leicester16(id);
		break;
	case ID_MANUNITED16:
		init_f_manunited16(id);
		break;
	default:
		cout << "Error: Wrong footballer id" << id << endl;
	}

	if (fullName.empty())
		fullName = name + L" " + surname;

	init_shownNames();
}

void Footballer::default_skills()
{
	maximumSpeed=20; acceleration=20; agility=20; reaction=20; // PHYSICAL
	attackingPositioning=20; passingVision=20; // MENTAL ATTACKING
	tacticalDiscipline=20; concentration=20; // MENTAL
	shortPassing=20; longPassing=20; firstTouch=20; dribbling=20; // TECHNIQUE
}

float Footballer::getMaxSpeed()
{
	return (0.1 * maximumSpeed) / 100.0;
}

float Footballer::getMaxAcceleration()
{
	return (0.03 * acceleration) / 100.0;
}