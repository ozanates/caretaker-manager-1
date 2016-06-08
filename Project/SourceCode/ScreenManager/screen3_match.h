#include "iScreen.h"

class MatchScreen : public iScreen
{
	bool paused;

	void InitializeScreen(); // Default values for drawables
	void InitializeStadium();
	void drawStadium();
	void drawScoreboard();
	void drawPanels();
	void drawButtons();
	void drawCommentator();

	// Drawable Positions
	sf::Vector2f panelPositions[3];

	// Drawables
	sf::Sprite footballPitch;
	sf::CircleShape sfBall;
	sf::CircleShape footballers0[11];
	sf::CircleShape footballers1[11];
	sf::CircleShape hand;
	sf::RectangleShape commentatorBackground;
	sf::Text commentatorText;

	// Button Rectangles
	sf::FloatRect startPause;
	sf::FloatRect changeTactics;

	// stadium definitions
	float MATCH_PLAYAREA_LEFT;
	float MATCH_PLAYAREA_TOP;
	float MATCH_CONST_W;
	float MATCH_CONST_H;

	bool ControlMousePressed(float,float);
	void ControlMouseMoved(float,float);

public:
	MatchScreen();
	MatchScreen(sf::RenderWindow* w, Game* g, Fonts* f, Stadium *s);
	e_Window Render();
};

#ifndef STYLE_MATCH
#define STYLE_MATCH

/* Styles for Match Screen
 *
 *
 *
 */

#include "style_general.h"


#define MATCH_PITCH_HEIGHT 631.11063f // 667.740535f // 0.85 * earlier height
#define MATCH_PITCH_WIDTH 947.53852f // 0.85 * earlier width
#define MATCH_PITCH_LEFT (1366-MATCH_PITCH_WIDTH)
#define MATCH_PITCH_TOP (768-MATCH_PITCH_HEIGHT-50)

#define PANEL_WIDTH 400
#define PANEL_HEIGHT 240

#endif