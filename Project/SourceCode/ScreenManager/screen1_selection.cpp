#include "screen1_selection.h"

SelectionScreen::SelectionScreen(sf::RenderWindow* w, Game* g, Fonts* f, Stadium *s):iScreen(w,g,f,s)
{
}

e_Window SelectionScreen::Render()
{
	return tacticScreen;
}