#include "iScreen.h"

class MainScreen : public iScreen
{
	int x,y; //for handling mouse
	bool startIsSelected;
	sf::Text text_StartAGame, text_Options, text_Exit, text_SelectAScenario, text_CustomMatch, text_RandomMatch;
	sf::Text text_Exit_AreYouSure, text_Exit_Yes, text_Exit_No, text_Back;
	sf::Text text_English, text_Turkish;
	
	sf::RectangleShape recButton_StartAGame, recButton_Options, recButton_Exit;
	sf::RectangleShape recButton_Scenario, recButton_Random, recButton_Custom;
	sf::RectangleShape recButton_English, recButton_Turkish;

	void ControlMouseMoved();
	e_Window ControlMousePressed();

	void InitializeScreen(); // Default values for drawables
	void UpdateStrings();

	void DefaultButtonColors(); // Default color values for buttons
	void ShowGameModeChoices(); // Show game mode choices in the menu.
public:
	MainScreen(sf::RenderWindow* w, Game* g, Fonts* f, Stadium* s);
	e_Window Render();
};

#ifndef STYLE_MAIN
#define STYLE_MAIN

#include "style_general.h"

///// MAIN SCREEN - Main Buttons

#define BUTTON_MAIN_STARTAGAME_TOP (268*SCALE_V)				// Vertical position of button "Start a Game"
#define BUTTON_MAIN_OPTIONS_TOP (418*SCALE_V)					// Vertical position of button "Options"
#define BUTTON_MAIN_EXIT_TOP (568*SCALE_V)						// Vertical position of button "Exit"

///// MAIN SCREEN - Side Buttons

#define BUTTON_MAIN_SCENARIO_TOP (318*SCALE_V)
#define BUTTON_MAIN_RANDOM_TOP (468*SCALE_V)
#define BUTTON_MAIN_CUSTOM_TOP (618*SCALE_V)

#define BUTTON_MAIN_EXIT_AREYOUSURE_TOP (468*SCALE_V)
#define BUTTON_MAIN_EXIT_YESNO_WIDTH (150*SCALE_H)
#define BUTTON_MAIN_EXIT_YESNO_HEIGHT (100*SCALE_V)
#define BUTTON_MAIN_EXIT_YESNO_TOP (618*SCALE_V)
#define BUTTON_MAIN_EXIT_YES_LEFT (783*SCALE_H)	
#define BUTTON_MAIN_EXIT_NO_LEFT (983*SCALE_H)	

#define BUTTON_MAIN_SECOND_LEFT (783*SCALE_H)					// Horizontal position of side buttons
#define BUTTON_MAIN_SECOND_WIDTH (400*SCALE_H)					// Width of side buttons
#define BUTTON_MAIN_SECOND_HEIGHT (80*SCALE_V)					// Height of side buttons

#define BUTTON_LANG_LEFT (1200*SCALE_H)
#define BUTTON_LANG_EN_TOP (10*SCALE_V)
#define BUTTON_LANG_TR_TOP (70*SCALE_V)
#define BUTTON_LANG_WIDTH (150*SCALE_H)
#define BUTTON_LANG_HEIGHT (50*SCALE_H)

#endif