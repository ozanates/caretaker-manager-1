#include "iScreen.h"

class SelectionScreen : public iScreen
{
public:
	SelectionScreen();
	SelectionScreen(sf::RenderWindow* w, Game* g, Fonts* f, Stadium *s);
	e_Window Render();
};