#ifndef ENUM_H
#define ENUM_H

enum e_Window
{
	mainScreen,
	selectionScreen,
	tacticScreen,
	matchScreen,
	optionsScreen,
	noChange,
	exitSignal
};

enum e_GameType
{
	Scenario,
	CustomMatch,
	RandomMatch
};

enum e_Language
{
	TR,
	EN
};

enum TacticTab
{
	TeamSheet,
	Formation,
	TeamInstr,
	AttackingPlay,
	DefendingPlay,
	PlayerInstr,
	PlayerRoles,
	SetPieces
};

enum e_matchState
{
	kickoff,
	openPlay,
	goalKick,
	cornerKick,
	cornerKickPlay,
	freeKick,
	freeKickPlay,
	throwIn,
	end
};

#endif