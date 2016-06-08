#include "fonts.h"

Fonts::Fonts()
{
	if (!button.loadFromFile(BookAntiqua))
		std::cout << "Error: Font file is missing: fonts/BKANT.ttf" << std::endl;

	if (!regular.loadFromFile(ArimoRegular))
		std::cout << "Error: Font file is missing. fonts/ArimoRegular.ttf" << std::endl;

	if (!wideRegular.loadFromFile(VeraMono))
		std::cout << "Error: Font file is missing. fonts/VeraMono.ttf" << std::endl;

	if (!narrowRegular.loadFromFile(AntonioRegular))
		std::cout << "Error: Font file is missing. fonts/Antonio.ttf" << std::endl;

	if (!scoreboard.loadFromFile(FontScoreboard))
		std::cout << "Error: Font file is missing. fonts/scoreboard.ttf" << std::endl;
}