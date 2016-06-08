#ifndef UTIL_H

#define UTIL_H

#include <SFML\Graphics.hpp>

float convertFromUnitInterval(float number, float start, float end);

bool outOfRange10(int value, int change);

float distanceBetween(sf::Vector2f first, sf::Vector2f second);

float RandomBetween(float first, float second);

void ChangeInstr(float* value, float change);

bool isBetweenTwoPoints(sf::Vector2f ourpoint, sf::Vector2f first, sf::Vector2f second);

sf::Vector3f vector2f_to_3f(sf::Vector2f);

sf::Vector2f vector3f_to_2f(sf::Vector3f);

bool isPointInTetragon(sf::Vector2f point, sf::Vector2f* tetragon);

bool isPointBetween(sf::Vector2f testPoint, sf::Vector2f point1, sf::Vector2f point2, float margin);

int moduloNatural(int input, int bound);

sf::Vector2f CalculatePassImpulse(sf::Vector2f direction);

#endif