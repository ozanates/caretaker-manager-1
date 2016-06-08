#ifndef STYLE_GENERAL
#define STYLE_GENERAL

/* General styles
 *
 *
 *
 */

#define SCALE_H (((window->getSize().x)*1.0)/1366)
#define SCALE_V (((window->getSize().y)*1.0)/768)

/// MAIN SCREEN BUTTON SIZES

#define BUTTON_MAIN_FIRST_LEFT (183*SCALE_H)					// Horizontal positon of main buttons
#define BUTTON_MAIN_FIRST_WIDTH (400*SCALE_H)					// Width of main buttons
#define BUTTON_MAIN_FIRST_HEIGHT (100*SCALE_V)				// Height of main buttons

///// Button Color & Text Style

#define BUTTON1_OUTSIDE_COLOR sf::Color::Transparent
#define BUTTON1_INSIDE_COLOR sf::Color::Transparent
#define BUTTON1_THICKNESS 2
#define BUTTON1_TEXT_COLOR sf::Color(255,138,0) //sf::Color(0,255,138)

#define BUTTON1_HOVERED_OUTSIDE_COLOR sf::Color::Transparent
#define BUTTON1_HOVERED_INSIDE_COLOR sf::Color(93,138,138,80)
#define BUTTON1_HOVERED_THICKNESS 4
#define BUTTON1_HOVERED_TEXT_COLOR sf::Color::White

#define BUTTON1_TEXT_SIZE (50*SCALE_V)
#define BUTTON1_TEXT_MARGIN ((BUTTON_MAIN_FIRST_HEIGHT - BUTTON1_TEXT_SIZE)*SCALE_V/2-10)

///// HEADER

#define HEADER_REC_WIDTH 1250*SCALE_H
#define HEADER_REC_HEIGHT 70*SCALE_V
#define HEADER_REC_TOP 20*SCALE_V

#define HEADER_INSIDE_COLOR sf::Color(50,0,0)
#define HEADER_OUTSIDE_COLOR sf::Color::Transparent

#define TEXT_TACTIC_HEADER_SIZE 40*SCALE_V
#define TEXT_TACTIC_HEADER_LEFT 400*SCALE_H
#define TEXT_TACTIC_HEADER_TOP 30*SCALE_V

///// EXIT

#define BUTTON_MAIN_EXIT_AREYOUSURE_TOP (468*SCALE_V)
#define BUTTON_MAIN_EXIT_YESNO_WIDTH (150*SCALE_H)
#define BUTTON_MAIN_EXIT_YESNO_HEIGHT (100*SCALE_V)
#define BUTTON_MAIN_EXIT_YESNO_TOP (618*SCALE_V)
#define BUTTON_MAIN_EXIT_YES_LEFT (783*SCALE_H)	
#define BUTTON_MAIN_EXIT_NO_LEFT (983*SCALE_H)	

#define BUTTON_MAIN_SECOND_LEFT (783*SCALE_H)					// Horizontal position of side buttons
#define BUTTON_MAIN_SECOND_WIDTH (400*SCALE_H)				// Width of side buttons
#define BUTTON_MAIN_SECOND_HEIGHT (80*SCALE_V)				// Height of side buttons

#endif