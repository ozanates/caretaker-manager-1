#include "club.h"
#include "../Headers/clubIDs.h"
#include <iostream> //cout icin

void Club::init_c_leicester16()
{
	// CLUB PROPERTIES
	id = ID_LEICESTER16;
	fullName=L"Leicester City";
	shortName=L"LCFC";
	colorDark = sf::Color(10,30,150);
	colorLight = sf::Color(255,255,255);
	home_color0 = colorDark;
	home_color1 = colorLight;
	away_color0 = colorLight;
	away_color1 = colorDark;

	subsSize = 7;
	squadSize = 23;
	reservesSize = squadSize-11-subsSize;

	// CLUB INSTRUCTIONS
	mentality=0.4;
	defensiveLine=0.5;

	defendingWidth=0.6;

	attackingWidth=0.7;
	buildUpSpeed_ownHalf=0.6;
	buildUpSpeed_oppositeHalf=0.8;

	taker_leftCornerKick=7; taker_rightCornerKick=7; taker_leftFreeKick=7; taker_rightFreeKick=7; taker_penalty=10;

	// CLUB SQUAD
	assignFootballer(lineUp[0],100100,Main_GK,Aligning_C); // Schmeichel
	lineUp[0]->set_tactical(0.1f,0.5f);
	lineUp[0]->set_defending(0.1f,0.5f);
	lineUp[0]->freq_shooting = 0.1; lineUp[0]->freq_dribblingPast = 0.1; lineUp[0]->freq_crossing = 0.1;
	lineUp[0]->freq_riskyPassing = 0.3; lineUp[0]->freq_dribblingForward = 0.2;

	assignFootballer(lineUp[1],100106,Main_D,Aligning_R); // Simpson
	lineUp[1]->set_tactical(0.3f,0.9f);
	lineUp[1]->set_defending(0.3f,0.9f);
	lineUp[1]->freq_shooting = 0.3; lineUp[1]->freq_dribblingPast = 0.5; lineUp[1]->freq_crossing = 0.5;
	lineUp[1]->freq_riskyPassing = 0.3; lineUp[1]->freq_dribblingForward = 0.7;

	assignFootballer(lineUp[2],100105,Main_D,Aligning_C); // Morgan
	lineUp[2]->set_tactical(0.26f,0.65f);
	lineUp[2]->set_defending(0.26f,0.65f);
	lineUp[2]->freq_shooting = 0.2; lineUp[2]->freq_dribblingPast = 0.3; lineUp[2]->freq_crossing = 0.2;
	lineUp[2]->freq_riskyPassing = 0.3; lineUp[2]->freq_dribblingForward = 0.4;

	assignFootballer(lineUp[3],100104,Main_D,Aligning_C); // Huth
	lineUp[3]->set_tactical(0.26f,0.35f);
	lineUp[3]->set_defending(0.26f,0.35f);
	lineUp[3]->freq_shooting = 0.2; lineUp[3]->freq_dribblingPast = 0.2; lineUp[3]->freq_crossing = 0.1;
	lineUp[3]->freq_riskyPassing = 0.3; lineUp[3]->freq_dribblingForward = 0.2;

	assignFootballer(lineUp[4],100103,Main_D,Aligning_L); // Fuchs
	lineUp[4]->set_tactical(0.3f,0.1f);
	lineUp[4]->set_defending(0.3f,0.1f);
	lineUp[4]->freq_shooting = 0.5; lineUp[4]->freq_dribblingPast = 0.4; lineUp[4]->freq_crossing = 0.8;
	lineUp[4]->freq_riskyPassing = 0.6; lineUp[4]->freq_dribblingForward = 0.5;

	assignFootballer(lineUp[5],100110,Main_M,Aligning_C); // Kante
	lineUp[5]->set_tactical(0.45f,0.65f);
	lineUp[5]->set_defending(0.45f,0.65f);
	lineUp[5]->freq_shooting = 0.5; lineUp[5]->freq_dribblingPast = 0.5; lineUp[5]->freq_crossing = 0.3;
	lineUp[5]->freq_riskyPassing = 0.5; lineUp[5]->freq_dribblingForward = 0.8;

	assignFootballer(lineUp[6],100111,Main_M,Aligning_C); // Drinkwater
	lineUp[6]->set_tactical(0.45f,0.35f);
	lineUp[6]->set_defending(0.45f,0.35f);
	lineUp[6]->freq_shooting = 0.5; lineUp[6]->freq_dribblingPast = 0.4; lineUp[6]->freq_crossing = 0.5;
	lineUp[6]->freq_riskyPassing = 0.8; lineUp[6]->freq_dribblingForward = 0.7;

	assignFootballer(lineUp[7],100113,Main_M,Aligning_R); // Mahrez
	lineUp[7]->set_tactical(0.5f,0.9f);
	lineUp[7]->set_defending(0.5f,0.9f);
	lineUp[7]->freq_shooting = 0.6; lineUp[7]->freq_dribblingPast = 0.8; lineUp[7]->freq_crossing = 0.7;
	lineUp[7]->freq_riskyPassing = 0.7; lineUp[7]->freq_dribblingForward = 0.8;

	assignFootballer(lineUp[8],100120,Main_F,Aligning_C); // Okazaki
	lineUp[8]->set_tactical(0.7f,0.4f);
	lineUp[8]->set_defending(0.6f,0.47f);
	lineUp[8]->freq_shooting = 0.6; lineUp[8]->freq_dribblingPast = 0.5; lineUp[8]->freq_crossing = 0.5;
	lineUp[8]->freq_riskyPassing = 0.5; lineUp[8]->freq_dribblingForward = 0.6;

	assignFootballer(lineUp[9],100112,Main_M,Aligning_L); // Albrighton
	lineUp[9]->set_tactical(0.5f,0.1f);
	lineUp[9]->set_defending(0.5f,0.1f);
	lineUp[9]->freq_shooting = 0.4; lineUp[9]->freq_dribblingPast = 0.4; lineUp[9]->freq_crossing = 0.8;
	lineUp[9]->freq_riskyPassing = 0.7; lineUp[9]->freq_dribblingForward = 0.5;

	assignFootballer(lineUp[10],100121,Main_F,Aligning_C); // Vardy
	lineUp[10]->set_tactical(0.7f,0.6f);
	lineUp[10]->set_defending(0.7f,0.52f);
	lineUp[10]->freq_shooting = 0.7; lineUp[10]->freq_dribblingPast = 0.6; lineUp[10]->freq_crossing = 0.5;
	lineUp[10]->freq_riskyPassing = 0.5; lineUp[10]->freq_dribblingForward = 0.8;

	//subs = new SquadPosition[subsSize];
	assignFootballer(subs[0],100101,Main_SUB,Aligning_C); // Schwarzer
	assignFootballer(subs[1],100108,Main_SUB,Aligning_C); // Wasilewski
	assignFootballer(subs[2],100109,Main_SUB,Aligning_C); // Schlupp
	assignFootballer(subs[3],100116,Main_SUB,Aligning_C); // King
	assignFootballer(subs[4],100114,Main_SUB,Aligning_C); // Amartey
	assignFootballer(subs[5],100118,Main_SUB,Aligning_C); // Gray
	assignFootballer(subs[6],100122,Main_SUB,Aligning_C); // Ulloa

	//reserves = new SquadPosition[reservesSize];
	assignFootballer(reserves[0],100102,Main_SUB,Aligning_C); // Hamer
	assignFootballer(reserves[1],100107,Main_SUB,Aligning_C); // Moore
	assignFootballer(reserves[2],100115,Main_SUB,Aligning_C); // Gökhan
	assignFootballer(reserves[3],100119,Main_SUB,Aligning_C); // Dyer
	assignFootballer(reserves[4],100117,Main_SUB,Aligning_C); // James

}