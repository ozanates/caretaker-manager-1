#pragma once

#include <SFML/Graphics.hpp>
#include "../Headers/fileLocations.h"
#include <iostream>

class Fonts
{
public:
	Fonts();
	sf::Font button;
	sf::Font regular;
	sf::Font scoreboard;
	sf::Font wideRegular;
	sf::Font narrowRegular;
};