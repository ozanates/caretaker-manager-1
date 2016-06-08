#ifndef GAME_H
#define GAME_H

#include "Club/club.h"
#include "Headers/enum.h"

class Game
{
public:
	e_Window currentScreen;
	e_GameType currentGameType;
	Language* language;
	Game(Language* lang);
	~Game();
};

#endif