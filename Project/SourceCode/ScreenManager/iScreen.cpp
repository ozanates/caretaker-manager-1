#include "iScreen.h"
#include <iostream>

iScreen::iScreen(sf::RenderWindow* w, Game* g, Fonts* f, Stadium* s){
	if (!tex_mainBackground.loadFromFile(LOCATION_BACKGROUND1))
		std::cout << "Error: Background1 could not be loaded from file" << std::endl;	
	else
		tex_mainBackground.setSmooth(true);

	if (!tex_FootballPitch.loadFromFile(LOCATION_PITCH))
		std::cout << "Error: Football Pitch for Tactic Screen could not be loaded from file" << endl;
	else
		tex_FootballPitch.setSmooth(true);

	window = w;
	game = g;
	fonts = f;
	stadium = s;
};

sf::FloatRect iScreen::drawText(const sf::String& str, const sf::Font& font, const unsigned int& size, const sf::Uint32& style, const float& x, const float& y, const sf::Color& color)
{
	sf::Text text;
	text.setFont(font);
	text.setString(str);
	text.setCharacterSize(size);
	text.setStyle(style);
	text.setPosition(x,y);
	text.setColor(color);
	window->draw(text);
	
	return text.getGlobalBounds();
};

void iScreen::drawLine(sf::Vector2f first, sf::Vector2f second, sf::Color color0, sf::Color color1)
{
	sf::Vertex line[2] = { first, second};
	line[0].color = color0;
	line[1].color = color1;
	window->draw(line, 2, sf::Lines);
};

void iScreen::drawSimpleText(const sf::String& str, const float& x, const float& y)
{
	int size = 10;
	sf::Uint32 style = sf::Text::Regular;
	sf::Color color = sf::Color::Black;
	sf::Text text;
	text.setFont(fonts->regular);
	text.setString(str);
	text.setCharacterSize(size);
	text.setStyle(style);
	text.setPosition(x,y);
	text.setColor(color);
	window->draw(text);
	
	return;
};

void iScreen::drawBackground()
{
	sf::Sprite sprite;
	sprite.setTexture(tex_mainBackground);
	sprite.setScale(sf::Vector2f( (window->getSize().x)*1.0/Background1_x, (window->getSize().y)*1.0/Background1_y ));
	window->draw(sprite);
}



bool iScreen::RenderClosing()
{
	int x, y;

	// Definitions for side buttons (Exit)
	sf::RectangleShape recButton_Exit_AreYouSure(sf::Vector2f(BUTTON_MAIN_SECOND_WIDTH,BUTTON_MAIN_SECOND_HEIGHT));
	recButton_Exit_AreYouSure.setPosition(BUTTON_MAIN_SECOND_LEFT,BUTTON_MAIN_EXIT_AREYOUSURE_TOP);

	sf::RectangleShape recButton_Exit_Yes(sf::Vector2f(BUTTON_MAIN_EXIT_YESNO_WIDTH,BUTTON_MAIN_EXIT_YESNO_HEIGHT));
	recButton_Exit_Yes.setPosition(BUTTON_MAIN_EXIT_YES_LEFT, BUTTON_MAIN_EXIT_YESNO_TOP);

	sf::RectangleShape recButton_Exit_No(sf::Vector2f(BUTTON_MAIN_EXIT_YESNO_WIDTH,BUTTON_MAIN_EXIT_YESNO_HEIGHT));
	recButton_Exit_No.setPosition(BUTTON_MAIN_EXIT_NO_LEFT, BUTTON_MAIN_EXIT_YESNO_TOP);

	sf::Text text_Exit_AreYouSure, text_Exit_Yes, text_Exit_No;

	text_Exit_AreYouSure.setFont(fonts->button);
	text_Exit_AreYouSure.setString(langstrings->CLOSINGSCREEN_001);
	text_Exit_AreYouSure.setCharacterSize(BUTTON1_TEXT_SIZE/2);
	text_Exit_AreYouSure.setStyle(sf::Text::Regular);
	text_Exit_AreYouSure.setPosition(BUTTON_MAIN_SECOND_LEFT+BUTTON1_TEXT_MARGIN, BUTTON_MAIN_EXIT_AREYOUSURE_TOP+BUTTON1_TEXT_MARGIN);

	text_Exit_Yes.setFont(fonts->button);
	text_Exit_Yes.setString(langstrings->GENERAL_0001);
	text_Exit_Yes.setCharacterSize(BUTTON1_TEXT_SIZE);
	text_Exit_Yes.setStyle(sf::Text::Bold);
	text_Exit_Yes.setPosition(BUTTON_MAIN_EXIT_YES_LEFT+BUTTON1_TEXT_MARGIN, BUTTON_MAIN_EXIT_YESNO_TOP+BUTTON1_TEXT_MARGIN);

	text_Exit_No.setFont(fonts->button);
	text_Exit_No.setString(langstrings->GENERAL_0002);
	text_Exit_No.setCharacterSize(BUTTON1_TEXT_SIZE);
	text_Exit_No.setStyle(sf::Text::Bold);
	text_Exit_No.setPosition(BUTTON_MAIN_EXIT_NO_LEFT+BUTTON1_TEXT_MARGIN, BUTTON_MAIN_EXIT_YESNO_TOP+BUTTON1_TEXT_MARGIN);

	while (window->isOpen())
	{
		while (window->pollEvent(event))
		{
			recButton_Exit_AreYouSure.setOutlineColor(BUTTON1_OUTSIDE_COLOR);
			recButton_Exit_AreYouSure.setFillColor(BUTTON1_INSIDE_COLOR);
			recButton_Exit_AreYouSure.setOutlineThickness(BUTTON1_THICKNESS);
				
			recButton_Exit_Yes.setOutlineColor(BUTTON1_OUTSIDE_COLOR);
			recButton_Exit_Yes.setFillColor(BUTTON1_INSIDE_COLOR);
			recButton_Exit_Yes.setOutlineThickness(BUTTON1_THICKNESS);
			
			recButton_Exit_No.setOutlineColor(BUTTON1_OUTSIDE_COLOR);
			recButton_Exit_No.setFillColor(BUTTON1_INSIDE_COLOR);
			recButton_Exit_No.setOutlineThickness(BUTTON1_THICKNESS);

			text_Exit_AreYouSure.setColor(BUTTON1_TEXT_COLOR);
			text_Exit_Yes.setColor(BUTTON1_TEXT_COLOR);
			text_Exit_No.setColor(BUTTON1_TEXT_COLOR);

			switch (event.type)
			{
			case sf::Event::MouseMoved:
				x = event.mouseMove.x;
				y = event.mouseMove.y;
				if (y>BUTTON_MAIN_EXIT_YESNO_TOP && y<BUTTON_MAIN_EXIT_YESNO_TOP+BUTTON_MAIN_EXIT_YESNO_HEIGHT)
				{ // Mouse is moved to YES or NO
					if (x>BUTTON_MAIN_EXIT_YES_LEFT && x<BUTTON_MAIN_EXIT_YES_LEFT+BUTTON_MAIN_EXIT_YESNO_WIDTH)
					{ // Mouse is moved to YES
						recButton_Exit_Yes.setOutlineColor(BUTTON1_HOVERED_OUTSIDE_COLOR);
						recButton_Exit_Yes.setFillColor(BUTTON1_HOVERED_INSIDE_COLOR);
						recButton_Exit_Yes.setOutlineThickness(BUTTON1_HOVERED_THICKNESS);
						text_Exit_Yes.setColor(BUTTON1_HOVERED_TEXT_COLOR);
					}
					else if (x>BUTTON_MAIN_EXIT_NO_LEFT && x<BUTTON_MAIN_EXIT_NO_LEFT+BUTTON_MAIN_EXIT_YESNO_WIDTH)
					{ // Mouse is moved to NO
						recButton_Exit_No.setOutlineColor(BUTTON1_HOVERED_OUTSIDE_COLOR);
						recButton_Exit_No.setFillColor(BUTTON1_HOVERED_INSIDE_COLOR);
						recButton_Exit_No.setOutlineThickness(BUTTON1_HOVERED_THICKNESS);
						text_Exit_No.setColor(BUTTON1_HOVERED_TEXT_COLOR);
					}
				}
				break;

			case sf::Event::MouseButtonPressed:

				if (event.mouseButton.button == sf::Mouse::Left)
				{
					x = event.mouseButton.x;
					y = event.mouseButton.y;
					if (y>BUTTON_MAIN_EXIT_YESNO_TOP && y<BUTTON_MAIN_EXIT_YESNO_TOP+BUTTON_MAIN_EXIT_YESNO_HEIGHT)
					{ // Mouse is pressed on YES or NO
						if (x>BUTTON_MAIN_EXIT_YES_LEFT && x<BUTTON_MAIN_EXIT_YES_LEFT+BUTTON_MAIN_EXIT_YESNO_WIDTH)
						{ // Mouse is pressed on YES
							return true;
						}
						else if (x>BUTTON_MAIN_EXIT_NO_LEFT && x<BUTTON_MAIN_EXIT_NO_LEFT+BUTTON_MAIN_EXIT_YESNO_WIDTH)
						{ // Mouse is moved to NO
							return false;
						}
					}
				}
				break;
			}

			window->clear();
			window->draw(recButton_Exit_AreYouSure);
			window->draw(text_Exit_AreYouSure);

			window->draw(recButton_Exit_Yes);
			window->draw(text_Exit_Yes);

			window->draw(recButton_Exit_No);
			window->draw(text_Exit_No);
			window->display();
		}
	}
}