#include "footballer.h"
#include <iostream> //cout icin

void Footballer::debug_f_galatasaray(int id)
{
	switch(id)
	{
		case 10100:
			name = L"Fernando"; surname = L"Muslera"; fullName = L"Néstor Fernando Muslera Micol"; birthYear = 1986;
			number=1;
			break; 
		case 10101:
			name = L"Aurélien"; surname = L"Chedjou"; fullName = L"Aurélien Bayard Chedjou Fongang"; birthYear = 1985;
			number=21;
			break; 
		case 10102:
			name = L"Hakan"; surname = L"Balta"; fullName = L"Hakan Kadir Balta"; usesFirstName=true; birthYear = 1983;
			number=22;
			break; 
		case 10103:
			name = L"Martin"; surname = L"Linnes"; birthYear = 1991;
			number=27;
			break; 
		case 10104:
			name = L"Lionel"; surname = L"Carole"; fullName = L"Lionel Jules Carole"; birthYear = 1991;
			number=23;
			break; 
		case 10105:
			name = L"Selçuk"; surname = L"Ýnan"; usesFirstName=true; birthYear = 1985;
			number=8;
			break; 
		case 10106:
			name = L"Ryan"; surname = L"Donk"; birthYear = 1994;
			number=15;
			break; 
		case 10107:
			name = L"Lukas"; surname = L"Podolski"; birthYear = 1985;
			number=11;
			break;
		case 10108:
			name = L"Wesley"; surname = L"Sneijder"; fullName = L"Wesley Benjamin Sneijder"; birthYear = 1983;
			number=10;
			break; 
		case 10109:
			name = L"Sinan"; surname = L"Gümüþ"; usesFirstName=true; birthYear = 1994;
			number=18;
			break; 
		case 10110:
			name = L"Burak"; surname = L"Yýlmaz"; usesFirstName=true; birthYear = 1985;
			number=17;
			break; 
		case 10111:
			name = L"Cenk"; surname = L"Gönen"; usesFirstName=true; birthYear = 1988;
			number=99;
			break; 
		case 10112:
			name = L"Semih"; surname = L"Kaya"; usesFirstName=true; birthYear = 1991;
			number=26;
			break; 
		case 10113: 
			name = L"Jason"; surname = L"Denayer"; birthYear = 1995;
			number=64;
			break; 
		//case 10114:
			//name = L"Jem"; surname = L"Karacan"; usesFirstName=true; fullName = L"Jem Paul Karacan"; birthYear = 1989;
			//number=6;
			//break; 
		case 10115:
			name = L"Bilal"; surname = L"Kýsa"; usesFirstName = true; birthYear = 1983;
			number=5;
			break; 
		case 10116:
			name = L"Emre"; surname = L"Çolak"; usesFirstName = true; birthYear = 1991;
			number=52;
			break; 
		case 10117:
			name = L"Umut"; surname = L"Bulut"; usesFirstName = true; birthYear = 1983;
			number=9;
			break; 
		case 10118:
			name = L"Koray"; surname = L"Günter"; usesFirstName = true; birthYear = 1994;
			number=28;
			break; 
		case 10119:
			name = L"Tarýk"; surname = L"Çamdal"; usesFirstName = true; fullName = L"Osman Tarýk Çamdal"; birthYear = 1991;
			number=38;
			break; 
		case 10120:
			name = L"Olcan"; surname = L"Adýn"; usesFirstName = true; birthYear = 1985;
			number=29;
			break; 
		case 10121:
			name = L"Hamit"; surname = L"Altýntop"; usesFirstName = true; birthYear = 1982;
			number=4;
			break; 
		case 10122:
			name = L"José"; surname = L"Rodríguez"; fullName = L"José Rodríguez Martínez"; birthYear = 1994;
			number=14;
			break; 
		case 10123:
			name = L"Yasin"; surname = L"Öztekin"; usesFirstName = true; birthYear = 1987;
			number=7;
			break; 
		default:
			name = L"GSName"; surname = L"GSSurname"; birthYear = 2016;
			number=0;
	}
}