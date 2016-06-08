#include "language.h"

bool Language::init_Turkish()
{
	if(!isEnglish) return false;
	isEnglish=false;

	GENERAL_0001 = L"Evet";
	GENERAL_0002 = L"Hay�r";
	GENERAL_0003 = L"<- Geri";
	GENERAL_0004 = L"Onayla";
	GENERAL_0005 = L"Sol";
	GENERAL_0006 = L"Sa�";

	CLOSINGSCREEN_001 = L"GER�EKTEN ��kmak istiyor musun?";

	MAINSCREEN_001 = L"Oyuna Ba�la";
	MAINSCREEN_002 = L"Se�enekler";
	MAINSCREEN_003 = L"��k��";
	
	MAINSCREEN_005 = L"Senaryo Se�";
	MAINSCREEN_006 = L"Rastgele Ma�";
	MAINSCREEN_007 = L"Ma� Ayarla";

	TACTICTABS_0 = L"Esame Listesi",
	TACTICTABS_1 = L"Dizili�",
	TACTICTABS_2 = L"Tak�m Komutlar�",
	TACTICTABS_3 = L"H�cum Oyunu",
	TACTICTABS_4 = L"Savunma Oyunu",
	TACTICTABS_5 = L"Futbolcu Komutlar�",
	TACTICTABS_6 = L"Futbolcu Rolleri",
	TACTICTABS_7 = L"Duran Toplar";

	INSTRUCTIONS_001_1 = L"Defansif anlay��";
	INSTRUCTIONS_001_2 = L"Ofansif anlay��";
	INSTRUCTIONS_002_1 = L"Defans �izgisi geride";
	INSTRUCTIONS_002_2 = L"Defans �izgisi ileride";
	INSTRUCTIONS_003_1 = L"Dar h�cum oyunu";
	INSTRUCTIONS_003_2 = L"Geni� h�cum oyunu";
	INSTRUCTIONS_004_1 = L"Dar savunma oyunu";
	INSTRUCTIONS_004_2 = L"Geni� savunma oyunu";
	INSTRUCTIONS_005 = L"Frikikleri kullanan (";
	INSTRUCTIONS_006 = L"Kornerleri kullanan (";
	INSTRUCTIONS_007 = L"Penalt�lar� kullanan";
	INSTRUCTIONS_008 = L"Bir futbolcu se�:";
	INSTRUCTIONS_009_1 = L"Az �ut �ek";
	INSTRUCTIONS_009_2 = L"�ok �ut �ek";
	INSTRUCTIONS_010_1 = L"Az �al�m dene";
	INSTRUCTIONS_010_2 = L"�ok �al�m dene";
	INSTRUCTIONS_011_1 = L"Topu ileri daha az s�r";
	INSTRUCTIONS_011_2 = L"Topu ileri daha �ok s�r";
	INSTRUCTIONS_012_1 = L"Basit paslar dene";
	INSTRUCTIONS_012_2 = L"Riskli paslar dene";
	INSTRUCTIONS_013_1 = L"Az orta yap";
	INSTRUCTIONS_013_2 = L"�ok orta yap";

	TacticScreen_0001 = L"�LK ON B�R";
	TacticScreen_0002 = L"YEDEKLER";
	TacticScreen_0003 = L"KADRO DI�I";

	MATCHSCREEN_0001 = L"BA�LAT";
	MATCHSCREEN_0002 = L"DURAKLAT";
	MATCHSCREEN_0003 = L"TAKT�K DE���T�R";

	COMMENTATOR_00001 = L"Top taca ��kt�.";
	COMMENTATOR_00002 = L"Ve ma� ba�l�yor.";
	COMMENTATOR_00003 = L"Ve ma� tekrar ba�lad�.";
	COMMENTATOR_00004 = L"Ve top d��ar�da. Korner!";
	COMMENTATOR_00005 = L"Ve top auta gidiyor.";
	COMMENTATOR_00006 = L"GOOOOOOOOOOOLLLLLLL!!!";

	ACTION_00001 = L" gelen pas� kontrol etmeye �al���yor.";
	ACTION_00002 = L" k�sa pas�n� att�.";
	ACTION_00003 = L" tak�m arkada��n� g�rd�.";
	ACTION_00004 = L" bo�luk yakalad�. Topu ileri s�r�yor."; 
	ACTION_00005 = L" uzun bir pas deniyor. Hedefi ";

	return true;
};