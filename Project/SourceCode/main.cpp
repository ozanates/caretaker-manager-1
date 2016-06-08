#include <SFML/Graphics.hpp>
#include "Headers/enum.h"
#include "game.h"
#include "ScreenManager/fonts.h"
#include "ScreenManager/screens.hpp"
#include "random.h"
#include <iostream>
#include <btBulletDynamicsCommon.h>

void drawSimpleText(sf::RenderWindow& window, const sf::Font& font, const sf::String& str, const float& x, const float& y)
{
	int size = 10;
	sf::Uint32 style = sf::Text::Regular;
	sf::Color color = sf::Color::Green;
	sf::Text text;
	text.setFont(font);
	text.setString(str);
	text.setCharacterSize(size);
	text.setStyle(style);
	text.setPosition(x,y);
	text.setColor(color);
	window.draw(text);
	
	return;
};

int main()
{
	// full screen
	//sf::RenderWindow window(sf::VideoMode(1366, 768), "RPG",sf::Style::Fullscreen);

	sf::RenderWindow window(sf::VideoMode(1366, 768), "Caretaker Manager", sf::Style::Close);
	window.setPosition(sf::Vector2i(0,0));
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);

	Random random;
	srand(time(NULL));
	Language *language = new Language;
	Game game(language);
	Fonts fonts;
	Stadium* stadium = new Stadium(&random,language);

	std::vector<iScreen*> Screens;
	int screen = DEBUG_STARTMATCH?3:0;

	MainScreen screen0(&window,&game,&fonts,stadium); 
	Screens.push_back(&screen0);
	SelectionScreen screen1(&window,&game,&fonts,stadium);
	Screens.push_back(&screen1);
	TacticScreen screen2(&window,&game,&fonts,stadium);
	Screens.push_back(&screen2);
	MatchScreen screen3(&window,&game,&fonts,stadium);
	Screens.push_back(&screen3);

	while (screen >= 0 && screen!=exitSignal)
	{
		screen = Screens[screen]->Render();
	}
	window.close();

    return EXIT_SUCCESS;
}