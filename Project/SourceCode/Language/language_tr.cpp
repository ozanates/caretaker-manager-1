#include "language.h"

bool Language::init_Turkish()
{
	if(!isEnglish) return false;
	isEnglish=false;

	GENERAL_0001 = L"Evet";
	GENERAL_0002 = L"Hayýr";
	GENERAL_0003 = L"<- Geri";
	GENERAL_0004 = L"Onayla";
	GENERAL_0005 = L"Sol";
	GENERAL_0006 = L"Sað";

	CLOSINGSCREEN_001 = L"GERÇEKTEN çýkmak istiyor musun?";

	MAINSCREEN_001 = L"Oyuna Baþla";
	MAINSCREEN_002 = L"Seçenekler";
	MAINSCREEN_003 = L"Çýkýþ";
	
	MAINSCREEN_005 = L"Senaryo Seç";
	MAINSCREEN_006 = L"Rastgele Maç";
	MAINSCREEN_007 = L"Maç Ayarla";

	TACTICTABS_0 = L"Esame Listesi",
	TACTICTABS_1 = L"Diziliþ",
	TACTICTABS_2 = L"Takým Komutlarý",
	TACTICTABS_3 = L"Hücum Oyunu",
	TACTICTABS_4 = L"Savunma Oyunu",
	TACTICTABS_5 = L"Futbolcu Komutlarý",
	TACTICTABS_6 = L"Futbolcu Rolleri",
	TACTICTABS_7 = L"Duran Toplar";

	INSTRUCTIONS_001_1 = L"Defansif anlayýþ";
	INSTRUCTIONS_001_2 = L"Ofansif anlayýþ";
	INSTRUCTIONS_002_1 = L"Defans çizgisi geride";
	INSTRUCTIONS_002_2 = L"Defans çizgisi ileride";
	INSTRUCTIONS_003_1 = L"Dar hücum oyunu";
	INSTRUCTIONS_003_2 = L"Geniþ hücum oyunu";
	INSTRUCTIONS_004_1 = L"Dar savunma oyunu";
	INSTRUCTIONS_004_2 = L"Geniþ savunma oyunu";
	INSTRUCTIONS_005 = L"Frikikleri kullanan (";
	INSTRUCTIONS_006 = L"Kornerleri kullanan (";
	INSTRUCTIONS_007 = L"Penaltýlarý kullanan";
	INSTRUCTIONS_008 = L"Bir futbolcu seç:";
	INSTRUCTIONS_009_1 = L"Az þut çek";
	INSTRUCTIONS_009_2 = L"Çok þut çek";
	INSTRUCTIONS_010_1 = L"Az çalým dene";
	INSTRUCTIONS_010_2 = L"Çok çalým dene";
	INSTRUCTIONS_011_1 = L"Topu ileri daha az sür";
	INSTRUCTIONS_011_2 = L"Topu ileri daha çok sür";
	INSTRUCTIONS_012_1 = L"Basit paslar dene";
	INSTRUCTIONS_012_2 = L"Riskli paslar dene";
	INSTRUCTIONS_013_1 = L"Az orta yap";
	INSTRUCTIONS_013_2 = L"Çok orta yap";

	TacticScreen_0001 = L"ÝLK ON BÝR";
	TacticScreen_0002 = L"YEDEKLER";
	TacticScreen_0003 = L"KADRO DIÞI";

	MATCHSCREEN_0001 = L"BAÞLAT";
	MATCHSCREEN_0002 = L"DURAKLAT";
	MATCHSCREEN_0003 = L"TAKTÝK DEÐÝÞTÝR";

	COMMENTATOR_00001 = L"Top taca çýktý.";
	COMMENTATOR_00002 = L"Ve maç baþlýyor.";
	COMMENTATOR_00003 = L"Ve maç tekrar baþladý.";
	COMMENTATOR_00004 = L"Ve top dýþarýda. Korner!";
	COMMENTATOR_00005 = L"Ve top auta gidiyor.";
	COMMENTATOR_00006 = L"GOOOOOOOOOOOLLLLLLL!!!";

	ACTION_00001 = L" gelen pasý kontrol etmeye çalýþýyor.";
	ACTION_00002 = L" kýsa pasýný attý.";
	ACTION_00003 = L" takým arkadaþýný gördü.";
	ACTION_00004 = L" boþluk yakaladý. Topu ileri sürüyor."; 
	ACTION_00005 = L" uzun bir pas deniyor. Hedefi ";

	return true;
};