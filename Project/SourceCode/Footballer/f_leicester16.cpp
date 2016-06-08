#include "footballer.h"
//#include <iostream> //cout icin

void Footballer::init_f_leicester16(int id)
{
	switch(id)
	{ 
		case 100100:
			name = L"Kasper"; surname = L"Schmeichel"; birthYear = 1986; number=1;
			shortPassing=65; longPassing=55; firstTouch=50; dribbling=30; // TECHNIQUE
			maximumSpeed=65; acceleration=70; agility=60; reaction=65; // PHYSICAL
			tacticalDiscipline=60; concentration=85; // MENTAL
			attackingPositioning=30; passingVision=55; // MENTAL ATTACKING
			break; 
		case 100101:
			name = L"Mark"; surname = L"Schwarzer"; birthYear = 1972; number=32;
			shortPassing=60; longPassing=52; firstTouch=48; dribbling=30; // TECHNIQUE
			maximumSpeed=48; acceleration=50; agility=49; reaction=65; // PHYSICAL
			tacticalDiscipline=60; concentration=82; // MENTAL
			attackingPositioning=30; passingVision=55; // MENTAL ATTACKING
			break; 
		case 100102:
			name = L"Ben"; surname = L"Hamer"; birthYear = 1987; number=12;
			shortPassing=60; longPassing=52; firstTouch=48; dribbling=30; // TECHNIQUE
			maximumSpeed=48; acceleration=50; agility=49; reaction=65; // PHYSICAL
			tacticalDiscipline=60; concentration=82; // MENTAL
			attackingPositioning=30; passingVision=55; // MENTAL ATTACKING
			break; 
		case 100103:
			name = L"Christian"; surname = L"Fuchs"; birthYear = 1986; number=28;
			shortPassing=75; longPassing=70; firstTouch=70; dribbling=55; // TECHNIQUE
			maximumSpeed=65; acceleration=60; agility=65; reaction=75; // PHYSICAL
			tacticalDiscipline=65; concentration=80; // MENTAL
			attackingPositioning=70; passingVision=65; // MENTAL ATTACKING
			break; 
		case 100104:
			name = L"Robert"; surname = L"Huth"; birthYear = 1984; number=6;
			shortPassing=65; longPassing=55; firstTouch=55; dribbling=45; // TECHNIQUE
			maximumSpeed=50; acceleration=50; agility=40; reaction=65; // PHYSICAL
			tacticalDiscipline=80; concentration=90; // MENTAL
			attackingPositioning=50; passingVision=50; // MENTAL ATTACKING
			break; 
		case 100105:
			name = L"Wes"; surname = L"Morgan"; birthYear = 1984; number=5;
			shortPassing=65; longPassing=55; firstTouch=60; dribbling=50; // TECHNIQUE
			maximumSpeed=50; acceleration=50; agility=50; reaction=65; // PHYSICAL
			tacticalDiscipline=80; concentration=85; // MENTAL
			attackingPositioning=55; passingVision=55; // MENTAL ATTACKING
			break; 
		case 100106:
			name = L"Danny"; surname = L"Simpson"; birthYear = 1987; number=17;
			shortPassing=70; longPassing=60; firstTouch=65; dribbling=63; // TECHNIQUE
			maximumSpeed=80; acceleration=75; agility=60; reaction=75; // PHYSICAL
			tacticalDiscipline=60; concentration=70; // MENTAL
			attackingPositioning=60; passingVision=55; // MENTAL ATTACKING
			break; 
		case 100107:
			name = L"Liam"; surname = L"Moore"; birthYear = 1993; number=18;
			shortPassing=63; longPassing=55; firstTouch=59; dribbling=55; // TECHNIQUE
			maximumSpeed=57; acceleration=59; agility=55; reaction=62; // PHYSICAL
			tacticalDiscipline=67; concentration=70; // MENTAL
			attackingPositioning=55; passingVision=55; // MENTAL ATTACKING
			break;
		case 100108:
			name = L"Marcin"; surname = L"Wasilewski"; birthYear = 1980; number=27;
			shortPassing=63; longPassing=55; firstTouch=59; dribbling=55; // TECHNIQUE
			maximumSpeed=48; acceleration=51; agility=48; reaction=62; // PHYSICAL
			tacticalDiscipline=78; concentration=80; // MENTAL
			attackingPositioning=55; passingVision=55; // MENTAL ATTACKING
			break; 
		case 100109:
			name = L"Jeffrey"; surname = L"Schlupp"; birthYear = 1992; number=18;
			shortPassing=62; longPassing=55; firstTouch=66; dribbling=72; // TECHNIQUE
			maximumSpeed=78; acceleration=70; agility=65; reaction=64; // PHYSICAL
			tacticalDiscipline=62; concentration=61; // MENTAL
			attackingPositioning=61; passingVision=54; // MENTAL ATTACKING
			break; 
		case 100110:
			name = L"N'Golo"; surname = L"Kanté"; birthYear = 1991;	number=14;
			shortPassing=75; longPassing=60; firstTouch=75; dribbling=65; // TECHNIQUE
			maximumSpeed=80; acceleration=85; agility=80; reaction=80; // PHYSICAL
			tacticalDiscipline=80; concentration=90; // MENTAL
			attackingPositioning=70; passingVision=70; // MENTAL ATTACKING
			break; 
		case 100111:
			name = L"Danny"; surname = L"Drinkwater"; birthYear = 1988;	number=4;
			shortPassing=80; longPassing=70; firstTouch=80; dribbling=55; // TECHNIQUE
			maximumSpeed=65; acceleration=70; agility=70; reaction=75; // PHYSICAL
			tacticalDiscipline=90; concentration=90; // MENTAL
			attackingPositioning=75; passingVision=80; // MENTAL ATTACKING
			break; 
		case 100112:
			name = L"Marc"; surname = L"Albrighton"; birthYear = 1989; number=11;
			shortPassing=75; longPassing=75; firstTouch=80; dribbling=65; // TECHNIQUE
			maximumSpeed=70; acceleration=70; agility=70; reaction=75; // PHYSICAL
			tacticalDiscipline=80; concentration=75; // MENTAL
			attackingPositioning=70; passingVision=65; // MENTAL ATTACKING
			break; 
		case 100113: 
			name = L"Riyad"; surname = L"Mahrez"; birthYear = 1991; number=26;
			shortPassing=80; longPassing=65; firstTouch=75; dribbling=90; // TECHNIQUE
			maximumSpeed=70; acceleration=75; agility=80; reaction=75; // PHYSICAL
			tacticalDiscipline=70; concentration=70; // MENTAL
			attackingPositioning=75; passingVision=75; // MENTAL ATTACKING
			break; 
		case 100114:
			name = L"Daniel"; surname = L"Amartey"; birthYear = 1994; number=21;
			shortPassing=70; longPassing=60; firstTouch=71; dribbling=65; // TECHNIQUE
			maximumSpeed=78; acceleration=82; agility=80; reaction=80; // PHYSICAL
			tacticalDiscipline=75; concentration=78; // MENTAL
			attackingPositioning=67; passingVision=65; // MENTAL ATTACKING
			break; 
		case 100115:
			name = L"Gökhan"; surname = L"Ýnler"; birthYear = 1984; number=33;
			shortPassing=76; longPassing=74; firstTouch=73; dribbling=67; // TECHNIQUE
			maximumSpeed=60; acceleration=62; agility=63; reaction=70; // PHYSICAL
			tacticalDiscipline=72; concentration=74; // MENTAL
			attackingPositioning=70; passingVision=76; // MENTAL ATTACKING
			break;
		case 100116:
			name = L"Andy"; surname = L"King"; birthYear = 1988; number=10;
			shortPassing=72; longPassing=70; firstTouch=68; dribbling=62; // TECHNIQUE
			maximumSpeed=63; acceleration=63; agility=66; reaction=70; // PHYSICAL
			tacticalDiscipline=72; concentration=74; // MENTAL
			attackingPositioning=77; passingVision=72; // MENTAL ATTACKING
			break; 
		case 100117:
			name = L"Matty"; surname = L"James"; birthYear = 1991; number=8;
			shortPassing=77; longPassing=75; firstTouch=68; dribbling=62; // TECHNIQUE
			maximumSpeed=63; acceleration=63; agility=66; reaction=70; // PHYSICAL
			tacticalDiscipline=68; concentration=70; // MENTAL
			attackingPositioning=68; passingVision=78; // MENTAL ATTACKING
			break; 
		case 100118:
			name = L"Demarai"; surname = L"Gray"; birthYear = 1996;	number=22;
			shortPassing=68; longPassing=62; firstTouch=65; dribbling=81; // TECHNIQUE
			maximumSpeed=80; acceleration=80; agility=72; reaction=70; // PHYSICAL
			tacticalDiscipline=62; concentration=65; // MENTAL
			attackingPositioning=63; passingVision=65; // MENTAL ATTACKING
			break; 
		case 100119:
			name = L"Nathan"; surname = L"Dyer"; birthYear = 1987; number=24;
			shortPassing=65; longPassing=60; firstTouch=62; dribbling=78; // TECHNIQUE
			maximumSpeed=85; acceleration=82; agility=77; reaction=72; // PHYSICAL
			tacticalDiscipline=67; concentration=69; // MENTAL
			attackingPositioning=67; passingVision=65; // MENTAL ATTACKING
			break; 
		case 100120:
			name = L"Shinji"; surname = L"Okazaki"; birthYear = 1986; number=20;
			shortPassing=75; longPassing=60; firstTouch=75; dribbling=65; // TECHNIQUE
			maximumSpeed=65; acceleration=70; agility=80; reaction=80; // PHYSICAL
			tacticalDiscipline=90; concentration=80; // MENTAL
			attackingPositioning=80; passingVision=75; // MENTAL ATTACKING
			break; 
		case 100121:
			name = L"Jamie"; surname = L"Vardy"; birthYear = 1987; number=9;
			shortPassing=75; longPassing=60; firstTouch=75; dribbling=72; // TECHNIQUE
			maximumSpeed=85; acceleration=80; agility=70; reaction=80; // PHYSICAL
			tacticalDiscipline=75; concentration=85;  // MENTAL
			attackingPositioning=80; passingVision=70; // MENTAL ATTACKING
			break; 
		case 100122:
			name = L"Leonardo"; surname = L"Ulloa"; birthYear = 1986; number=23;
			shortPassing=68; longPassing=60; firstTouch=70; dribbling=65; // TECHNIQUE
			maximumSpeed=63; acceleration=59; agility=61; reaction=69; // PHYSICAL
			tacticalDiscipline=72; concentration=75; // MENTAL
			attackingPositioning=80; passingVision=70; // MENTAL ATTACKING
			break; 
		default:
			name = L"LCFC16Name"; surname = L"LCFC16Surname"; birthYear = 2016;	number=0;
			default_skills();
			break;
	}
}