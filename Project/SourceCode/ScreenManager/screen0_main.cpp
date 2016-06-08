#include "screen0_main.h"

MainScreen::MainScreen(sf::RenderWindow* w, Game* g, Fonts* f, Stadium* s):iScreen(w,g,f,s)
{
}

void MainScreen::DefaultButtonColors()
{
	recButton_StartAGame.setOutlineColor(BUTTON1_OUTSIDE_COLOR);
	recButton_StartAGame.setFillColor(BUTTON1_INSIDE_COLOR);
	recButton_StartAGame.setOutlineThickness(BUTTON1_THICKNESS);

	recButton_Options.setOutlineColor(BUTTON1_OUTSIDE_COLOR);
	recButton_Options.setFillColor(BUTTON1_INSIDE_COLOR);
	recButton_Options.setOutlineThickness(BUTTON1_THICKNESS);

	recButton_Exit.setOutlineColor(BUTTON1_OUTSIDE_COLOR);
	recButton_Exit.setFillColor(BUTTON1_INSIDE_COLOR);
	recButton_Exit.setOutlineThickness(BUTTON1_THICKNESS);

	text_StartAGame.setColor(BUTTON1_TEXT_COLOR);
	text_Options.setColor(BUTTON1_TEXT_COLOR);
	text_Exit.setColor(BUTTON1_TEXT_COLOR);

	recButton_English.setOutlineColor(BUTTON1_OUTSIDE_COLOR);
	recButton_English.setFillColor(BUTTON1_INSIDE_COLOR);
	recButton_English.setOutlineThickness(BUTTON1_THICKNESS);
	recButton_Turkish.setOutlineColor(BUTTON1_OUTSIDE_COLOR);
	recButton_Turkish.setFillColor(BUTTON1_INSIDE_COLOR);
	recButton_Turkish.setOutlineThickness(BUTTON1_THICKNESS);
	text_English.setColor(BUTTON1_TEXT_COLOR);
	text_Turkish.setColor(BUTTON1_TEXT_COLOR);
}

void MainScreen::ShowGameModeChoices()
{
	recButton_Scenario.setOutlineColor(BUTTON1_OUTSIDE_COLOR);
	recButton_Scenario.setFillColor(BUTTON1_INSIDE_COLOR);
	recButton_Scenario.setOutlineThickness(BUTTON1_THICKNESS);
				
	recButton_Random.setOutlineColor(BUTTON1_OUTSIDE_COLOR);
	recButton_Random.setFillColor(BUTTON1_INSIDE_COLOR);
	recButton_Random.setOutlineThickness(BUTTON1_THICKNESS);
			
	recButton_Custom.setOutlineColor(BUTTON1_OUTSIDE_COLOR);
	recButton_Custom.setFillColor(BUTTON1_INSIDE_COLOR);
	recButton_Custom.setOutlineThickness(BUTTON1_THICKNESS);

	text_SelectAScenario.setColor(BUTTON1_TEXT_COLOR);
	text_CustomMatch.setColor(BUTTON1_TEXT_COLOR);
	text_RandomMatch.setColor(BUTTON1_TEXT_COLOR);
	text_Back.setColor(BUTTON1_TEXT_COLOR);
}

void MainScreen::UpdateStrings()
{
	text_StartAGame.setString(langstrings->MAINSCREEN_001);
	text_Options.setString(langstrings->MAINSCREEN_002);
	text_Exit.setString(langstrings->MAINSCREEN_003);
	text_Back.setString(langstrings->GENERAL_0003);

	text_SelectAScenario.setString(langstrings->MAINSCREEN_005);
	text_RandomMatch.setString(langstrings->MAINSCREEN_006);
	text_CustomMatch.setString(langstrings->MAINSCREEN_007);
}

void MainScreen::InitializeScreen()
{
	UpdateStrings();

	// Text definitions for main buttons
	text_StartAGame.setFont(fonts->button);
	
	text_StartAGame.setCharacterSize(BUTTON1_TEXT_SIZE);
	text_StartAGame.setStyle(sf::Text::Bold);
	text_StartAGame.setPosition(BUTTON_MAIN_FIRST_LEFT+BUTTON1_TEXT_MARGIN, BUTTON_MAIN_STARTAGAME_TOP+BUTTON1_TEXT_MARGIN);

	text_Options.setFont(fonts->button);

	text_Options.setCharacterSize(BUTTON1_TEXT_SIZE);
	text_Options.setStyle(sf::Text::Bold);
	text_Options.setPosition(BUTTON_MAIN_FIRST_LEFT+BUTTON1_TEXT_MARGIN, BUTTON_MAIN_OPTIONS_TOP+BUTTON1_TEXT_MARGIN);

	text_Exit.setFont(fonts->button);
	
	text_Exit.setCharacterSize(BUTTON1_TEXT_SIZE);
	text_Exit.setStyle(sf::Text::Bold);
	text_Exit.setPosition(BUTTON_MAIN_FIRST_LEFT+BUTTON1_TEXT_MARGIN, BUTTON_MAIN_EXIT_TOP+BUTTON1_TEXT_MARGIN);

	text_Back.setFont(fonts->button);
	
	text_Back.setCharacterSize(BUTTON1_TEXT_SIZE);
	text_Back.setStyle(sf::Text::Bold);
	text_Back.setPosition(BUTTON_MAIN_FIRST_LEFT+BUTTON1_TEXT_MARGIN, BUTTON_MAIN_EXIT_TOP+BUTTON1_TEXT_MARGIN);

	// Text definitions for side buttons (Start a Game)
	text_SelectAScenario.setFont(fonts->button);
	
	text_SelectAScenario.setCharacterSize(BUTTON1_TEXT_SIZE);
	text_SelectAScenario.setStyle(sf::Text::Bold);
	text_SelectAScenario.setPosition(BUTTON_MAIN_SECOND_LEFT+BUTTON1_TEXT_MARGIN, BUTTON_MAIN_SCENARIO_TOP+BUTTON1_TEXT_MARGIN);

	text_RandomMatch.setFont(fonts->button);
	
	text_RandomMatch.setCharacterSize(BUTTON1_TEXT_SIZE);
	text_RandomMatch.setStyle(sf::Text::Bold);
	text_RandomMatch.setPosition(BUTTON_MAIN_SECOND_LEFT+BUTTON1_TEXT_MARGIN, BUTTON_MAIN_RANDOM_TOP+BUTTON1_TEXT_MARGIN);

	text_CustomMatch.setFont(fonts->button);
	
	text_CustomMatch.setCharacterSize(BUTTON1_TEXT_SIZE);
	text_CustomMatch.setStyle(sf::Text::Bold);
	text_CustomMatch.setPosition(BUTTON_MAIN_SECOND_LEFT+BUTTON1_TEXT_MARGIN, BUTTON_MAIN_CUSTOM_TOP+BUTTON1_TEXT_MARGIN);

	// Definitions for main buttons
	recButton_StartAGame.setSize(sf::Vector2f(BUTTON_MAIN_FIRST_WIDTH,BUTTON_MAIN_FIRST_HEIGHT));
	recButton_StartAGame.setPosition(BUTTON_MAIN_FIRST_LEFT,BUTTON_MAIN_STARTAGAME_TOP);
		
	recButton_Options.setSize(sf::Vector2f(BUTTON_MAIN_FIRST_WIDTH,BUTTON_MAIN_FIRST_HEIGHT));
	recButton_Options.setPosition(BUTTON_MAIN_FIRST_LEFT,BUTTON_MAIN_OPTIONS_TOP);
	
	recButton_Exit.setSize(sf::Vector2f(BUTTON_MAIN_FIRST_WIDTH,BUTTON_MAIN_FIRST_HEIGHT));
	recButton_Exit.setPosition(BUTTON_MAIN_FIRST_LEFT,BUTTON_MAIN_EXIT_TOP);	

	// Definitions for side buttons (Start a Game)
	recButton_Scenario.setSize(sf::Vector2f(BUTTON_MAIN_SECOND_WIDTH,BUTTON_MAIN_SECOND_HEIGHT));
	recButton_Scenario.setPosition(BUTTON_MAIN_SECOND_LEFT,BUTTON_MAIN_SCENARIO_TOP);

	recButton_Random.setSize(sf::Vector2f(BUTTON_MAIN_SECOND_WIDTH,BUTTON_MAIN_SECOND_HEIGHT));
	recButton_Random.setPosition(BUTTON_MAIN_SECOND_LEFT,BUTTON_MAIN_RANDOM_TOP);

	recButton_Custom.setSize(sf::Vector2f(BUTTON_MAIN_SECOND_WIDTH,BUTTON_MAIN_SECOND_HEIGHT));
	recButton_Custom.setPosition(BUTTON_MAIN_SECOND_LEFT,BUTTON_MAIN_CUSTOM_TOP);

	// Definitions for Language Options
	recButton_English.setSize(sf::Vector2f(BUTTON_LANG_WIDTH,BUTTON_LANG_HEIGHT));
	recButton_English.setPosition(BUTTON_LANG_LEFT,BUTTON_LANG_EN_TOP);

	recButton_Turkish.setSize(sf::Vector2f(BUTTON_LANG_WIDTH,BUTTON_LANG_HEIGHT));
	recButton_Turkish.setPosition(BUTTON_LANG_LEFT,BUTTON_LANG_TR_TOP);

	text_English.setFont(fonts->button);
	text_English.setString("English");
	text_English.setCharacterSize(BUTTON1_TEXT_SIZE/2.0);
	text_English.setStyle(sf::Text::Bold);
	text_English.setPosition(BUTTON_LANG_LEFT+BUTTON1_TEXT_MARGIN/2.0, BUTTON_LANG_EN_TOP+BUTTON1_TEXT_MARGIN/2.0);

	text_Turkish.setFont(fonts->button);
	text_Turkish.setString(L"Türkçe");
	text_Turkish.setCharacterSize(BUTTON1_TEXT_SIZE/2.0);
	text_Turkish.setStyle(sf::Text::Bold);
	text_Turkish.setPosition(BUTTON_LANG_LEFT+BUTTON1_TEXT_MARGIN/2.0, BUTTON_LANG_TR_TOP+BUTTON1_TEXT_MARGIN/2.0);
};

void MainScreen::ControlMouseMoved()
{
	// Mouse is moved to a position.
	x = event.mouseMove.x;
	y = event.mouseMove.y;
	if (x>BUTTON_MAIN_FIRST_LEFT && x<BUTTON_MAIN_FIRST_LEFT+BUTTON_MAIN_FIRST_WIDTH)
	{ // Mouse is moved to one of the main buttons on the left.
		if (y>BUTTON_MAIN_STARTAGAME_TOP && y<BUTTON_MAIN_STARTAGAME_TOP+BUTTON_MAIN_FIRST_HEIGHT)
		{ // Mouse is moved to button named "Start a Game".
			recButton_StartAGame.setOutlineColor(BUTTON1_HOVERED_OUTSIDE_COLOR);
			recButton_StartAGame.setFillColor(BUTTON1_HOVERED_INSIDE_COLOR);
			recButton_StartAGame.setOutlineThickness(BUTTON1_HOVERED_THICKNESS);
			text_StartAGame.setColor(BUTTON1_HOVERED_TEXT_COLOR);
		}
		else if (y>BUTTON_MAIN_OPTIONS_TOP && y<BUTTON_MAIN_OPTIONS_TOP+BUTTON_MAIN_FIRST_HEIGHT)
		{ // Mouse is moved to button named "Options".
			recButton_Options.setOutlineColor(BUTTON1_HOVERED_OUTSIDE_COLOR);
			recButton_Options.setFillColor(BUTTON1_HOVERED_INSIDE_COLOR);
			recButton_Options.setOutlineThickness(BUTTON1_HOVERED_THICKNESS);
			text_Options.setColor(BUTTON1_HOVERED_TEXT_COLOR);
		}
		else if (y>BUTTON_MAIN_EXIT_TOP && y<BUTTON_MAIN_EXIT_TOP+BUTTON_MAIN_FIRST_HEIGHT)
		{ // Mouse is moved to button named "Exit".
			recButton_Exit.setOutlineColor(BUTTON1_HOVERED_OUTSIDE_COLOR);
			recButton_Exit.setFillColor(BUTTON1_HOVERED_INSIDE_COLOR);
			recButton_Exit.setOutlineThickness(BUTTON1_HOVERED_THICKNESS);
			text_Exit.setColor(BUTTON1_HOVERED_TEXT_COLOR);
			text_Back.setColor(BUTTON1_HOVERED_TEXT_COLOR);
		}
	}

	else if (startIsSelected && x>BUTTON_MAIN_SECOND_LEFT && x<BUTTON_MAIN_SECOND_LEFT+BUTTON_MAIN_SECOND_WIDTH)
	{ // Mouse is moved to Select a Scenario or Random Match or Custom Match
		if (y>BUTTON_MAIN_SCENARIO_TOP && y<BUTTON_MAIN_SCENARIO_TOP+BUTTON_MAIN_SECOND_HEIGHT)
		{ // Mouse is moved to Select a Scenario
			recButton_Scenario.setOutlineColor(BUTTON1_HOVERED_OUTSIDE_COLOR);
			recButton_Scenario.setFillColor(BUTTON1_HOVERED_INSIDE_COLOR);
			recButton_Scenario.setOutlineThickness(BUTTON1_HOVERED_THICKNESS);
			text_SelectAScenario.setColor(BUTTON1_HOVERED_TEXT_COLOR);
		}
		else if (y>BUTTON_MAIN_RANDOM_TOP && y<BUTTON_MAIN_RANDOM_TOP+BUTTON_MAIN_SECOND_HEIGHT)
		{ // Mouse is moved to Random Match
			recButton_Random.setOutlineColor(BUTTON1_HOVERED_OUTSIDE_COLOR);
			recButton_Random.setFillColor(BUTTON1_HOVERED_INSIDE_COLOR);
			recButton_Random.setOutlineThickness(BUTTON1_HOVERED_THICKNESS);
			text_RandomMatch.setColor(BUTTON1_HOVERED_TEXT_COLOR);
		}
		else if (y>BUTTON_MAIN_CUSTOM_TOP && y<BUTTON_MAIN_CUSTOM_TOP+BUTTON_MAIN_SECOND_HEIGHT)
		{ // Mouse is moved to Custom Match
			recButton_Custom.setOutlineColor(BUTTON1_HOVERED_OUTSIDE_COLOR);
			recButton_Custom.setFillColor(BUTTON1_HOVERED_INSIDE_COLOR);
			recButton_Custom.setOutlineThickness(BUTTON1_HOVERED_THICKNESS);
			text_CustomMatch.setColor(BUTTON1_HOVERED_TEXT_COLOR);
		}
	}
	else if (x>BUTTON_LANG_LEFT && x<BUTTON_LANG_LEFT+BUTTON_LANG_WIDTH)
	{
		if (y>BUTTON_LANG_EN_TOP && y<BUTTON_LANG_EN_TOP+BUTTON_LANG_HEIGHT)
		{ // Mouse is moved to English
			recButton_English.setOutlineColor(BUTTON1_HOVERED_OUTSIDE_COLOR);
			recButton_English.setFillColor(BUTTON1_HOVERED_INSIDE_COLOR);
			recButton_English.setOutlineThickness(BUTTON1_HOVERED_THICKNESS);
			text_English.setColor(BUTTON1_HOVERED_TEXT_COLOR);
		}
		else if (y>BUTTON_LANG_TR_TOP && y<BUTTON_LANG_TR_TOP+BUTTON_LANG_HEIGHT)
		{ // Mouse is moved to Turkish
			recButton_Turkish.setOutlineColor(BUTTON1_HOVERED_OUTSIDE_COLOR);
			recButton_Turkish.setFillColor(BUTTON1_HOVERED_INSIDE_COLOR);
			recButton_Turkish.setOutlineThickness(BUTTON1_HOVERED_THICKNESS);
			text_Turkish.setColor(BUTTON1_HOVERED_TEXT_COLOR);
		}
	}
}

e_Window MainScreen::ControlMousePressed()
{
	if (event.mouseButton.button == sf::Mouse::Left)
	{
		x = event.mouseButton.x;
		y = event.mouseButton.y;
		if (x>BUTTON_MAIN_FIRST_LEFT && x<BUTTON_MAIN_FIRST_LEFT+BUTTON_MAIN_FIRST_WIDTH)
		{ // Left mouse button is pressed on one of the main buttons on the left.
			if (y>BUTTON_MAIN_STARTAGAME_TOP && y<BUTTON_MAIN_STARTAGAME_TOP+BUTTON_MAIN_FIRST_HEIGHT)
			{ // Left mouse button is pressed on the button named "Start a Game".
				recButton_StartAGame.setOutlineColor(BUTTON1_HOVERED_OUTSIDE_COLOR);
				recButton_StartAGame.setFillColor(BUTTON1_HOVERED_INSIDE_COLOR);
				startIsSelected=true;
			}
			else if (y>BUTTON_MAIN_EXIT_TOP && y<BUTTON_MAIN_EXIT_TOP+BUTTON_MAIN_FIRST_HEIGHT)
			{ // Left mouse button is pressed on the button named "Exit".
				if (startIsSelected)
				{ // The button is used as "Back" to the main screen.
					startIsSelected = false;
					return mainScreen;
				}
				else
				{
					if (RenderClosing())
						return exitSignal;
				}
			}
		}

		else if (startIsSelected && x>BUTTON_MAIN_SECOND_LEFT && x<BUTTON_MAIN_SECOND_LEFT+BUTTON_MAIN_SECOND_WIDTH)
		{ // Left mouse button is pressed on Select a Scenario or Random Match or Custom Match
			if (y>BUTTON_MAIN_SCENARIO_TOP && y<BUTTON_MAIN_SCENARIO_TOP+BUTTON_MAIN_SECOND_HEIGHT)
			{ // Left mouse button is pressed on Select a Scenario
				game->currentGameType = Scenario;
				return selectionScreen;
			}
			else if (y>BUTTON_MAIN_RANDOM_TOP && y<BUTTON_MAIN_RANDOM_TOP+BUTTON_MAIN_SECOND_HEIGHT)
			{ // Left mouse button is pressed on Random Match
				game->currentGameType = RandomMatch;
				return selectionScreen;
			}
			else if (y>BUTTON_MAIN_CUSTOM_TOP && y<BUTTON_MAIN_CUSTOM_TOP+BUTTON_MAIN_SECOND_HEIGHT)
			{ // Left mouse button is pressed on Custom Match
				game->currentGameType = CustomMatch;
				return selectionScreen;
			}
		}
		else if (x>BUTTON_LANG_LEFT && x<BUTTON_LANG_LEFT+BUTTON_LANG_WIDTH)
		{
			if (y>BUTTON_LANG_EN_TOP && y<BUTTON_LANG_EN_TOP+BUTTON_LANG_HEIGHT)
			{ // Left mouse button is pressed on English
				if (game->language->init_English())
					UpdateStrings();
			}
			else if (y>BUTTON_LANG_TR_TOP && y<BUTTON_LANG_TR_TOP+BUTTON_LANG_HEIGHT)
			{ // Left mouse button is pressed on Turkish
				if (game->language->init_Turkish())
					UpdateStrings();
			}
		}

	}

	return noChange;
}

e_Window MainScreen::Render()
{
	InitializeScreen();
	e_Window result;
	startIsSelected = false;

	while (window->isOpen())
	{
		while (window->pollEvent(event))
		{
			window->pollEvent(event);
			
			if (event.type == sf::Event::Closed)
			{
				bool _result = RenderClosing();
				if (_result)
					return exitSignal;
			}

			DefaultButtonColors();

			if (startIsSelected)
			{ // Game mode choices will be rendered.
				ShowGameModeChoices();
			}

			switch (event.type)
			{
			case sf::Event::MouseMoved:
				ControlMouseMoved();
				break;
			case sf::Event::MouseButtonPressed:
				result = ControlMousePressed();
				if( result!=noChange )
					return result; 
				break;
			case sf::Event::Closed:
				return exitSignal;
			default:
				break;
			}

			window->clear();
			drawBackground();

			window->draw(recButton_Exit);

			if (!startIsSelected)
			{ // Nothing is selected.
				window->draw(recButton_StartAGame);
				window->draw(text_StartAGame);
				window->draw(text_Exit);
			}
			else
			{ // Start is selected.
				window->draw(recButton_Scenario);
				window->draw(text_SelectAScenario);

				window->draw(recButton_Random);
				window->draw(text_RandomMatch);

				window->draw(recButton_Custom);
				window->draw(text_CustomMatch);

				window->draw(text_Back);
			}
			window->draw(recButton_English);
			window->draw(recButton_Turkish);
			window->draw(text_English);
			window->draw(text_Turkish);

			window->display();
		}

	}
}