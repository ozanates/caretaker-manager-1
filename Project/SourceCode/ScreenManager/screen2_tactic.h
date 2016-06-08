#include "iScreen.h"
//#include <memory>

#define SIZE_TEAMINSTR1 2
#define SIZE_ATTINSTR1 1
#define SIZE_DEFINSTR1 1
#define SIZE_PLAYERINSTR1 5

class Instruction{ 
public: 
	wstring descr1, descr2; float* value; sf::Vector2f position; sf::FloatRect minus; sf::FloatRect plus;
	Instruction(){};
	Instruction(sf::Vector2f p);
	Instruction(float* v, sf::Vector2f p);
	void changeName(wstring w1, wstring w2);
	void changeValue(float* val);
};

class TacticScreen : public iScreen
{
	int x,y; //for handling mouse
	sf::FloatRect fr; // for handling bounding rectangles of entitites
	wstring wstring_TacticTabs[8];

	// Drawables
	void initalizeGraphics();
	sf::Text text_TacticTabs[8];
	sf::Text text_Confirm, text_Back;
	sf::RectangleShape recButton_Confirm, recButton_Back;

	sf::Sprite sprite_circlebutton;
	sf::Texture tex_circlebutton;
	sf::Sprite sprite_minus;
	sf::Texture tex_minus;
	sf::Sprite sprite_plus;
	sf::Texture tex_plus;
	sf::Sprite sprite_leftArrow;
	sf::Texture tex_leftArrow;
	sf::Sprite sprite_rightArrow;
	sf::Texture tex_rightArrow;

	// Instructions
	void initializeInstructions();
	Instruction teamInstructions1[SIZE_TEAMINSTR1];
	Instruction attInstructions1[SIZE_ATTINSTR1];
	Instruction defInstructions1[SIZE_DEFINSTR1];
	Instruction playerInstructions1[SIZE_PLAYERINSTR1];
	sf::FloatRect clickCircles_setPieces[10];
	sf::FloatRect clickCircle_playerInstr[2];

	int selectedTacticTab;
	bool teamsheet_isFootballerSelected;
	SquadPosition* teamsheet_selectedSquadPosition;
	bool formation_isFootballerSelected;
	SquadPosition* formation_selectedSquadPosition;
	bool isShiftPressed;

	void InitializeScreen(); // Default values for drawables
	void UpdateStrings();
	void DrawScreen(); // Changing drawables and drawing them

	void DefaultButtonColors(); // Default color values for buttons
	void ShowProfile(Footballer *f);
	bool SwapSquadPositions(SquadPosition* s1, SquadPosition* s2);

	// DRAWING PANELS
	void drawBars(float left, float top, wstring descr1, wstring descr2, float value);
	void drawHeader();
	void drawTacticsPanel();
	void drawTacticsPanel_TeamSheet();
	void drawTacticsPanel_Formation();
	void drawTacticsPanel_TeamInstr();
	void drawTacticsPanel_AttackingPlay();
	void drawTacticsPanel_DefendingPlay();
	void drawTacticsPanel_SetPieces();
	void drawTacticsPanel_PlayerInstructions();
	int selectedPlayer_instruction;
	void update_playerInstructions();

	// HANDLING INPUTS
	void HandleMouseMoved(float x, float y);
	void HandleKeyPressed();
	void HandleKeyReleased();
	void HandleMouseLeftReleased(float x, float y);
	e_Window HandleMouseLeftPressed(float x, float y);

public:
	TacticScreen(sf::RenderWindow* w, Game* g, Fonts* f, Stadium* s);
	e_Window Render();

};

#ifndef STYLE_TACTIC
#define STYLE_TACTIC

#include "style_general.h"

#define TacticTabsSize 8

///// TACTIC SCREEN - Buttons

#define BUTTON_TACTIC_SIDE_WIDTH (200*SCALE_H)
#define BUTTON_TACTIC_SIDE_HEIGHT (50*SCALE_V)

#define BUTTON_TACTIC_SIDE_LEFT (50*SCALE_H)
#define BUTTON_TACTIC_TABS_TOP (100*SCALE_V)
#define BUTTON_TACTIC_CONFIRM_TOP (590*SCALE_V)
#define BUTTON_TACTIC_BACK_TOP (670*SCALE_V)

#define TEXT_TACTIC_SIDEBUTTON_SIZE (20*SCALE_V)
#define TEXT_TACTIC_SIDEBUTTON_LEFTMARGIN ((BUTTON_TACTIC_SIDE_HEIGHT - TEXT_TACTIC_SIDEBUTTON_SIZE)*SCALE_H/2)
#define TEXT_TACTIC_SIDEBUTTON_GAP_V (5*SCALE_V)

///// TACTIC PANEL

#define TACTIC_PANEL_TOP (BUTTON_TACTIC_TABS_TOP*SCALE_V)
#define TACTIC_PANEL_LEFT ((BUTTON_TACTIC_SIDE_LEFT + BUTTON_TACTIC_SIDE_WIDTH + 15)*SCALE_H)
#define TACTIC_PANEL_WIDTH ((1300*SCALE_H)-TACTIC_PANEL_LEFT)
#define TACTIC_PANEL_HEIGHT (BUTTON_TACTIC_BACK_TOP+BUTTON_TACTIC_SIDE_HEIGHT-BUTTON_TACTIC_TABS_TOP)

#define TACTIC_PANEL_BACKCOLOR sf::Color::Color(240,250,230,200) // old color sf::Color::Color(240,250,230,100)

///// TACTIC SCREEN - Team Sheet

#define TEXT_TACTIC_TEAMSHEET_TEAMNAMESIZE (14*SCALE_V)
#define TEXT_TACTIC_TEAMSHEET_FOOTBALLERNAMESIZE (13*SCALE_V)

#define TEXT_TACTIC_TEAMSHEET_lineUp_TOP (TACTIC_PANEL_TOP+12*SCALE_V)
#define TEXT_TACTIC_TEAMSHEET_SUBS_TOP (TEXT_TACTIC_TEAMSHEET_lineUp_TOP+TEXT_TACTIC_TEAMSHEET_TEAMNAMESIZE+10+11*(TEXT_TACTIC_TEAMSHEET_FOOTBALLERNAMESIZE+5)+10*SCALE_V)
#define TEXT_TACTIC_TEAMSHEET_RESERVES_TOP (TEXT_TACTIC_TEAMSHEET_SUBS_TOP+TEXT_TACTIC_TEAMSHEET_TEAMNAMESIZE+10+7*(TEXT_TACTIC_TEAMSHEET_FOOTBALLERNAMESIZE+5)+10*SCALE_V)

#define TACTIC_TEAMSHEET_NUMBER_LEFT (TACTIC_PANEL_LEFT+12*SCALE_H) // TACTIC_TEAMSHEET_NO_LEFT
#define TACTIC_TEAMSHEET_NAME_LEFT (TACTIC_TEAMSHEET_NUMBER_LEFT+30*SCALE_H)
#define TACTIC_TEAMSHEET_POSITION_LEFT (TACTIC_TEAMSHEET_NAME_LEFT+250*SCALE_H) //burayi degistirdim

#define TACTIC_TEAMSHEET_PROFILE_LEFT (TACTIC_TEAMSHEET_POSITION_LEFT+200*SCALE_H)
#define TACTIC_TEAMSHEET_PROFILE_TOP (TACTIC_PANEL_TOP+30*SCALE_V)
#define TACTIC_TEAMSHEET_PROFILE_WIDTH (TACTIC_PANEL_WIDTH-(TACTIC_TEAMSHEET_PROFILE_LEFT-TACTIC_PANEL_LEFT)-25)
#define TACTIC_TEAMSHEET_PROFILE_HEIGHT (TACTIC_PANEL_HEIGHT-50*SCALE_V)
#define TACTIC_TEAMSHEET_BACKCOLOR sf::Color::Color(210,220,200,230)

///// TACTIC SCREEN - Formation

#define TACTIC_FORMATION_LEFT (TACTIC_PANEL_LEFT+60*SCALE_H)
#define TACTIC_FORMATION_RIGHT (TACTIC_PANEL_LEFT+TACTIC_PANEL_WIDTH-60*SCALE_H)
#define TACTIC_FORMATION_TOP (TACTIC_PANEL_TOP+70*SCALE_V)
#define TACTIC_FORMATION_BOTTOM (TACTIC_PANEL_TOP+TACTIC_PANEL_HEIGHT-70*SCALE_V)
#define TACTIC_FORMATION_WIDTH (TACTIC_FORMATION_RIGHT-TACTIC_FORMATION_LEFT)
#define TACTIC_FORMATION_HEIGHT (TACTIC_FORMATION_BOTTOM-TACTIC_FORMATION_TOP)

#define FORMATION_CIRCLE_SIZE 15
#define FORMATION_CIRCLE_OUTLINESIZE 8

///// TACTIC SCREEN - Bars

#define MINUS_LEFT 140
#define BAR_LEFT 163
#define PLUS_LEFT 240
#define BAR_WIDTH 5
#define BAR_HEIGHT 13
#define BAR_NEXT 7
#define SECOND_DESCR 270

#define INSTR_FIRSTLEFT TACTIC_PANEL_LEFT+10
#define INSTR_SECONDLEFT TACTIC_PANEL_LEFT+500

///// TACTIC SCREEN - Team Instructions

#define INSTR_FIRSTTOP TACTIC_PANEL_TOP+10

///// TACTIC SCREEN - Attacking Play

#define ATTACKINGWIDTH INSTR_FIRSTTOP

///// TACTIC SCREEN - Defending Play

#define DEFENDINGWIDTH INSTR_FIRSTTOP

///// 

#define LEFTARROW_PLACE 180
#define RIGHTARROW_PLACE 340

#endif