#include "squadPosition.h"
#include "../Club/club.h"
#include <iostream>

SquadPosition::SquadPosition()
{
	lastMotion = 0;
	sinceBallIsControlled = 0;
	countdown_showName = 0;
}

SquadPosition::~SquadPosition()
{

}

void SquadPosition::UpdatePositions()
{
	if (tactical_x<0.2)
		mainPosition = Main_GK;
	else if (tactical_x<0.35)
		mainPosition = Main_D;
	else if (tactical_x<=0.45)
		mainPosition = Main_DM;
	else if (tactical_x<0.55)
		mainPosition = Main_M;
	else if (tactical_x<=0.65)
		mainPosition = Main_AM;
	else if (tactical_x<0.85)
		mainPosition = Main_F;

	if (tactical_y<=0.33)
		aligningPosition = Aligning_L;
	else if (tactical_y<0.67)
		aligningPosition = Aligning_C;
	else if (tactical_y>=0.67)
		aligningPosition = Aligning_R;
}

float getBetweenNumbers(float x, float min, float max)
{
	if (x<min) return min;
	else if (x>max) return max;
	else return x;
}

void SquadPosition::set_tactical(float x2, float y2)
{
	tactical_x=getBetweenNumbers(x2,0.05,0.85); 
	tactical_y=getBetweenNumbers(y2,0.05,0.95);
}

void SquadPosition::add_tactical(float x2, float y2)
{
	tactical_x+=x2;
	if (mainPosition==Main_GK)
	{
		tactical_x=getBetweenNumbers(tactical_x,0.05,0.15);
	}
	else
	{
		tactical_y+=y2;
		tactical_x=getBetweenNumbers(tactical_x,0.2,0.85);
		tactical_y=getBetweenNumbers(tactical_y,0.05,0.95);
	}

	UpdatePositions();
}

void SquadPosition::set_defending(float x2, float y2)
{
	defending_x=getBetweenNumbers(x2,0.05,0.85); 
	defending_y=getBetweenNumbers(y2,0.05,0.95);
}

void SquadPosition::add_defending(float x2, float y2)
{
	defending_x+=x2;
	if (mainPosition==Main_GK)
	{
		defending_x=getBetweenNumbers(tactical_x,0.05,0.15);
	}
	else
	{
		defending_y+=y2;
		defending_x=getBetweenNumbers(defending_x,0.2,0.85);
		defending_y=getBetweenNumbers(defending_y,0.05,0.95);
	}
	UpdatePositions();
}

wstring SquadPosition::getstring_mainPosition()
{
	switch(mainPosition)
	{
	case Main_GK:
		return L"GK";
	case Main_D:
		return L"D";
	case Main_DM:
		return L"DM";
	case Main_M:
		return L"M";
	case Main_AM:
		return L"AM";
	case Main_F:
		return L"F";
	default:
		return L"";
	}
};

wstring SquadPosition::getstring_aligningPosition()
{
	switch(aligningPosition)
	{
	case Aligning_C:
		return L"C";
	case Aligning_L:
		return L"L";
	case Aligning_R:
		return L"R";
	default:
		return L"";
	}
};

float SquadPosition::goTowardsPoint(float dest_x, float dest_y, float amount)
{
	float distance = distanceBetween(sf::Vector2f(dest_x,dest_y), sf::Vector2f(x,y));
	float ratio;
	if (distance<amount)
		ratio = 1;
	else
		ratio = amount / distance;

	x += ratio * (dest_x-x);
	y += ratio * (dest_y-y);
	return distance;
}