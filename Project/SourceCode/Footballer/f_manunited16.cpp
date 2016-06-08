#include "footballer.h"
//#include <iostream>

void Footballer::init_f_manunited16(int id)
{
	switch(id)
	{ 
		case 100200:
			name = L"David"; surname = L"de Gea"; birthYear = 1990; number=1;
			shortPassing=70; longPassing=60; firstTouch=55; dribbling=30; // TECHNIQUE
			maximumSpeed=65; acceleration=70; agility=80; reaction=70; // PHYSICAL
			tacticalDiscipline=60; concentration=90; // MENTAL
			attackingPositioning=55; passingVision=60; // MENTAL ATTACKING
			break; 
		case 100201:
			name = L"Sergio"; surname = L"Romero"; birthYear = 1987; number=20;
			shortPassing=65; longPassing=55; firstTouch=50; dribbling=25; // TECHNIQUE
			maximumSpeed=65; acceleration=63; agility=70; reaction=70; // PHYSICAL
			tacticalDiscipline=50; concentration=70; // MENTAL
			attackingPositioning=50; passingVision=55; // MENTAL ATTACKING
			break; 
		case 100202:
			name = L"Timothy"; surname = L"Fosu-Mensah"; fullName = L"Evans Timothy Fosu Fosu-Mensah"; birthYear = 1993; number=51;
			shortPassing=65; longPassing=55; firstTouch=70; dribbling=62; // TECHNIQUE
			maximumSpeed=75; acceleration=70; agility=65; reaction=70; // PHYSICAL
			tacticalDiscipline=66; concentration=70; // MENTAL
			attackingPositioning=65; passingVision=60; // MENTAL ATTACKING
			break; 
		case 100203:
			name = L"Chris"; surname = L"Smalling"; birthYear = 1989; number=12;
			shortPassing=70; longPassing=55; firstTouch=60; dribbling=55; // TECHNIQUE
			maximumSpeed=80; acceleration=65; agility=60; reaction=70; // PHYSICAL
			tacticalDiscipline=70; concentration=75; // MENTAL
			attackingPositioning=55; passingVision=50; // MENTAL ATTACKING
			break; 
		case 100204:
			name = L"Marcos"; surname = L"Rojo"; birthYear = 1990; number=5;
			shortPassing=70; longPassing=65; firstTouch=60; dribbling=60; // TECHNIQUE
			maximumSpeed=73; acceleration=70; agility=68; reaction=70; // PHYSICAL
			tacticalDiscipline=68; concentration=68; // MENTAL
			attackingPositioning=60; passingVision=60; // MENTAL ATTACKING
			break; 
		case 100205:
			name = L"Phil"; surname = L"Jones"; birthYear = 1992; number=4;
			shortPassing=75; longPassing=62; firstTouch=60; dribbling=60; // TECHNIQUE
			maximumSpeed=77; acceleration=75; agility=68; reaction=70; // PHYSICAL
			tacticalDiscipline=73; concentration=82; // MENTAL
			attackingPositioning=65; passingVision=60; // MENTAL ATTACKING
			break; 
		case 100206:
			name = L"Daley"; surname = L"Blind"; birthYear = 1990; number=17;
			shortPassing=80; longPassing=75; firstTouch=75; dribbling=65; // TECHNIQUE
			maximumSpeed=70; acceleration=65; agility=70; reaction=80; // PHYSICAL
			tacticalDiscipline=80; concentration=75; // MENTAL
			attackingPositioning=70; passingVision=75; // MENTAL ATTACKING
			break; 
		case 100207:
			name = L"Patrick"; surname = L"McNair"; birthYear = 1995; number=33;
			shortPassing=65; longPassing=60; firstTouch=63; dribbling=58; // TECHNIQUE
			maximumSpeed=68; acceleration=67; agility=62; reaction=70; // PHYSICAL
			tacticalDiscipline=68; concentration=72; // MENTAL
			attackingPositioning=60; passingVision=60; // MENTAL ATTACKING
			break;
		case 100208:
			name = L"Luke"; surname = L"Shaw"; birthYear = 1995; number=23;
			shortPassing=75; longPassing=60; firstTouch=70;dribbling=75; // TECHNIQUE
			maximumSpeed=80; acceleration=80; agility=70; reaction=80; // PHYSICAL
			tacticalDiscipline=70; concentration=70; // MENTAL
			attackingPositioning=70; passingVision=60; // MENTAL ATTACKING
			break; 
		case 100209:
			name = L"Cameron"; surname = L"Borthwick-Jackson"; birthYear = 1997; number=43;
			shortPassing=65; longPassing=55; firstTouch=70; dribbling=62; // TECHNIQUE
			maximumSpeed=75; acceleration=70; agility=65; reaction=70; // PHYSICAL
			tacticalDiscipline=66; concentration=70; // MENTAL
			attackingPositioning=65; passingVision=60; // MENTAL ATTACKING
			break; 
		case 100210:
			name = L"Matteo"; surname = L"Darmian"; birthYear = 1989; number=36;
			shortPassing=75; longPassing=60; firstTouch=70; dribbling=70; // TECHNIQUE
			maximumSpeed=70; acceleration=70; agility=75; reaction=75; // PHYSICAL
			tacticalDiscipline=75; concentration=75; // MENTAL
			attackingPositioning=60; passingVision=60; // MENTAL ATTACKING
			break; 
		case 100211:
			name = L"Antonio"; surname = L"Valencia"; birthYear = 1985; number=25;
			shortPassing=65; longPassing=58; firstTouch=68; dribbling=71; // TECHNIQUE
			maximumSpeed=85; acceleration=82; agility=77; reaction=70; // PHYSICAL
			tacticalDiscipline=69; concentration=70; // MENTAL
			attackingPositioning=65; passingVision=58; // MENTAL ATTACKING
			break; 
		case 100212:
			name = L"Guillermo"; surname = L"Varela"; birthYear = 1993; number=30;
			shortPassing=64; longPassing=55; firstTouch=68; dribbling=70; // TECHNIQUE
			maximumSpeed=80; acceleration=78; agility=75; reaction=70; // PHYSICAL
			tacticalDiscipline=72; concentration=70; // MENTAL
			attackingPositioning=67; passingVision=62; // MENTAL ATTACKING
			break; 
		case 100213: 
			name = L"Morgan"; surname = L"Schneiderlin"; birthYear = 1989; number=28;
			shortPassing=80; longPassing=70; firstTouch=70; dribbling=60; // TECHNIQUE
			maximumSpeed=70; acceleration=60; agility=70; reaction=75; // PHYSICAL
			tacticalDiscipline=80; concentration=80; // MENTAL
			attackingPositioning=65; passingVision=75; // MENTAL ATTACKING
			break; 
		case 100214:
			name = L"Michael"; surname = L"Carrick"; birthYear = 1981; number=16;
			shortPassing=84; longPassing=80; firstTouch=80; dribbling=55; // TECHNIQUE
			maximumSpeed=60; acceleration=50; agility=55; reaction=65; // PHYSICAL
			tacticalDiscipline=75; concentration=85; // MENTAL
			attackingPositioning=65; passingVision=85; // MENTAL ATTACKING
			break; 
		case 100215:
			name = L"Marouane"; surname = L"Fellaini"; birthYear = 1987; number=27;
			shortPassing=72; longPassing=60; firstTouch=65; dribbling=55; // TECHNIQUE
			maximumSpeed=55; acceleration=50; agility=52; reaction=65; // PHYSICAL
			tacticalDiscipline=72; concentration=75; // MENTAL
			attackingPositioning=75; passingVision=50; // MENTAL ATTACKING
			break;
		case 100216:
			name = L"Bastian"; surname = L"Schweinsteiger"; birthYear = 1984; number=31;
			shortPassing=80; longPassing=78; firstTouch=77; dribbling=69; // TECHNIQUE
			maximumSpeed=54; acceleration=52; agility=50; reaction=70; // PHYSICAL
			tacticalDiscipline=82; concentration=85; // MENTAL
			attackingPositioning=73; passingVision=85; // MENTAL ATTACKING
			break; 
		case 100217:
			name = L"Ander"; surname = L"Herrera"; birthYear = 1989; number=21;
			shortPassing=77; longPassing=68; firstTouch=79; dribbling=73; // TECHNIQUE
			maximumSpeed=67; acceleration=72; agility=71; reaction=70; // PHYSICAL
			tacticalDiscipline=75; concentration=77; // MENTAL
			attackingPositioning=75; passingVision=79; // MENTAL ATTACKING
			break; 
		case 100218:
			name = L"Andreas"; surname = L"Perreira"; birthYear = 1996;	number=44;
			shortPassing=76; longPassing=72; firstTouch=78; dribbling=74; // TECHNIQUE
			maximumSpeed=68; acceleration=68; agility=73; reaction=70; // PHYSICAL
			tacticalDiscipline=68; concentration=70; // MENTAL
			attackingPositioning=72; passingVision=78; // MENTAL ATTACKING
			break; 
		case 100219:
			name = L"Memphis"; surname = L"Depay"; birthYear = 1994; number=7;
			shortPassing=77; longPassing=65; firstTouch=77; dribbling=84; // TECHNIQUE
			maximumSpeed=78; acceleration=80; agility=77; reaction=72; // PHYSICAL
			tacticalDiscipline=70; concentration=68; // MENTAL
			attackingPositioning=72; passingVision=79; // MENTAL ATTACKING
			break; 
		case 100220:
			name = L"Ashley"; surname = L"Young"; birthYear = 1985; number=18;
			shortPassing=75; longPassing=71; firstTouch=70; dribbling=71; // TECHNIQUE
			maximumSpeed=79; acceleration=82; agility=78; reaction=70; // PHYSICAL
			tacticalDiscipline=75; concentration=78; // MENTAL
			attackingPositioning=70; passingVision=68; // MENTAL ATTACKING
			break; 
		case 100221:
			name = L"Adnan"; surname = L"Januzaj"; birthYear = 1995; number=11;
			shortPassing=75; longPassing=70; firstTouch=72; dribbling=79; // TECHNIQUE
			maximumSpeed=78; acceleration=75; agility=74; reaction=70; // PHYSICAL
			tacticalDiscipline=71; concentration=65; // MENTAL
			attackingPositioning=71; passingVision=79; // MENTAL ATTACKING
			break; 
		case 100222:
			name = L"Jesse"; surname = L"Lingard"; birthYear = 1992; number=35;
			shortPassing=75; longPassing=60; firstTouch=75; dribbling=75; // TECHNIQUE
			maximumSpeed=75; acceleration=75; agility=80; reaction=80; // PHYSICAL
			tacticalDiscipline=65; concentration=70; // MENTAL
			attackingPositioning=75; passingVision=70; // MENTAL ATTACKING
			break; 
		case 100223:
			name = L"Juan"; surname = L"Mata"; birthYear = 1988; number=8;
			shortPassing=90; longPassing=70; firstTouch=80; dribbling=85; // TECHNIQUE
			maximumSpeed=60; acceleration=75; agility=80; reaction=75; // PHYSICAL
			tacticalDiscipline=70; concentration=75; // MENTAL
			attackingPositioning=75; passingVision=80; // MENTAL ATTACKING
			break; 
		case 100224:
			name = L"Wayne"; surname = L"Rooney"; birthYear = 1985; number=10;
			shortPassing=85; longPassing=80; firstTouch=75; dribbling=70; // TECHNIQUE
			maximumSpeed=65; acceleration=75; agility=75; reaction=70; // PHYSICAL
			tacticalDiscipline=75; concentration=80; // MENTAL
			attackingPositioning=80; passingVision=75; // MENTAL ATTACKING
			break; 
		case 100225:
			name = L"Anthony"; surname = L"Martial"; birthYear = 1995; number=9;
			shortPassing=70; longPassing=55; firstTouch=75; dribbling=85; // TECHNIQUE
			maximumSpeed=80; acceleration=85; agility=80; reaction=80; // PHYSICAL
			tacticalDiscipline=70; concentration=70; // MENTAL
			attackingPositioning=75; passingVision=65; // MENTAL ATTACKING
			break; 
		case 100226:
			name = L"Marcus"; surname = L"Rashford"; birthYear = 1997; number=39;
			shortPassing=70; longPassing=50; firstTouch=70; dribbling=77; // TECHNIQUE
			maximumSpeed=80; acceleration=80; agility=75; reaction=75; // PHYSICAL
			tacticalDiscipline=60; concentration=65; // MENTAL
			attackingPositioning=70; passingVision=60; // MENTAL ATTACKING
			break; 
		default:
			name = L"MUFC16Name"; surname = L"MUFC16Surname"; birthYear = 2016;	number=0;
			default_skills();
			break;
	}
}