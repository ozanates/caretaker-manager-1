#include "screen2_tactic.h"

Instruction::Instruction(sf::Vector2f p):position(p)
{
	minus = sf::FloatRect(p.x+MINUS_LEFT,p.y,20,20);
	plus = sf::FloatRect(p.x+PLUS_LEFT,p.y,20,20);
}

Instruction::Instruction(float* v, sf::Vector2f p):value(v),position(p)
{
	minus = sf::FloatRect(p.x+MINUS_LEFT,p.y,20,20);
	plus = sf::FloatRect(p.x+PLUS_LEFT,p.y,20,20);
}; 

void Instruction::changeName(wstring w1, wstring w2){descr1=w1; descr2=w2;};
void Instruction::changeValue(float* val){value=val;};

TacticScreen::TacticScreen(sf::RenderWindow* w, Game* g, Fonts* f, Stadium* s) : iScreen(w,g,f,s)
{
	selectedTacticTab = TeamSheet;
	game->currentScreen = tacticScreen;
	teamsheet_isFootballerSelected = false;
	formation_isFootballerSelected = false;

	wstring_TacticTabs[0] = L"Team Sheet",
	wstring_TacticTabs[1] = L"Formation",
	wstring_TacticTabs[2] = L"Team Instructions",
	wstring_TacticTabs[3] = L"Attacking Play",
	wstring_TacticTabs[4] = L"Defending Play",
	wstring_TacticTabs[5] = L"Player Instructions",
	wstring_TacticTabs[6] = L"Player Roles",
	wstring_TacticTabs[7] = L"Set Pieces";

	isShiftPressed=false;
	selectedPlayer_instruction=0;

	initalizeGraphics();
	initializeInstructions();
}

void TacticScreen::UpdateStrings()
{
	wstring_TacticTabs[0] = langstrings->TACTICTABS_0;
	wstring_TacticTabs[1] = langstrings->TACTICTABS_1;
	wstring_TacticTabs[2] = langstrings->TACTICTABS_2;
	wstring_TacticTabs[3] = langstrings->TACTICTABS_3;
	wstring_TacticTabs[4] = langstrings->TACTICTABS_4;
	wstring_TacticTabs[5] = langstrings->TACTICTABS_5;
	wstring_TacticTabs[6] = langstrings->TACTICTABS_6;
	wstring_TacticTabs[7] = langstrings->TACTICTABS_7;

	teamInstructions1[0].changeName(langstrings->INSTRUCTIONS_001_1,langstrings->INSTRUCTIONS_001_2);
	teamInstructions1[1].changeName(langstrings->INSTRUCTIONS_002_1,langstrings->INSTRUCTIONS_002_2);

	attInstructions1[0].changeName(langstrings->INSTRUCTIONS_003_1,langstrings->INSTRUCTIONS_003_2);

	defInstructions1[0].changeName(langstrings->INSTRUCTIONS_004_1,langstrings->INSTRUCTIONS_004_2);

	playerInstructions1[0].changeName(langstrings->INSTRUCTIONS_009_1,langstrings->INSTRUCTIONS_009_2);
	playerInstructions1[1].changeName(langstrings->INSTRUCTIONS_010_1,langstrings->INSTRUCTIONS_010_2);
	playerInstructions1[2].changeName(langstrings->INSTRUCTIONS_011_1,langstrings->INSTRUCTIONS_011_2);
	playerInstructions1[3].changeName(langstrings->INSTRUCTIONS_012_1,langstrings->INSTRUCTIONS_012_2);
	playerInstructions1[4].changeName(langstrings->INSTRUCTIONS_013_1,langstrings->INSTRUCTIONS_013_2);
};

void TacticScreen::initalizeGraphics()
{
	// Circle button sign
	if (!tex_circlebutton.loadFromFile(LOCATION_CIRCLEBUTTON))
	{
		std::cout << "Error: Circle button image could not be loaded from file." << std::endl;	
	}
	tex_circlebutton.setSmooth(true);
	sprite_circlebutton.setScale(0.7,0.7);
	sprite_circlebutton.setTexture(tex_circlebutton);

	// Minus sign
	if(!tex_minus.loadFromFile(LOCATION_MINUS))
	{
		std::cout << "Error: Minus image could not be loaded from file." << std::endl;	
	}
	tex_minus.setSmooth(true);
	sprite_minus.setScale(0.7,0.7);
	sprite_minus.setTexture(tex_minus);

	// Plus sign
	if(!tex_plus.loadFromFile(LOCATION_PLUS))
	{
		std::cout << "Error: Plus image could not be loaded from file." << std::endl;	
	}
	tex_plus.setSmooth(true);
	sprite_plus.setScale(0.7,0.7);
	sprite_plus.setTexture(tex_plus);

	// Left arrow sign
	if(!tex_leftArrow.loadFromFile(LOCATION_LEFTARROW))
	{
		std::cout << "Error: Left arrow image could not be loaded from file." << std::endl;	
	}
	tex_leftArrow.setSmooth(true);
	sprite_leftArrow.setScale(0.7,0.7);
	sprite_leftArrow.setTexture(tex_leftArrow);

	// Right arrow sign
	if(!tex_rightArrow.loadFromFile(LOCATION_RIGHTARROW))
	{
		std::cout << "Error: Left arrow image could not be loaded from file." << std::endl;	
	}
	tex_rightArrow.setSmooth(true);
	sprite_rightArrow.setScale(0.7,0.7);
	sprite_rightArrow.setTexture(tex_rightArrow);

	for (int i=0; i<3; i++)
	{
		clickCircles_setPieces[0+i*4] = sf::FloatRect(INSTR_FIRSTLEFT+LEFTARROW_PLACE,INSTR_FIRSTTOP+i*30,20,20);
		clickCircles_setPieces[1+i*4] = sf::FloatRect(INSTR_FIRSTLEFT+RIGHTARROW_PLACE,INSTR_FIRSTTOP+i*30,20,20);
		if (i<2)
		{
			clickCircles_setPieces[2+i*4] = sf::FloatRect(INSTR_SECONDLEFT+LEFTARROW_PLACE,INSTR_FIRSTTOP+i*30,20,20);
			clickCircles_setPieces[3+i*4] = sf::FloatRect(INSTR_SECONDLEFT+RIGHTARROW_PLACE,INSTR_FIRSTTOP+i*30,20,20);
		}
	}

	clickCircle_playerInstr[0] = sf::FloatRect(600+LEFTARROW_PLACE,INSTR_FIRSTTOP,20,20);
	clickCircle_playerInstr[1] = sf::FloatRect(600+RIGHTARROW_PLACE,INSTR_FIRSTTOP,20,20);
}

void TacticScreen::initializeInstructions()
{
	teamInstructions1[0] = Instruction(&stadium->club0->mentality,sf::Vector2f(INSTR_FIRSTLEFT,INSTR_FIRSTTOP));
	teamInstructions1[1] = Instruction(&stadium->club0->defensiveLine,sf::Vector2f(INSTR_FIRSTLEFT,INSTR_FIRSTTOP+30));

	attInstructions1[0] = Instruction(&stadium->club0->attackingWidth,sf::Vector2f(INSTR_FIRSTLEFT,INSTR_FIRSTTOP));

	defInstructions1[0] = Instruction(&stadium->club0->defendingWidth,sf::Vector2f(INSTR_FIRSTLEFT,INSTR_FIRSTTOP));

	playerInstructions1[0] = Instruction(sf::Vector2f(INSTR_FIRSTLEFT,INSTR_FIRSTTOP+30));
	playerInstructions1[1] = Instruction(sf::Vector2f(INSTR_FIRSTLEFT,INSTR_FIRSTTOP+60));
	playerInstructions1[2] = Instruction(sf::Vector2f(INSTR_FIRSTLEFT,INSTR_FIRSTTOP+90));
	playerInstructions1[3] = Instruction(sf::Vector2f(INSTR_FIRSTLEFT,INSTR_FIRSTTOP+120));
	playerInstructions1[4] = Instruction(sf::Vector2f(INSTR_FIRSTLEFT,INSTR_FIRSTTOP+150));
	update_playerInstructions();
}

void TacticScreen::update_playerInstructions()
{
	SquadPosition* player = stadium->club0->lineUp[selectedPlayer_instruction];
	playerInstructions1[0].changeValue(&player->freq_shooting);
	playerInstructions1[1].changeValue(&player->freq_dribblingPast);
	playerInstructions1[2].changeValue(&player->freq_dribblingForward);
	playerInstructions1[3].changeValue(&player->freq_riskyPassing);
	playerInstructions1[4].changeValue(&player->freq_crossing);
};

void TacticScreen::drawBars(float left, float top, wstring descr1, wstring descr2, float value)
{
	// Draw description
	drawText(descr1, fonts->regular, BAR_HEIGHT, sf::Text::Regular, left, top, sf::Color::Black);
	drawText(descr2, fonts->regular, BAR_HEIGHT, sf::Text::Regular, left+SECOND_DESCR, top, sf::Color::Black);

	// Draw minus and plus signs
	sprite_circlebutton.setPosition(left+MINUS_LEFT,top);
	sprite_circlebutton.setColor(sf::Color::Black);
	window->draw(sprite_circlebutton);
	sprite_minus.setPosition(left+MINUS_LEFT,top);
	window->draw(sprite_minus);

	sprite_circlebutton.setPosition(left+PLUS_LEFT,top);
	window->draw(sprite_circlebutton);
	sprite_plus.setPosition(left+PLUS_LEFT,top);
	window->draw(sprite_plus);

	// Draw bars
	sf::RectangleShape bar;
	bar.setSize(sf::Vector2f(BAR_WIDTH, BAR_HEIGHT));
	bar.setOutlineColor(stadium->club0->colorDark);
	bar.setFillColor(stadium->club0->colorLight);
	bar.setOutlineThickness(1);
	int value_int = value*10;
	for (int i=0; i<10; i++)
	{
		if (i==value_int) 
			bar.setFillColor(sf::Color::Transparent);
		bar.setPosition(left+BAR_LEFT + i*BAR_NEXT, top);
		window->draw(bar);
	}
}

void TacticScreen::drawHeader()
{
	sf::RectangleShape headerOutline(sf::Vector2f(HEADER_REC_WIDTH,HEADER_REC_HEIGHT));
	headerOutline.setPosition( (1366*SCALE_H-HEADER_REC_WIDTH)/2, HEADER_REC_TOP );
	headerOutline.setOutlineThickness(0);
	headerOutline.setOutlineColor(HEADER_OUTSIDE_COLOR);
	headerOutline.setFillColor(stadium->club0->colorDark);
	window->draw(headerOutline);

	wstring wstr = stadium->club0->fullName + wstring(L" - " + wstring_TacticTabs[selectedTacticTab]);
	drawText(wstr,fonts->regular,TEXT_TACTIC_HEADER_SIZE,sf::Text::Bold,TEXT_TACTIC_HEADER_LEFT,TEXT_TACTIC_HEADER_TOP,stadium->club0->colorLight);
}

void TacticScreen::InitializeScreen()
{
	for (int i=0; i<8; i++)
	{
		text_TacticTabs[i].setFont(fonts->button);
		text_TacticTabs[i].setString(wstring_TacticTabs[i]);
		text_TacticTabs[i].setCharacterSize(TEXT_TACTIC_SIDEBUTTON_SIZE);
		text_TacticTabs[i].setPosition(BUTTON_TACTIC_SIDE_LEFT+TEXT_TACTIC_SIDEBUTTON_LEFTMARGIN, 
						  BUTTON_TACTIC_TABS_TOP + i * (TEXT_TACTIC_SIDEBUTTON_SIZE+TEXT_TACTIC_SIDEBUTTON_GAP_V));
	}

	// Button definitions for Confirm and Back
	recButton_Confirm.setSize( sf::Vector2f(BUTTON_TACTIC_SIDE_WIDTH, BUTTON_TACTIC_SIDE_HEIGHT) );
	recButton_Confirm.setPosition(BUTTON_TACTIC_SIDE_LEFT, BUTTON_TACTIC_CONFIRM_TOP);
	recButton_Confirm.setOutlineThickness(2);

	recButton_Back.setSize( sf::Vector2f(BUTTON_TACTIC_SIDE_WIDTH, BUTTON_TACTIC_SIDE_HEIGHT) );
	recButton_Back.setPosition(BUTTON_TACTIC_SIDE_LEFT, BUTTON_TACTIC_BACK_TOP);
	recButton_Back.setOutlineThickness(2);

	text_Confirm.setFont(fonts->button);
	text_Confirm.setString(langstrings->GENERAL_0004);
	text_Confirm.setCharacterSize(TEXT_TACTIC_SIDEBUTTON_SIZE);
	text_Confirm.setStyle(sf::Text::Bold);
	text_Confirm.setPosition(BUTTON_TACTIC_SIDE_LEFT+TEXT_TACTIC_SIDEBUTTON_LEFTMARGIN, BUTTON_TACTIC_CONFIRM_TOP+TEXT_TACTIC_SIDEBUTTON_GAP_V);

	text_Back.setFont(fonts->button);
	text_Back.setString(langstrings->GENERAL_0003);
	text_Back.setCharacterSize(TEXT_TACTIC_SIDEBUTTON_SIZE);
	text_Back.setStyle(sf::Text::Bold);
	text_Back.setPosition(BUTTON_TACTIC_SIDE_LEFT+TEXT_TACTIC_SIDEBUTTON_LEFTMARGIN, BUTTON_TACTIC_BACK_TOP+TEXT_TACTIC_SIDEBUTTON_GAP_V);

}

void TacticScreen::DefaultButtonColors()
{
	for (int i=0; i<8; i++)
	{
		text_TacticTabs[i].setColor(BUTTON1_TEXT_COLOR);
	}

	recButton_Confirm.setOutlineColor(BUTTON1_OUTSIDE_COLOR);
	recButton_Confirm.setFillColor(BUTTON1_INSIDE_COLOR);

	recButton_Back.setOutlineColor(BUTTON1_OUTSIDE_COLOR);
	recButton_Back.setFillColor(BUTTON1_INSIDE_COLOR);

	text_Confirm.setColor(BUTTON1_TEXT_COLOR);
	text_Back.setColor(BUTTON1_TEXT_COLOR);
}

void TacticScreen::ShowProfile(Footballer *f)
{
	sf::RectangleShape rec_Outline( sf::Vector2f(TACTIC_TEAMSHEET_PROFILE_WIDTH, TACTIC_TEAMSHEET_PROFILE_HEIGHT) );
	rec_Outline.setPosition(TACTIC_TEAMSHEET_PROFILE_LEFT, TACTIC_TEAMSHEET_PROFILE_TOP);
	rec_Outline.setOutlineThickness(2);
	rec_Outline.setOutlineColor(BUTTON1_OUTSIDE_COLOR);
	rec_Outline.setFillColor(TACTIC_TEAMSHEET_BACKCOLOR);
	window->draw(rec_Outline);

	drawText(f->fullName,fonts->regular,TEXT_TACTIC_TEAMSHEET_FOOTBALLERNAMESIZE*2,sf::Text::Regular,TACTIC_TEAMSHEET_PROFILE_LEFT+50,TACTIC_TEAMSHEET_PROFILE_TOP+50,sf::Color::Black);

}

bool TacticScreen::SwapSquadPositions(SquadPosition* s1, SquadPosition* s2)
{
	Footballer* temp = s1->get_footballer();
	s1->set_footballer(s2->get_footballer());
	s2->set_footballer(temp);

	return true;
}

void TacticScreen::drawTacticsPanel_TeamSheet()
{
	wstring wstr;

	Club* club0 = stadium->club0; // First club for demo. // TODO: User selection will be considered.
	SquadPosition** _lineUp = club0->lineUp;
	SquadPosition** _subs = club0->subs;
	SquadPosition** _reserves = club0->reserves;
	
	drawText(langstrings->TacticScreen_0001,fonts->regular,TEXT_TACTIC_TEAMSHEET_TEAMNAMESIZE,sf::Text::Bold,TACTIC_TEAMSHEET_NAME_LEFT,TEXT_TACTIC_TEAMSHEET_lineUp_TOP,club0->colorDark);
	for (int i=0; i<11; i++)
	{
		wstr = to_wstring(_lineUp[i]->get_footballer()->number)+L".";
		float y_pos = TEXT_TACTIC_TEAMSHEET_lineUp_TOP+TEXT_TACTIC_TEAMSHEET_TEAMNAMESIZE+10.0*SCALE_V+i*(TEXT_TACTIC_TEAMSHEET_FOOTBALLERNAMESIZE+5.0*SCALE_V);
		sf::FloatRect floatRect = drawText(wstr,fonts->regular,TEXT_TACTIC_TEAMSHEET_FOOTBALLERNAMESIZE,sf::Text::Regular,TACTIC_TEAMSHEET_NUMBER_LEFT,y_pos,sf::Color::Black);

		wstr = _lineUp[i]->get_footballer()->fullName_shown;
		drawText(wstr,fonts->regular,TEXT_TACTIC_TEAMSHEET_FOOTBALLERNAMESIZE,sf::Text::Regular,TACTIC_TEAMSHEET_NAME_LEFT,y_pos,sf::Color::Black);

		wstr = _lineUp[i]->getstring_mainPosition()+L" "+_lineUp[i]->getstring_aligningPosition();
		drawText(wstr,fonts->regular,TEXT_TACTIC_TEAMSHEET_FOOTBALLERNAMESIZE,sf::Text::Regular,TACTIC_TEAMSHEET_POSITION_LEFT,y_pos,sf::Color::Black);

		_lineUp[i]->set_teamSheetBound(floatRect);
	}
	
	drawText(langstrings->TacticScreen_0002,fonts->regular,TEXT_TACTIC_TEAMSHEET_TEAMNAMESIZE,sf::Text::Bold,TACTIC_TEAMSHEET_NAME_LEFT,TEXT_TACTIC_TEAMSHEET_SUBS_TOP,club0->colorDark);
	for (int i=0; i<club0->subsSize; i++)
	{
		wstr = to_wstring(_subs[i]->get_footballer()->number)+L".";
		float y_pos = TEXT_TACTIC_TEAMSHEET_SUBS_TOP+TEXT_TACTIC_TEAMSHEET_TEAMNAMESIZE+10*SCALE_V+i*(TEXT_TACTIC_TEAMSHEET_FOOTBALLERNAMESIZE+5*SCALE_V);
		sf::FloatRect floatRect = drawText(wstr,fonts->regular,TEXT_TACTIC_TEAMSHEET_FOOTBALLERNAMESIZE,sf::Text::Regular,TACTIC_TEAMSHEET_NUMBER_LEFT, y_pos,sf::Color::Black);

		wstr = _subs[i]->get_footballer()->fullName_shown;
		drawText(wstr,fonts->regular,TEXT_TACTIC_TEAMSHEET_FOOTBALLERNAMESIZE,sf::Text::Regular,TACTIC_TEAMSHEET_NAME_LEFT, y_pos,sf::Color::Black);

		_subs[i]->set_teamSheetBound(floatRect);
	}

	drawText(langstrings->TacticScreen_0003,fonts->regular,TEXT_TACTIC_TEAMSHEET_TEAMNAMESIZE,sf::Text::Bold,TACTIC_TEAMSHEET_NAME_LEFT,TEXT_TACTIC_TEAMSHEET_RESERVES_TOP,club0->colorDark);	
	for (int i=0; i<club0->reservesSize; i++)
	{
		wstr = to_wstring(_reserves[i]->get_footballer()->number)+L".";
		float y_pos = TEXT_TACTIC_TEAMSHEET_RESERVES_TOP+TEXT_TACTIC_TEAMSHEET_TEAMNAMESIZE+10*SCALE_V+i*(TEXT_TACTIC_TEAMSHEET_FOOTBALLERNAMESIZE+5*SCALE_V);
		sf::FloatRect floatRect = drawText(wstr,fonts->regular,TEXT_TACTIC_TEAMSHEET_FOOTBALLERNAMESIZE,sf::Text::Regular,TACTIC_TEAMSHEET_NUMBER_LEFT,y_pos,sf::Color::Black);

		wstr = _reserves[i]->get_footballer()->fullName_shown;
		drawText(wstr,fonts->regular,TEXT_TACTIC_TEAMSHEET_FOOTBALLERNAMESIZE,sf::Text::Regular,TACTIC_TEAMSHEET_NAME_LEFT,y_pos,sf::Color::Black);

		_reserves[i]->set_teamSheetBound(floatRect);
	}
	/**/
}

void TacticScreen::drawTacticsPanel_Formation()
{
	sf::Sprite footballPitch;
	footballPitch.setTexture(tex_FootballPitch);
	footballPitch.setScale(sf::Vector2f( (TACTIC_PANEL_WIDTH)*1.0f/TacticFootballPitch_x , (TACTIC_PANEL_HEIGHT)*1.0f/TacticFootballPitch_y  ));
	footballPitch.setPosition(TACTIC_PANEL_LEFT,TACTIC_PANEL_TOP);
	window->draw(footballPitch);
	Club* club0 = stadium->club0;
	SquadPosition** _lineUp = club0->lineUp;

	// Defending Formation
	for (int i=0; i<11; i++)
	{
		sf::CircleShape circle(FORMATION_CIRCLE_SIZE);
		float x_pos = TACTIC_FORMATION_LEFT+TACTIC_FORMATION_WIDTH*_lineUp[i]->tactical_x;
		float y_pos = TACTIC_FORMATION_TOP+TACTIC_FORMATION_HEIGHT*_lineUp[i]->tactical_y;
		circle.setPosition(x_pos-FORMATION_CIRCLE_SIZE,y_pos-(1.0*FORMATION_CIRCLE_SIZE));
		circle.setFillColor(*stadium->club0_color0); //
		//circle.setOutlineColor(*stadium->club0_color0);
		circle.setPointCount(1000);
		window->draw(circle);

		_lineUp[i]->set_formationBound(circle.getGlobalBounds());

		float x_pos2 = TACTIC_FORMATION_LEFT+TACTIC_FORMATION_WIDTH*0.5*_lineUp[i]->defending_x;
		float y_pos2 = TACTIC_FORMATION_TOP+TACTIC_FORMATION_HEIGHT*_lineUp[i]->defending_y;
		circle.setPosition(x_pos2-(FORMATION_CIRCLE_SIZE*0.5),y_pos2-(0.5*FORMATION_CIRCLE_SIZE));
		circle.setScale(0.5,0.5);
		sf::Color newcolor = *stadium->club0_color0;
		newcolor.a=150;
		circle.setFillColor(newcolor);
		window->draw(circle);
		int number = _lineUp[i]->get_footballer()->number;
		drawText(to_string(number),fonts->narrowRegular,TEXT_TACTIC_TEAMSHEET_FOOTBALLERNAMESIZE,sf::Text::Bold,
				x_pos+((number<10)?4:0)-(TEXT_TACTIC_TEAMSHEET_FOOTBALLERNAMESIZE/2),y_pos-(TEXT_TACTIC_TEAMSHEET_FOOTBALLERNAMESIZE/2),*stadium->club0_color1);

		newcolor = *stadium->club0_color1;
		newcolor.a=150;
		drawText(to_string(_lineUp[i]->get_footballer()->number),fonts->narrowRegular,TEXT_TACTIC_TEAMSHEET_FOOTBALLERNAMESIZE,sf::Text::Regular,
				x_pos2+((number<10)?3:0)-(TEXT_TACTIC_TEAMSHEET_FOOTBALLERNAMESIZE/2),y_pos2-(TEXT_TACTIC_TEAMSHEET_FOOTBALLERNAMESIZE/2),newcolor);

		drawText(_lineUp[i]->get_footballer()->shortName_shown,fonts->narrowRegular,TEXT_TACTIC_TEAMSHEET_FOOTBALLERNAMESIZE,sf::Text::Regular,
				x_pos,y_pos+FORMATION_CIRCLE_SIZE+10,*stadium->club0_color1);

		if (formation_isFootballerSelected && formation_selectedSquadPosition==_lineUp[i])
		{
			sf::CircleShape selectedCircle(FORMATION_CIRCLE_SIZE*2.5);
			selectedCircle.setPosition(x_pos-FORMATION_CIRCLE_SIZE*2.5,y_pos-FORMATION_CIRCLE_SIZE*2.5);
			selectedCircle.setOutlineThickness(FORMATION_CIRCLE_OUTLINESIZE);
			selectedCircle.setFillColor(sf::Color::Transparent);
			selectedCircle.setOutlineColor(*stadium->club0_color1-sf::Color(0,0,0,150));
			selectedCircle.setPointCount(100);
			window->draw(selectedCircle);
		}

		
	}
}

void TacticScreen::drawTacticsPanel_TeamInstr()
{
	for (int i=0; i<SIZE_TEAMINSTR1; i++)
	{
		Instruction* ins = &teamInstructions1[i];
		drawBars(ins->position.x,ins->position.y,ins->descr1,ins->descr2,*ins->value);
	}
}

void TacticScreen::drawTacticsPanel_AttackingPlay()
{
	for (int i=0; i<1; i++)
	{
		Instruction* ins = &attInstructions1[i];
		drawBars(ins->position.x,ins->position.y,ins->descr1,ins->descr2,*ins->value);
	}
}

void TacticScreen::drawTacticsPanel_DefendingPlay()
{
	for (int i=0; i<1; i++)
	{
		Instruction* ins = &defInstructions1[i];
		drawBars(ins->position.x,ins->position.y,ins->descr1,ins->descr2,*ins->value);
	}
}

void TacticScreen::drawTacticsPanel_SetPieces()
{
	// Descriptions
	drawText(langstrings->INSTRUCTIONS_005+langstrings->GENERAL_0005+L"):", fonts->regular, BAR_HEIGHT, sf::Text::Regular, INSTR_FIRSTLEFT, INSTR_FIRSTTOP, sf::Color::Black);
	drawText(langstrings->INSTRUCTIONS_005+langstrings->GENERAL_0006+L"):", fonts->regular, BAR_HEIGHT, sf::Text::Regular, INSTR_SECONDLEFT, INSTR_FIRSTTOP, sf::Color::Black);
	drawText(langstrings->INSTRUCTIONS_006+langstrings->GENERAL_0005+L"):", fonts->regular, BAR_HEIGHT, sf::Text::Regular, INSTR_FIRSTLEFT, INSTR_FIRSTTOP+30, sf::Color::Black);
	drawText(langstrings->INSTRUCTIONS_006+langstrings->GENERAL_0006+L"):", fonts->regular, BAR_HEIGHT, sf::Text::Regular, INSTR_SECONDLEFT, INSTR_FIRSTTOP+30, sf::Color::Black);
	drawText(langstrings->INSTRUCTIONS_007+L":", fonts->regular, BAR_HEIGHT, sf::Text::Regular, INSTR_FIRSTLEFT, INSTR_FIRSTTOP+60, sf::Color::Black);

	// Arrow buttons
	sprite_circlebutton.setColor(sf::Color::Black);

	for (int i=0; i<3; i++)
	{
		sprite_circlebutton.setPosition(INSTR_FIRSTLEFT+LEFTARROW_PLACE,INSTR_FIRSTTOP+i*30);
		window->draw(sprite_circlebutton);
		sprite_leftArrow.setPosition(INSTR_FIRSTLEFT+LEFTARROW_PLACE,INSTR_FIRSTTOP+i*30);
		window->draw(sprite_leftArrow);
		sprite_circlebutton.setPosition(INSTR_FIRSTLEFT+RIGHTARROW_PLACE,INSTR_FIRSTTOP+i*30);
		window->draw(sprite_circlebutton);
		sprite_rightArrow.setPosition(INSTR_FIRSTLEFT+RIGHTARROW_PLACE,INSTR_FIRSTTOP+i*30);
		window->draw(sprite_rightArrow);

		if (i<2)
		{
			sprite_circlebutton.setPosition(INSTR_SECONDLEFT+LEFTARROW_PLACE,INSTR_FIRSTTOP+i*30);
			window->draw(sprite_circlebutton);
			sprite_leftArrow.setPosition(INSTR_SECONDLEFT+LEFTARROW_PLACE,INSTR_FIRSTTOP+i*30);
			window->draw(sprite_leftArrow);
			sprite_circlebutton.setPosition(INSTR_SECONDLEFT+RIGHTARROW_PLACE,INSTR_FIRSTTOP+i*30);
			window->draw(sprite_circlebutton);
			sprite_rightArrow.setPosition(INSTR_SECONDLEFT+RIGHTARROW_PLACE,INSTR_FIRSTTOP+i*30);
			window->draw(sprite_rightArrow);
		}
	}

	// Player names
	Club* club = stadium->club0;
	SquadPosition* player;
	player = club->lineUp[club->taker_leftFreeKick];
	drawText(player->get_footballer()->fullName_shown, fonts->regular, BAR_HEIGHT, sf::Text::Regular, INSTR_FIRSTLEFT+200, INSTR_FIRSTTOP, sf::Color::Black);
	player = club->lineUp[club->taker_rightFreeKick];
	drawText(player->get_footballer()->fullName_shown, fonts->regular, BAR_HEIGHT, sf::Text::Regular, INSTR_SECONDLEFT+200, INSTR_FIRSTTOP, sf::Color::Black);
	player = club->lineUp[club->taker_leftCornerKick];
	drawText(player->get_footballer()->fullName_shown, fonts->regular, BAR_HEIGHT, sf::Text::Regular, INSTR_FIRSTLEFT+200, INSTR_FIRSTTOP+30, sf::Color::Black);
	player = club->lineUp[club->taker_rightCornerKick];
	drawText(player->get_footballer()->fullName_shown, fonts->regular, BAR_HEIGHT, sf::Text::Regular, INSTR_SECONDLEFT+200, INSTR_FIRSTTOP+30, sf::Color::Black);
	player = club->lineUp[club->taker_penalty];
	drawText(player->get_footballer()->fullName_shown, fonts->regular, BAR_HEIGHT, sf::Text::Regular, INSTR_FIRSTLEFT+200, INSTR_FIRSTTOP+60, sf::Color::Black);
}

void TacticScreen::drawTacticsPanel_PlayerInstructions()
{
	// Select a player:
	drawText(langstrings->INSTRUCTIONS_008, fonts->regular, BAR_HEIGHT, sf::Text::Regular, 600, INSTR_FIRSTTOP, sf::Color::Black);
	sprite_circlebutton.setColor(sf::Color::Black);
	sprite_circlebutton.setPosition(600+LEFTARROW_PLACE,INSTR_FIRSTTOP);
	window->draw(sprite_circlebutton);
	sprite_leftArrow.setPosition(600+LEFTARROW_PLACE,INSTR_FIRSTTOP);
	window->draw(sprite_leftArrow);
	sprite_circlebutton.setPosition(600+RIGHTARROW_PLACE,INSTR_FIRSTTOP);
	window->draw(sprite_circlebutton);
	sprite_rightArrow.setPosition(600+RIGHTARROW_PLACE,INSTR_FIRSTTOP);
	window->draw(sprite_rightArrow);
	SquadPosition* player = stadium->club0->lineUp[selectedPlayer_instruction];
	drawText(player->get_footballer()->fullName_shown, fonts->regular, BAR_HEIGHT, sf::Text::Regular, 800, INSTR_FIRSTTOP, sf::Color::Black);

	// Draw instructions:
	for (int i=0; i<SIZE_PLAYERINSTR1; i++)
	{
		Instruction* ins = &playerInstructions1[i];
		drawBars(ins->position.x,ins->position.y,ins->descr1,ins->descr2,*ins->value);
	}

};

void TacticScreen::drawTacticsPanel()
{
	sf::RectangleShape rec_Outline( sf::Vector2f(TACTIC_PANEL_WIDTH, TACTIC_PANEL_HEIGHT) );
	rec_Outline.setPosition(TACTIC_PANEL_LEFT, TACTIC_PANEL_TOP);
	rec_Outline.setOutlineThickness(2);
	rec_Outline.setOutlineColor(BUTTON1_OUTSIDE_COLOR);
	rec_Outline.setFillColor(TACTIC_PANEL_BACKCOLOR);
	window->draw(rec_Outline);

	switch(selectedTacticTab)
	{
	case TeamSheet:
		drawTacticsPanel_TeamSheet();
		break;
	case Formation:
		drawTacticsPanel_Formation();
		break;
	case TeamInstr:
		drawTacticsPanel_TeamInstr();
		break;
	case AttackingPlay:
		drawTacticsPanel_AttackingPlay();
		break;
	case DefendingPlay:
		drawTacticsPanel_DefendingPlay();
		break;
	case PlayerInstr:
		drawTacticsPanel_PlayerInstructions();
		break;
	case SetPieces:
		drawTacticsPanel_SetPieces();
		break;
	default:
		break;
	}
}

e_Window TacticScreen::HandleMouseLeftPressed(float x, float y)
{
	Club* club0 = stadium->club0; // Human club

	if (x>BUTTON_TACTIC_SIDE_LEFT && x<BUTTON_TACTIC_SIDE_LEFT+BUTTON_TACTIC_SIDE_WIDTH)
	{ // Left mouse is pressed on one of the side buttons on the left.
		if (y>BUTTON_TACTIC_CONFIRM_TOP && y<BUTTON_TACTIC_CONFIRM_TOP+BUTTON_TACTIC_SIDE_HEIGHT)
		{ // Left mouse is pressed on button named "Confirm".
			return matchScreen;
		}
		else if (y>BUTTON_TACTIC_BACK_TOP && y<BUTTON_TACTIC_BACK_TOP+BUTTON_TACTIC_SIDE_HEIGHT)
		{ // Left mouse is pressed on button named "Back".
			if (stadium->elapsedSeconds>0)
				return matchScreen;
			else
				return earlierScreen; //TODO: We have to check if user really wants to go back.
		}
		else 
		{
			int i = (y-BUTTON_TACTIC_TABS_TOP) / (TEXT_TACTIC_SIDEBUTTON_SIZE+TEXT_TACTIC_SIDEBUTTON_GAP_V) ;
			if (i>=0 && i<TacticTabsSize)
			{ // Left mouse is pressed on one of the Tactic Tabs.
				selectedTacticTab=static_cast<TacticTab>(i);
			}
		}
	}

	// DIFFERENT ACTIONS FOR DIFFERENT TABS
	else if (selectedTacticTab == TeamSheet)
	{
		if (x>TACTIC_TEAMSHEET_NUMBER_LEFT && x<TACTIC_TEAMSHEET_PROFILE_LEFT)
		{ // One of the footballers are selected.
			for (int i=0; i<11; i++)
			{
				fr = club0->lineUp[i]->get_teamSheetBound();
				if (y>fr.top && y<fr.top+fr.height)
				{
					teamsheet_selectedSquadPosition = club0->lineUp[i];
					teamsheet_isFootballerSelected = true;
					break;
				}
			}

			if (!teamsheet_isFootballerSelected)
			{
				for (int i=0; i<club0->subsSize; i++)
				{
					fr = club0->subs[i]->get_teamSheetBound();
					if (y>fr.top && y<fr.top+fr.height)
					{
						teamsheet_selectedSquadPosition = club0->subs[i];
						teamsheet_isFootballerSelected = true;
						break;
					}
				}
			}

			if (!teamsheet_isFootballerSelected)
			{
				for (int i=0; i<club0->reservesSize; i++)
				{
					fr = club0->reserves[i]->get_teamSheetBound();
					if (y>fr.top && y<fr.top+fr.height)
					{
						teamsheet_selectedSquadPosition = club0->reserves[i];
						teamsheet_isFootballerSelected = true;
						break;
					}
				}
			}
		}
	}
	else if (selectedTacticTab == Formation)
	{ // Selecting a footballer to change his position.
		formation_isFootballerSelected = false;
		for (int i=0; i<11; i++)
		{
			fr = club0->lineUp[i]->get_formationBound();
			if (y>fr.top && y<fr.top+fr.height && x>fr.left && x<fr.left+fr.width)
			{
				formation_selectedSquadPosition = club0->lineUp[i];
				formation_isFootballerSelected = true;
				break;
			}
		}
	}
	else if (selectedTacticTab == TeamInstr)
	{
		for (int i=0; i<SIZE_TEAMINSTR1; i++)
		{
			if (teamInstructions1[i].minus.contains(x,y))
			{
				ChangeInstr(teamInstructions1[i].value,-0.1);
				break;
			}
			else if (teamInstructions1[i].plus.contains(x,y))
			{
				ChangeInstr(teamInstructions1[i].value,0.1);
				break;
			}
		}
	}
	else if (selectedTacticTab == AttackingPlay)
	{
		for (int i=0; i<SIZE_ATTINSTR1; i++)
		{
			if (attInstructions1[i].minus.contains(x,y))
			{
				ChangeInstr(attInstructions1[i].value,-0.1);
				break;
			}
			else if (attInstructions1[i].plus.contains(x,y))
			{
				ChangeInstr(attInstructions1[i].value,0.1);
				break;
			}
		}
	}
	else if (selectedTacticTab == DefendingPlay)
	{
		for (int i=0; i<SIZE_DEFINSTR1; i++)
		{
			if (defInstructions1[i].minus.contains(x,y))
			{
				ChangeInstr(defInstructions1[i].value,-0.1);
				break;
			}
			else if (defInstructions1[i].plus.contains(x,y))
			{
				ChangeInstr(defInstructions1[i].value,0.1);
				break;
			}
		}
	}
	else if (selectedTacticTab == PlayerInstr)
	{
		if (clickCircle_playerInstr[0].contains(x,y))
		{
			selectedPlayer_instruction = moduloNatural(selectedPlayer_instruction-1,11);
			update_playerInstructions();
		}
		else if (clickCircle_playerInstr[1].contains(x,y))
		{
			selectedPlayer_instruction = moduloNatural(selectedPlayer_instruction+1,11);
			update_playerInstructions();
		}
		else
		{
			for (int i=0; i<SIZE_PLAYERINSTR1; i++)
			{
				if (playerInstructions1[i].minus.contains(x,y))
				{
					ChangeInstr(playerInstructions1[i].value,-0.1);
					cout << "new instr: " << *playerInstructions1[i].value << endl;
					break;
				}
				else if (playerInstructions1[i].plus.contains(x,y))
				{
					ChangeInstr(playerInstructions1[i].value,0.1);
					cout << "new instr: " << *playerInstructions1[i].value << endl;
					break;
				}
			}
		}
	}
	else if (selectedTacticTab == SetPieces)
	{
		if (clickCircles_setPieces[0].contains(x,y))
			club0->taker_leftFreeKick = moduloNatural(club0->taker_leftFreeKick-1,11);
		else if (clickCircles_setPieces[1].contains(x,y))
			club0->taker_leftFreeKick = moduloNatural(club0->taker_leftFreeKick+1,11);
		else if (clickCircles_setPieces[2].contains(x,y))
			club0->taker_rightFreeKick = moduloNatural(club0->taker_rightFreeKick-1,11);
		else if (clickCircles_setPieces[3].contains(x,y))
			club0->taker_rightFreeKick = moduloNatural(club0->taker_rightFreeKick+1,11);
		else if (clickCircles_setPieces[4].contains(x,y))
			club0->taker_leftCornerKick = moduloNatural(club0->taker_leftCornerKick-1,11);
		else if (clickCircles_setPieces[5].contains(x,y))
			club0->taker_leftCornerKick = moduloNatural(club0->taker_leftCornerKick+1,11);
		else if (clickCircles_setPieces[6].contains(x,y))
			club0->taker_rightCornerKick = moduloNatural(club0->taker_rightCornerKick-1,11);
		else if (clickCircles_setPieces[7].contains(x,y))
			club0->taker_rightCornerKick = moduloNatural(club0->taker_rightCornerKick+1,11);
		else if (clickCircles_setPieces[8].contains(x,y))
			club0->taker_penalty = moduloNatural(club0->taker_penalty-1,11);
		else if (clickCircles_setPieces[9].contains(x,y))
			club0->taker_penalty = moduloNatural(club0->taker_penalty+1,11);
	}

	return noChange;
}

void TacticScreen::HandleMouseMoved(float x, float y)
{
	wstring wstr;
	Club* club0 = stadium->club0; // Human club

	if (selectedTacticTab == TeamSheet)
	{ 
		if (x>TACTIC_TEAMSHEET_NUMBER_LEFT && x<TACTIC_TEAMSHEET_PROFILE_LEFT)
		{ // One of the footballers are hovered. His profile will be shown
			bool found = false;
			for (int i=0; i<11; i++)
			{
				fr = club0->lineUp[i]->get_teamSheetBound();
				if (y>fr.top && y<fr.top+fr.height)
				{
					ShowProfile(club0->lineUp[i]->get_footballer());
					found = true;
					break;
				}
			}

			if (!found)
			{
				for (int i=0; i<club0->subsSize; i++)
				{
					fr = club0->subs[i]->get_teamSheetBound();
					if (y>fr.top && y<fr.top+fr.height)
					{
						ShowProfile(club0->subs[i]->get_footballer());
						found = true;
						break;
					}
				}
			}

			if (!found)
			{
				for (int i=0; i<club0->reservesSize; i++)
				{
					fr = club0->reserves[i]->get_teamSheetBound();
					if (y>fr.top && y<fr.top+fr.height)
					{
						ShowProfile(club0->reserves[i]->get_footballer());
						break;
					}
				}
			}
		}

		if (teamsheet_isFootballerSelected)
		{ // A footballer is being dragged.
			wstr = teamsheet_selectedSquadPosition->get_footballer()->fullName_shown;
			drawText(wstr,fonts->regular,TEXT_TACTIC_TEAMSHEET_FOOTBALLERNAMESIZE+5,sf::Text::Bold || sf::Text::Italic,x+10,y+10,club0->colorDark);
		}
	}

	if (x>BUTTON_TACTIC_SIDE_LEFT && x<BUTTON_TACTIC_SIDE_LEFT+BUTTON_TACTIC_SIDE_WIDTH)
	{ // Mouse is moved to one of the side buttons on the left.
		if (y>BUTTON_TACTIC_CONFIRM_TOP && y<BUTTON_TACTIC_CONFIRM_TOP+BUTTON_TACTIC_SIDE_HEIGHT)
		{ // Mouse is moved to button named "Confirm".
			recButton_Confirm.setOutlineColor(BUTTON1_HOVERED_OUTSIDE_COLOR);
			recButton_Confirm.setFillColor(BUTTON1_HOVERED_INSIDE_COLOR);
			text_Confirm.setColor(BUTTON1_HOVERED_TEXT_COLOR);
		}
		else if (y>BUTTON_TACTIC_BACK_TOP && y<BUTTON_TACTIC_BACK_TOP+BUTTON_TACTIC_SIDE_HEIGHT)
		{ // Mouse is moved to button named "Back".
			recButton_Back.setOutlineColor(BUTTON1_HOVERED_OUTSIDE_COLOR);
			recButton_Back.setFillColor(BUTTON1_HOVERED_INSIDE_COLOR);
			text_Back.setColor(BUTTON1_HOVERED_TEXT_COLOR);
		}
		else 
		{
			int i = (y-BUTTON_TACTIC_TABS_TOP) / (TEXT_TACTIC_SIDEBUTTON_SIZE+TEXT_TACTIC_SIDEBUTTON_GAP_V) ;
			if (i>=0 && i<TacticTabsSize)
			{ // Mouse is moved to one of the Tactic Tabs.
				text_TacticTabs[i].setColor(BUTTON1_HOVERED_TEXT_COLOR);
			}
		}
	}
}

void TacticScreen::HandleMouseLeftReleased(float x, float y)
{
	Club* club0 = stadium->club0; // Human club

	if (selectedTacticTab == TeamSheet && teamsheet_isFootballerSelected)
	{ 
		if (x>TACTIC_TEAMSHEET_NUMBER_LEFT && x<TACTIC_TEAMSHEET_PROFILE_LEFT)
		{ // A footballer is dragged.

			bool found = false;

			for (int i=0; i<11; i++)
			{
				fr = club0->lineUp[i]->get_teamSheetBound();
				if (y>fr.top && y<fr.top+fr.height)
				{
					SwapSquadPositions(teamsheet_selectedSquadPosition,club0->lineUp[i]);
					found = true;
					break;
				}
			}

			if (!found)
			{
				for (int i=0; i<club0->subsSize; i++)
				{
					fr = club0->subs[i]->get_teamSheetBound();
					if (y>fr.top && y<fr.top+fr.height)
					{
						SwapSquadPositions(teamsheet_selectedSquadPosition,club0->subs[i]);
						found = true;
						break;
					}
				}
			}

			if (!found)
			{
				for (int i=0; i<club0->reservesSize; i++)
				{
					fr = club0->reserves[i]->get_teamSheetBound();
					if (y>fr.top && y<fr.top+fr.height)
					{
						SwapSquadPositions(teamsheet_selectedSquadPosition,club0->reserves[i]);
						break;
					}
				}
			}

			teamsheet_isFootballerSelected = false;
		}
	}
}

void TacticScreen::HandleKeyPressed()
{
	if (event.key.code == sf::Keyboard::Up )
	{
		if (selectedTacticTab==Formation && formation_isFootballerSelected)
		{
			formation_selectedSquadPosition->add_tactical(0, (isShiftPressed)?(-0.1):(-0.01) );
			stadium->club0->sortLineUp();
		}
	}
	else if (event.key.code == sf::Keyboard::Down )
	{
		if (selectedTacticTab==Formation && formation_isFootballerSelected)
		{
			formation_selectedSquadPosition->add_tactical(0, (isShiftPressed)?(0.1):(0.01) );
			stadium->club0->sortLineUp();
		}
	}
	else if (event.key.code == sf::Keyboard::Left )
	{
		if (selectedTacticTab==Formation && formation_isFootballerSelected)
		{
			formation_selectedSquadPosition->add_tactical( (isShiftPressed)?(-0.1):(-0.01), 0);
			stadium->club0->sortLineUp();
		}
	}
	else if (event.key.code == sf::Keyboard::Right )
	{
		if (selectedTacticTab==Formation && formation_isFootballerSelected)
		{
			formation_selectedSquadPosition->add_tactical( (isShiftPressed)?(0.1):(0.01), 0);
			stadium->club0->sortLineUp();
		}
	}
	else if (event.key.code == sf::Keyboard::LShift || event.key.code == sf::Keyboard::RShift)
	{
		if (selectedTacticTab==Formation && formation_isFootballerSelected)
		{
			isShiftPressed=true;
		}
	}
	else if (event.key.code == sf::Keyboard::W )
	{
		if (selectedTacticTab==Formation && formation_isFootballerSelected)
		{
			formation_selectedSquadPosition->add_defending(0, (isShiftPressed)?(-0.1):(-0.01) );
			stadium->club0->sortLineUp();
		}
	}
	else if (event.key.code == sf::Keyboard::S )
	{
		if (selectedTacticTab==Formation && formation_isFootballerSelected)
		{
			formation_selectedSquadPosition->add_defending(0, (isShiftPressed)?(0.1):(0.01) );
			stadium->club0->sortLineUp();
		}
	}
	else if (event.key.code == sf::Keyboard::A )
	{
		if (selectedTacticTab==Formation && formation_isFootballerSelected)
		{
			formation_selectedSquadPosition->add_defending( (isShiftPressed)?(-0.1):(-0.01), 0);
			stadium->club0->sortLineUp();
		}
	}
	else if (event.key.code == sf::Keyboard::D )
	{
		if (selectedTacticTab==Formation && formation_isFootballerSelected)
		{
			formation_selectedSquadPosition->add_defending( (isShiftPressed)?(0.1):(0.01), 0);
			stadium->club0->sortLineUp();
		}
	}
}

void TacticScreen::HandleKeyReleased()
{
	if (event.key.code == sf::Keyboard::LShift || event.key.code == sf::Keyboard::RShift)
	{
		if (selectedTacticTab==Formation && formation_isFootballerSelected)
			isShiftPressed=false;
	}
}

e_Window TacticScreen::Render()
{
	UpdateStrings();
	earlierScreen = mainScreen;
	InitializeScreen();
	e_Window result;
	while (window->isOpen())
	{
		window->clear();
		drawBackground();
		drawHeader();
		drawTacticsPanel();

		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				bool _result = RenderClosing();
				if (_result)
					return exitSignal;
			}

			DefaultButtonColors();

			switch (event.type)
			{ 
				case sf::Event::MouseButtonPressed:
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						result = HandleMouseLeftPressed(event.mouseButton.x,event.mouseButton.y);
					}
					if (result!=noChange)
						return result;
					break;
				case sf::Event::MouseButtonReleased:
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						HandleMouseLeftReleased(event.mouseButton.x,event.mouseButton.y);
					}
					break;
				case sf::Event::KeyPressed:
					HandleKeyPressed();
					break;
				case sf::Event::KeyReleased:
					HandleKeyReleased();
					break;
				default:
					break;
			}
		}

		HandleMouseMoved(event.mouseMove.x,event.mouseMove.y);

		window->draw(recButton_Confirm);
		window->draw(recButton_Back);
		window->draw(text_Confirm);
		window->draw(text_Back);
		for (int i=0; i<TacticTabsSize; i++)
		{
			window->draw(text_TacticTabs[i]);
		}

		window->display();
	}
	return exitSignal;
}