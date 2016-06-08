#define _USE_MATH_DEFINES
#include <btBulletDynamicsCommon.h>

#include "util.h"
#include <SFML/Graphics.hpp>
#include <math.h>

float convertFromUnitInterval(float number, float start, float end)
{
	return ( number*(end-start)+start );
}

bool isOutOfRange10(int value, int change)
{
	return (value==1 && change<0) || (value==10 && change>0);
}

float distanceBetween(sf::Vector2f first, sf::Vector2f second)
{
	return sqrt( pow(first.x-second.x,2)+pow(first.y-second.y,2) );
}

float RandomBetween(float first, float second)
{
	return (second-first) * (static_cast <float> (rand()) / static_cast <float> (RAND_MAX)) + first;
}

void ChangeInstr(float* value, float change)
{
	if ((*value>0.98 && change>0) || (*value<0.12 && change<0))
		return;
	else
		*value += change;
	return;

}

bool isBetweenTwoPoints(sf::Vector2f ourpoint, sf::Vector2f first, sf::Vector2f second)
{
	float minx, miny, maxx, maxy;
	if (first.x<second.x)
	{
		minx=first.x; maxx=second.x;
	}
	else
	{
		minx=second.x; maxx=first.x;
	}

	if (first.y<second.y)
	{
		miny=first.y; maxy=second.y;
	}
	else
	{
		miny=second.y; maxy=first.y;
	}

	if (ourpoint.x>=minx && ourpoint.x<=maxx && ourpoint.y>=miny && ourpoint.y<=maxy)
		return true;

	return false;
};

sf::Vector3f vector2f_to_3f(sf::Vector2f input)
{
	return sf::Vector3f(input.x,0,input.y);
};

sf::Vector2f vector3f_to_2f(sf::Vector3f input)
{
	return sf::Vector2f(input.x,input.z);
};

double getAngle(float x1, float y1, float x2, float y2)
{
   float toReturn,theta1,theta2;

   theta1 = atan2(y1,x1);
   theta2 = atan2(y2,x2);
   toReturn = theta2 - theta1;
   while (toReturn > M_PI)
      toReturn -= 2.0 * M_PI;
   while (toReturn < -M_PI)
      toReturn += 2.0 * M_PI;

   return(toReturn);
}

bool isPointInTetragon(sf::Vector2f point, sf::Vector2f* tetragon)
{
	float angle=0; sf::Vector2f p1,p2;
	for (int i=0;i<4;i++) {
      p1.x = tetragon[i].x - point.x;
      p1.y = tetragon[i].y - point.y;
      p2.x = tetragon[(i+1)%4].x - point.x;
      p2.y = tetragon[(i+1)%4].y - point.y;
      angle += getAngle(p1.x,p1.y,p2.x,p2.y);
   }
   if (abs(angle) < M_PI) return false;
   else return true;	
};

bool isPointBetween(sf::Vector2f testPoint, sf::Vector2f point1, sf::Vector2f point2, float margin)
{
	float slope1 = (point2.y-point1.y)/(point2.x-point1.x);
	float slope2 = -1.0/slope1;
	float angle = atan(slope2);
	float x_dif = margin * cos(angle);
	float y_dif = margin * sin(angle);
	sf::Vector2f tetragon[4] = {
		sf::Vector2f(point1.x+x_dif,point1.y+y_dif),
		sf::Vector2f(point1.x-x_dif,point1.y-y_dif),
		sf::Vector2f(point2.x-x_dif,point2.y-y_dif),
		sf::Vector2f(point2.x+x_dif,point2.y+y_dif)
	};
	return isPointInTetragon(testPoint,tetragon);
};

int moduloNatural(int input, int mod)
{
	if(input<0)
		return moduloNatural(input+mod,mod);
	else if (input>=mod)
		return moduloNatural(input-mod,mod);
	else
		return input;
};

sf::Vector2f CalculatePassImpulse(sf::Vector2f direction)
{
	float impulse;
	float distance_direction = sqrt( std::pow(direction.x,2.0) + std::pow(direction.y,2.0) );
	impulse = (100.0*log((distance_direction/450.0)+1.0)) +1.0;

	return sf::Vector2f(direction.x*impulse/distance_direction, direction.y*impulse/distance_direction );
}