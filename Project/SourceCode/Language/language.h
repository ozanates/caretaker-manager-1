#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <iostream>

using namespace std;

class Language
{
public:
	Language();
	bool isEnglish;
	bool init_Turkish();
	bool init_English();

	wstring GENERAL_0001; // "YES"
	wstring GENERAL_0002; // "NO"
	wstring GENERAL_0003; // "<- Back"
	wstring GENERAL_0004; // "Confirm"
	wstring GENERAL_0005; // "Left"
	wstring GENERAL_0006; // "Right"

	wstring CLOSINGSCREEN_001; // "Do you REALLY want to exit?"
	
	wstring MAINSCREEN_001; // "Start a Game"
	wstring MAINSCREEN_002; // "Options"
	wstring MAINSCREEN_003; // "Exit"
	
	wstring MAINSCREEN_005; // "Select a Scenario"
	wstring MAINSCREEN_006; // "Random Match"
	wstring MAINSCREEN_007; // "Custom Match"

	wstring TACTICTABS_0; // "Team Sheet"
	wstring TACTICTABS_1; // ""Formation"
	wstring TACTICTABS_2; // "Team Instructions"
	wstring TACTICTABS_3; // "Attacking Play"
	wstring TACTICTABS_4; // "Defending Play"
	wstring TACTICTABS_5; // "Player Instructions"
	wstring TACTICTABS_6; // "Player Roles"
	wstring TACTICTABS_7; // "Set Pieces"

	wstring INSTRUCTIONS_001_1; // "Defending mentality"
	wstring INSTRUCTIONS_001_2; // "Attacking mentality"
	wstring INSTRUCTIONS_002_1; // "Low defensive line"
	wstring INSTRUCTIONS_002_2; // "High defensive line"
	wstring INSTRUCTIONS_003_1; // "Narrow attacking play"
	wstring INSTRUCTIONS_003_2; // "Wide attacking play"
	wstring INSTRUCTIONS_004_1; // "Narrow defending play"
	wstring INSTRUCTIONS_004_2; // "Wide defending play"
	wstring INSTRUCTIONS_005; // "Free kick taker ("
	wstring INSTRUCTIONS_006; // "Corner kick taker ("
	wstring INSTRUCTIONS_007; // "Penalty taker"
	wstring INSTRUCTIONS_008; // "Select a player: "
	wstring INSTRUCTIONS_009_1; // "Take less shoot"
	wstring INSTRUCTIONS_009_2; // "Take more shoot"
	wstring INSTRUCTIONS_010_1; // "Dribble past less"
	wstring INSTRUCTIONS_010_2; // "Dribble past more"
	wstring INSTRUCTIONS_011_1; // "Dribble forward less"
	wstring INSTRUCTIONS_011_2; // "Dribble forward more"
	wstring INSTRUCTIONS_012_1; // "More simple passes"
	wstring INSTRUCTIONS_012_2; // "More risky passes"
	wstring INSTRUCTIONS_013_1; // "Cross the ball less"
	wstring INSTRUCTIONS_013_2; // "Cross the ball more"
	
	wstring TacticScreen_0001; // "STARTING ELEVEN" 
	wstring TacticScreen_0002; // "SUBSTITUTES"
	wstring TacticScreen_0003; // "RESERVES"

	wstring MATCHSCREEN_0001; // "START"
	wstring MATCHSCREEN_0002; // "PAUSE"
	wstring MATCHSCREEN_0003; // "CHANGE TACTICS"

	wstring COMMENTATOR_00001; // "And it's a throw in."
	wstring COMMENTATOR_00002; // "The match is under way."
	wstring COMMENTATOR_00003; // "The match starts again."
	wstring COMMENTATOR_00004; // "And it's a corner kick."
	wstring COMMENTATOR_00005; // "And it's a goal kick."
	wstring COMMENTATOR_00006; // "GOOOOOAAAAAAAAALLLLLLL!!!"

	wstring ACTION_00001; // " controls the pass."
	wstring ACTION_00002; // " plays simple pass."
	wstring ACTION_00003; // " is trying to pass the ball."
	wstring ACTION_00004; // " finds some space. He is dribbling forward." 
	wstring ACTION_00005; // " tries a long pass towards "
};

#endif