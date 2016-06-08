#include "language.h"

bool Language::init_English()
{
	if(isEnglish) return false;
	isEnglish=true;

	GENERAL_0001 = L"Yes";
	GENERAL_0002 = L"No";
	GENERAL_0003 = L"<- Back";
	GENERAL_0004 = L"Confirm";
	GENERAL_0005 = L"Left";
	GENERAL_0006 = L"Right";

	CLOSINGSCREEN_001 = L"Do you REALLY want to exit?";

	MAINSCREEN_001 = L"Start a Game";
	MAINSCREEN_002 = L"Options";
	MAINSCREEN_003 = L"Exit";

	MAINSCREEN_005 = L"Select a Scenario";
	MAINSCREEN_006 = L"Random Match";
	MAINSCREEN_007 = L"Custom Match";

	TACTICTABS_0 = L"Team Sheet",
	TACTICTABS_1 = L"Formation",
	TACTICTABS_2 = L"Team Instructions",
	TACTICTABS_3 = L"Attacking Play",
	TACTICTABS_4 = L"Defending Play",
	TACTICTABS_5 = L"Player Instructions",
	TACTICTABS_6 = L"Player Roles",
	TACTICTABS_7 = L"Set Pieces";

	INSTRUCTIONS_001_1 = L"Defensive mentality";
	INSTRUCTIONS_001_2 = L"Attacking mentality";
	INSTRUCTIONS_002_1 = L"Low defensive line";
	INSTRUCTIONS_002_2 = L"High defensive line";
	INSTRUCTIONS_003_1 = L"Narrow attacking play";
	INSTRUCTIONS_003_2 = L"Wide attacking play";
	INSTRUCTIONS_004_1 = L"Narrow defending play";
	INSTRUCTIONS_004_2 = L"Wide defending play";
	INSTRUCTIONS_005 = L"Free kick taker (";
	INSTRUCTIONS_006 = L"Corner kick taker (";
	INSTRUCTIONS_007 = L"Penalty taker";
	INSTRUCTIONS_008 = L"Select a player:";
	INSTRUCTIONS_009_1 = L"Take less shoot";
	INSTRUCTIONS_009_2 = L"Take more shoot";
	INSTRUCTIONS_010_1 = L"Dribble past less";
	INSTRUCTIONS_010_2 = L"Dribble past more";
	INSTRUCTIONS_011_1 = L"Dribble forward less";
	INSTRUCTIONS_011_2 = L"Dribble forward more";
	INSTRUCTIONS_012_1 = L"More simple passes";
	INSTRUCTIONS_012_2 = L"More risky passes";
	INSTRUCTIONS_013_1 = L"Cross the ball less";
	INSTRUCTIONS_013_2 = L"Cross the ball more";

	TacticScreen_0001 = L"STARTING ELEVEN";
	TacticScreen_0002 = L"SUBSTITUTES";
	TacticScreen_0003 = L"RESERVES";

	MATCHSCREEN_0001 = L"START";
	MATCHSCREEN_0002 = L"PAUSE";
	MATCHSCREEN_0003 = L"CHANGE TACTICS";

	COMMENTATOR_00001 = L"And it's a throw in.";
	COMMENTATOR_00002 = L"The match is under way.";
	COMMENTATOR_00003 = L"The match starts again.";
	COMMENTATOR_00004 = L"And it's a corner kick.";
	COMMENTATOR_00005 = L"And it's a goal kick.";
	COMMENTATOR_00006 = L"GOOOOOAAAAAAAAALLLLLLL!!!";

	ACTION_00001 = L" controls the pass.";
	ACTION_00002 = L" plays simple pass.";
	ACTION_00003 = L" is trying to pass the ball.";
	ACTION_00004 = L" finds some space. He is dribbling forward."; 
	ACTION_00005 = L" tries a long pass towards ";

	return true;
};