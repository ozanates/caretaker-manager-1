#include "club.h"
#include "../Headers/clubIDs.h"
#include <iostream> //cout icin

void Club::init_c_manunited16()
{
	// CLUB PROPERTIES
	id = ID_MANUNITED16;
	fullName=L"Manchester United";
	shortName=L"MUFC";
	colorDark = sf::Color(140,11,14);
	colorLight = sf::Color(255,255,255);
	home_color0 = colorDark;
	home_color1 = colorLight;
	away_color0 = colorLight;
	away_color1 = sf::Color(30,30,30);

	subsSize = 7;
	squadSize = 27;
	reservesSize = squadSize-11-subsSize;

	// CLUB INSTRUCTIONS
	mentality=0.7;
	defensiveLine=0.7;

	defendingWidth=0.8;

	attackingWidth=0.9;
	buildUpSpeed_ownHalf=0.4;
	buildUpSpeed_oppositeHalf=0.5;

	taker_leftCornerKick=4; taker_rightCornerKick=4; taker_leftFreeKick=9; taker_rightFreeKick=7; taker_penalty=9;

	// CLUB SQUAD
	assignFootballer(lineUp[0],100200,Main_GK,Aligning_C); // De Gea
	lineUp[0]->set_tactical(0.1f,0.5f);
	lineUp[0]->set_defending(0.1f,0.5f);
	lineUp[0]->freq_shooting = 0.1; lineUp[0]->freq_dribblingPast = 0.1; lineUp[0]->freq_crossing = 0.1;
	lineUp[0]->freq_riskyPassing = 0.5; lineUp[0]->freq_dribblingForward = 0.2;

	assignFootballer(lineUp[1],100210,Main_D,Aligning_R); // Darmian
	lineUp[1]->set_tactical(0.35f,0.9f);
	lineUp[1]->set_defending(0.33f,0.9f);
	lineUp[1]->freq_shooting = 0.3; lineUp[1]->freq_dribblingPast = 0.3; lineUp[1]->freq_crossing = 0.5;
	lineUp[1]->freq_riskyPassing = 0.3; lineUp[1]->freq_dribblingForward = 0.5;

	assignFootballer(lineUp[2],100208,Main_D,Aligning_L); // Shaw
	lineUp[2]->set_tactical(0.37f,0.1f);
	lineUp[2]->set_defending(0.33f,0.1f);
	lineUp[2]->freq_shooting = 0.3; lineUp[2]->freq_dribblingPast = 0.6; lineUp[2]->freq_crossing = 0.5;
	lineUp[2]->freq_riskyPassing = 0.3; lineUp[2]->freq_dribblingForward = 0.7;

	assignFootballer(lineUp[3],100203,Main_D,Aligning_C); // Smalling
	lineUp[3]->set_tactical(0.29f,0.65f);
	lineUp[3]->set_defending(0.29f,0.65f);
	lineUp[3]->freq_shooting = 0.2; lineUp[3]->freq_dribblingPast = 0.3; lineUp[3]->freq_crossing = 0.2;
	lineUp[3]->freq_riskyPassing = 0.3; lineUp[3]->freq_dribblingForward = 0.4;

	assignFootballer(lineUp[4],100206,Main_D,Aligning_C); // Blind
	lineUp[4]->set_tactical(0.29f,0.35f);
	lineUp[4]->set_defending(0.29f,0.35f);
	lineUp[4]->freq_shooting = 0.4; lineUp[4]->freq_dribblingPast = 0.5; lineUp[4]->freq_crossing = 0.4;
	lineUp[4]->freq_riskyPassing = 0.6; lineUp[4]->freq_dribblingForward = 0.5;

	assignFootballer(lineUp[5],100214,Main_M,Aligning_C); // Carrick
	lineUp[5]->set_tactical(0.5f,0.65f);
	lineUp[5]->set_defending(0.5f,0.65f);
	lineUp[5]->freq_shooting = 0.4; lineUp[5]->freq_dribblingPast = 0.4; lineUp[5]->freq_crossing = 0.4;
	lineUp[5]->freq_riskyPassing = 0.9; lineUp[5]->freq_dribblingForward = 0.3;

	assignFootballer(lineUp[6],100213,Main_M,Aligning_C); // Schneiderlin
	lineUp[6]->set_tactical(0.5f,0.35f);
	lineUp[6]->set_defending(0.5f,0.35f);
	lineUp[6]->freq_shooting = 0.3; lineUp[6]->freq_dribblingPast = 0.3; lineUp[6]->freq_crossing = 0.4;
	lineUp[6]->freq_riskyPassing = 0.7; lineUp[6]->freq_dribblingForward = 0.3;

	assignFootballer(lineUp[7],100223,Main_AM,Aligning_R); // Mata
	lineUp[7]->set_tactical(0.6f,0.75f);
	lineUp[7]->set_defending(0.6f,0.88f);
	lineUp[7]->freq_shooting = 0.8; lineUp[7]->freq_dribblingPast = 0.6; lineUp[7]->freq_crossing = 0.7;
	lineUp[7]->freq_riskyPassing = 0.8; lineUp[7]->freq_dribblingForward = 0.4;
	
	assignFootballer(lineUp[8],100225,Main_AM,Aligning_L); // Martial
	lineUp[8]->set_tactical(0.62f,0.20f);
	lineUp[8]->set_defending(0.6f,0.12f);
	lineUp[8]->freq_shooting = 0.7; lineUp[8]->freq_dribblingPast = 0.7; lineUp[8]->freq_crossing = 0.5;
	lineUp[8]->freq_riskyPassing = 0.5; lineUp[8]->freq_dribblingForward = 0.8;

	assignFootballer(lineUp[9],100224,Main_AM,Aligning_C); // Rooney
	lineUp[9]->set_tactical(0.6f,0.4f);
	lineUp[9]->set_defending(0.62f,0.4f);
	lineUp[9]->freq_shooting = 0.7; lineUp[9]->freq_dribblingPast = 0.6; lineUp[9]->freq_crossing = 0.6;
	lineUp[9]->freq_riskyPassing = 0.8; lineUp[9]->freq_dribblingForward = 0.7;

	assignFootballer(lineUp[10],100226,Main_F,Aligning_C); // Rashford
	lineUp[10]->set_tactical(0.7f,0.52f);
	lineUp[10]->set_defending(0.7f,0.52f);
	lineUp[10]->freq_shooting = 0.7; lineUp[10]->freq_dribblingPast = 0.7; lineUp[10]->freq_crossing = 0.4;
	lineUp[10]->freq_riskyPassing = 0.3; lineUp[10]->freq_dribblingForward = 0.8;

	//subs = new SquadPosition[subsSize];
	assignFootballer(subs[0],100201,Main_SUB,Aligning_C); // Romero
	assignFootballer(subs[1],100204,Main_SUB,Aligning_C); // Rojo
	assignFootballer(subs[2],100202,Main_SUB,Aligning_C); // Fosu-Mensah
	assignFootballer(subs[3],100211,Main_SUB,Aligning_C); // Valencia
	assignFootballer(subs[4],100217,Main_SUB,Aligning_C); // Herrera
	assignFootballer(subs[5],100219,Main_SUB,Aligning_C); // Depay
	assignFootballer(subs[6],100222,Main_SUB,Aligning_C); // Lingard

	//reserves = new SquadPosition[reservesSize];
	assignFootballer(reserves[0],100205,Main_SUB,Aligning_C); // Jones
	assignFootballer(reserves[1],100207,Main_SUB,Aligning_C); // McNair
	assignFootballer(reserves[2],100209,Main_SUB,Aligning_C); // Borthwick
	assignFootballer(reserves[3],100212,Main_SUB,Aligning_C); // Varela
	assignFootballer(reserves[4],100215,Main_SUB,Aligning_C); // Fellaini
	assignFootballer(reserves[5],100218,Main_SUB,Aligning_C); // Perreira
	assignFootballer(reserves[6],100220,Main_SUB,Aligning_C); // Young
	assignFootballer(reserves[7],100221,Main_SUB,Aligning_C); // Januzaj
	assignFootballer(reserves[8],100216,Main_SUB,Aligning_C); // Schweinsteiger
}