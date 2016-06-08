#include "footballer.h"

void Footballer::debug_f_fenerbahce(int id)
{
	switch(id)
	{
		case 10200:
			name = L"Volkan"; surname = L"Demirel"; birthYear = 1981;
			break; 
		case 10201:
			name = L"Fabiano"; surname = L"Ribeiro"; fullName = L"Fabiano Ribeiro de Freitas"; birthYear = 1988;
			break; 
		case 10202:
			name = L"Simon"; surname = L"Kjær"; fullName = L"Simon Thorup Kjær"; birthYear = 1989;
			break; 
		case 10203:
			name = L"Bruno"; surname = L"Alves"; fullName = L"Bruno Eduardo Regufe Alves"; birthYear = 1981;
			break; 
		case 10204:
			name = L"Abdoulaye"; surname = L"Ba"; birthYear = 1991;
			break; 
		case 10205:
			name = L"Michal"; surname = L"Kadlec"; birthYear = 1984;
			break; 
		case 10206: 
			name = L"Hasan Ali"; surname = L"Kaldırım"; birthYear = 1989;
			break; 
		case 10207:
			name = L"Şener"; surname = L"Özbayraklı"; birthYear = 1990;
			break; 
		case 10208:
			name = L"Gökhan"; surname = L"Gönül"; birthYear = 1985;
			break; 
		case 10209:
			name = L"Caner"; surname = L"Erkin"; birthYear = 1988;
			break; 
		case 10210:
			name = L"Mehmet"; surname = L"Topal"; birthYear = 1986;
			break; 
		case 10211:
			name = L"Josef"; surname = L"de Souza"; fullName = L"Josef de Souza Dias"; birthYear = 1989;
			break; 
		case 10212:
			name = L"Ozan"; surname = L"Tufan"; birthYear = 1995;
			break; 
		case 10213:
			name = L"Raul"; surname = L"Meireles"; fullName = L"Raul José Trindade Meireles"; birthYear = 1983;
			break; 
		case 10214:
			name = L"Mehmet"; surname = L"Topuz"; birthYear = 1983;
			break; 
		case 10215:
			name = L"Diego"; surname = L"Ribas"; fullName = L"Diego Ribas da Cunha"; birthYear = 1985;
			break; 
		case 10216:
			name = L"Lazar"; surname = L"Marković L"; birthYear = 1994;
			break; 
		case 10217:
			name = L"Luis"; surname = L"Nani"; fullName = L"Luís Carlos Almeida da Cunha"; hasNickname = true; nickname = L"Nani"; birthYear = 1986;
			break; 
		case 10218:
			name = L"Alper"; surname = L"Potuk"; birthYear = 1991;
			break; 
		case 10219:
			name = L"Volkan"; surname = L"Şen"; birthYear = 1987;
			break; 
		case 10220:
			name = L"Fernando"; surname = L"Viana"; fullName = L"José Fernando Viana de Santana"; hasNickname = true; nickname = L"Fernandão"; birthYear = 1987;
			break; 
		case 10221:
			name = L"Robin"; surname = L"van Persie"; birthYear = 1983;
			break;
		default:
			name = L"Name"; surname = L"Surname"; fullName = L"Full Name"; nickname = L"Nickname"; birthYear = 0;
		}
}