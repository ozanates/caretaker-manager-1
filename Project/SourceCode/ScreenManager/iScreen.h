#ifndef ISCREEN_H
#define ISCREEN_H

#include "..\Headers\enum.h"
#include "..\Headers\fileLocations.h"
#include "style_general.h"
#include "../game.h"
#include "../SquadPosition/squadPosition.h"
#include "../Stadium/stadium.h"
#include "fonts.h"
#include <string>

#include "..\debugoptions.h"

#define langstrings game->language

class iScreen
{
protected :
	sf::RenderWindow* window;
	Game* game;
	Fonts* fonts;
	e_Window earlierScreen;
	sf::Event event;

	Stadium* stadium;

	sf::Texture tex_mainBackground;
	sf::Texture tex_FootballPitch;

	sf::FloatRect drawText(const sf::String& str, const sf::Font& font, const unsigned int& size, const sf::Uint32& style, const float& x, const float& y, const sf::Color& color);
	void drawSimpleText(const sf::String& str, const float& x, const float& y);
	void drawLine(sf::Vector2f,sf::Vector2f, sf::Color, sf::Color);
	void drawBackground();
	
	bool RenderClosing();
	
public :
	iScreen();
	iScreen(sf::RenderWindow* w, Game* g, Fonts* f, Stadium* s);
    virtual e_Window Render() = 0;
};

#endif