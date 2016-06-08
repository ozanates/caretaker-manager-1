#include "screen3_match.h"

MatchScreen::MatchScreen(sf::RenderWindow* w, Game* g, Fonts* f, Stadium* s):iScreen(w,g,f,s)
{
	// SET POSITIONS
	MATCH_PLAYAREA_LEFT = (MATCH_PITCH_LEFT+ (88.0*MATCH_PITCH_WIDTH/1600.0) ); // 88*MATCH_PITCH_WIDTH/1600
	MATCH_PLAYAREA_TOP = (MATCH_PITCH_TOP+ (73.0*MATCH_PITCH_HEIGHT/1131.0) ); // 73*MATCH_PITCH_HEIGHT/1131
	MATCH_CONST_W = 1427.0*MATCH_PITCH_WIDTH/(1600.0*105.0); // 1427*MATCH_PITCH_WIDTH/1600*105
	MATCH_CONST_H = 979.0*MATCH_PITCH_HEIGHT/(1131.0*68.0); // 979*MATCH_PITCH_HEIGHT/1131*68
	float panelHMargin = ((1366-MATCH_PITCH_WIDTH)-PANEL_WIDTH)/2;
	float panelVMargin = (768-PANEL_HEIGHT*3)/4;
	panelPositions[0] = sf::Vector2f(panelHMargin,panelVMargin);
	panelPositions[1] = sf::Vector2f(panelHMargin,panelVMargin*2+PANEL_HEIGHT);
	panelPositions[2] = sf::Vector2f(panelHMargin,panelVMargin*3+PANEL_HEIGHT*2);

	paused = true;

	commentatorBackground.setPosition(MATCH_PITCH_LEFT,720);
	commentatorBackground.setSize(sf::Vector2f(MATCH_PITCH_WIDTH-5,40));
	commentatorBackground.setFillColor(sf::Color(0,50,15,100));
	commentatorText.setColor(sf::Color::White);
	commentatorText.setCharacterSize(22);
	commentatorText.setPosition(MATCH_PITCH_LEFT+10,720+5);
	commentatorText.setFont(fonts->regular);

	InitializeScreen();
	InitializeStadium();
}

void MatchScreen::InitializeScreen()
{

}

void MatchScreen::InitializeStadium()
{
	// PITCH
	footballPitch.setTexture(tex_FootballPitch);
	footballPitch.setPosition(MATCH_PITCH_LEFT,MATCH_PITCH_TOP);
	footballPitch.setScale(sf::Vector2f( (MATCH_PITCH_WIDTH)*1.0f/TacticFootballPitch_x , (MATCH_PITCH_HEIGHT)*1.0f/TacticFootballPitch_y  ));

	// BALL
	sfBall.setRadius(3);
	sfBall.setFillColor(sf::Color(255,255,255));
	sfBall.setOutlineColor(sf::Color(0,0,0));
	sfBall.setOutlineThickness(2);

	// PLAYERS
	for (int i=0; i<11; i++)
	{
		footballers0[i].setRadius(11);
		footballers0[i].setFillColor(*stadium->club0_color0);
		footballers0[i].setPointCount(1000);

		footballers1[i].setRadius(11);
		footballers1[i].setFillColor(*stadium->club1_color0);
		footballers1[i].setPointCount(1000);
	}

	// HAND

	hand.setRadius(2);
	hand.setFillColor(sf::Color::Black);
	hand.setPointCount(100);

}

void MatchScreen::drawStadium()
{
	float new_x, new_y;

	// DRAW THE FOOTBALL PITCH
	window->draw(footballPitch);

	// DRAW FOOTBALLERS
	SquadPosition **lineup = stadium->club0->lineUp;
	int kitnumber;
	for (int i=0; i<11; i++)
	{
		// DRAW CIRCLE
		new_x = MATCH_PLAYAREA_LEFT + MATCH_CONST_W*lineup[i]->x - 5.5;
		new_y = MATCH_PLAYAREA_TOP + MATCH_CONST_H*lineup[i]->y - 5.5;
		footballers0[i].setPosition(new_x,new_y);
		window->draw(footballers0[i]);

		if (lineup[i]->countdown_showName>0)
		{
			wstring name = lineup[i]->get_footballer()->shortName_shown;
			drawText(name,fonts->narrowRegular,11,sf::Text::Regular,new_x,new_y+23,sf::Color::Yellow);
			lineup[i]->countdown_showName--;
		}

		// DRAW HANDS
		hand.setPosition(2.0 + MATCH_PLAYAREA_LEFT + MATCH_CONST_W*lineup[i]->x + (15.0 * cos(lineup[i]->theta)), 2.0 + MATCH_PLAYAREA_TOP + MATCH_CONST_H*lineup[i]->y + (15.0 * sin(lineup[i]->theta)));
		window->draw(hand);

		// DRAW NUMBER
		kitnumber=lineup[i]->get_footballer()->number;
		drawText(to_string(kitnumber),fonts->wideRegular,14,sf::Text::Bold,(kitnumber>9)?(new_x+2):(new_x+7),new_y+2,*stadium->club0_color1);
	}

	lineup = stadium->club1->lineUp;
	for (int i=0; i<11; i++)
	{
		// DRAW CIRCLE
		new_x = MATCH_PLAYAREA_LEFT + MATCH_CONST_W*lineup[i]->x - 5.5;
		new_y = MATCH_PLAYAREA_TOP + MATCH_CONST_H*lineup[i]->y - 5.5;
		footballers1[i].setPosition(new_x,new_y);
		window->draw(footballers1[i]);

		if (lineup[i]->countdown_showName>0)
		{
			wstring name = lineup[i]->get_footballer()->shortName_shown;
			drawText(name,fonts->narrowRegular,11,sf::Text::Regular,new_x,new_y+23,sf::Color::Yellow);
			lineup[i]->countdown_showName--;
		}

		// DRAW HANDS
		hand.setPosition(2.0 + MATCH_PLAYAREA_LEFT + MATCH_CONST_W*lineup[i]->x + (15.0 * cos(lineup[i]->theta)), 2.0 + MATCH_PLAYAREA_TOP + MATCH_CONST_H*lineup[i]->y + (15.0 * sin(lineup[i]->theta)));
		window->draw(hand);

		// DRAW NUMBER
		kitnumber=lineup[i]->get_footballer()->number;
		drawText(to_string(kitnumber),fonts->wideRegular,14,sf::Text::Bold,(kitnumber>9)?(new_x+2):(new_x+7),new_y+2,*stadium->club1_color1);
	}

	// DRAW THE BALL
	btVector3 position = stadium->ball->getPosition3();
	float new_radius = 2.0+1.0*position.getY();
	new_x = MATCH_PLAYAREA_LEFT + MATCH_CONST_W*position.getX() - new_radius;
	new_y = MATCH_PLAYAREA_TOP + MATCH_CONST_H*position.getZ() - new_radius;

	sfBall.setPosition( sf::Vector2f(new_x,new_y));	
	sfBall.setRadius (new_radius);
	window->draw(sfBall);

	// DEBUGGING : SHOWING BALL POSITION
	if (DEBUG_SHOWVALUES)
	{
		wstring ballPosition = L"Ball Position: (" + to_wstring(position.getX()).substr(0,6) + L"," + to_wstring(position.getZ()).substr(0,6) + L"," + to_wstring(position.getY()).substr(0,6) + L")";
		drawSimpleText(ballPosition,1000,705);
		sf::Vector3f linearvel = stadium->ball->getLinearVelocity();
		wstring ballVelocity = L"Ball Linear Velocity: (" + to_wstring(linearvel.x).substr(0,6) + L"," + to_wstring(linearvel.z).substr(0,6) + L"," + to_wstring(linearvel.y).substr(0,6) + L")";
		drawSimpleText(ballVelocity,1000,685);
	}
}

void MatchScreen::drawPanels()
{
	for (int i=0; i<3; i++)
	{
		sf::RectangleShape panel1(sf::Vector2f(PANEL_WIDTH,PANEL_HEIGHT));
		panel1.setPosition( panelPositions[i].x, panelPositions[i].y );
		panel1.setOutlineThickness(1);
		panel1.setOutlineColor(sf::Color::White);
		panel1.setFillColor(sf::Color(255,255,255,180));
		window->draw(panel1);
	}
}

void MatchScreen::drawScoreboard()
{
	// DRAW TIME
	float elapsed = stadium->elapsedSeconds;
	int min =(int)(elapsed/60);
	int sec =(int)elapsed%60;
	wstring timeString = ((min<10)?L"0":L"") + to_wstring(min) + L":" + ((sec<10)?L"0":L"") + to_wstring(sec);
	drawText(timeString,fonts->scoreboard,35,sf::Text::Regular,1250,4,sf::Color::White);

	// DRAW SCOREBOARD
	wstring scoreString0 = stadium->club0->shortName;
	for (int i=0; i<6-scoreString0.length(); i++) scoreString0 += L" ";
	scoreString0 += L":" + to_wstring(stadium->score0);
	drawText(scoreString0,fonts->scoreboard,35,sf::Text::Regular,1000,2,sf::Color::White);

	wstring scoreString1 = stadium->club1->shortName; 
	for (int i=0; i<6-scoreString1.length(); i++) scoreString1 += L" ";
	scoreString1 += L":" + to_wstring(stadium->score1);
	drawText(scoreString1,fonts->scoreboard,35,sf::Text::Regular,1000,2+35+8,sf::Color::White);
}

void MatchScreen::drawButtons()
{
	wstring stringStartPause = paused?langstrings->MATCHSCREEN_0001:langstrings->MATCHSCREEN_0002;
	startPause = drawText(stringStartPause,fonts->regular,10,sf::Text::Regular,1250,70,sf::Color::White);

	wstring stringChangeTactics = langstrings->MATCHSCREEN_0003;
	changeTactics = drawText(stringChangeTactics,fonts->regular,10,sf::Text::Regular,1250,50,sf::Color::White);

}

void MatchScreen::drawCommentator()
{
	window->draw(commentatorBackground);
	commentatorText.setString(stadium->commentator);
	window->draw(commentatorText);
};

bool MatchScreen::ControlMousePressed(float x, float y)
{
	if ( startPause.contains(x,y) )
		paused = !paused;
	else if (changeTactics.contains(x,y) )
		return true;

	return false;
}

void MatchScreen::ControlMouseMoved(float x, float y)
{

};

e_Window MatchScreen::Render()
{
	float mouse_x, mouse_y; wstring ballPosition = L"";
	while (window->isOpen())
	{
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				if (RenderClosing())
					return exitSignal;
			}
			else if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					if( ControlMousePressed(event.mouseButton.x,event.mouseButton.y) )
						return tacticScreen;					
				}
			}
			else if (event.type == sf::Event::MouseMoved && DEBUG_SHOWVALUES)
			{
				ControlMouseMoved(event.mouseMove.x,event.mouseMove.y);
				mouse_x = (event.mouseMove.x-MATCH_PLAYAREA_LEFT)/MATCH_CONST_W;
				mouse_y = (event.mouseMove.y-MATCH_PLAYAREA_TOP)/MATCH_CONST_H;
				ballPosition = L"Mouse Position: (" + to_wstring(mouse_x).substr(0,6) + L"," + to_wstring(mouse_y).substr(0,6) + L")";
			}
		}
		if (!paused) stadium->StepBulletWorld();
		window->clear();
		drawBackground();
		drawStadium();
		drawPanels();
		drawScoreboard();
		drawButtons();
		drawCommentator();
		if(DEBUG_SHOWVALUES) drawSimpleText(ballPosition,500,685);
		window->display();
	}
	return exitSignal;
}