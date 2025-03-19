//#pragma once
//
//
//
//
//#include "UIClass.h"
//#include "RadioButton.h"
//#include "UI_Label.h"
//#include "Game.h"
//#include <vector>
//
//
////default constructor 
//UI::UI(sf::RenderWindow& window) {
//	
//	
//	//ui labels init
//	TitleLable.initLabel(800, 23, "SOS GAME", "Cyan", 60);
//	SimpleLabel.initLabel(60, 23, "Simple Game", "White", 55);
//	GeneralLabel.initLabel(60, 65, "General Game", "Cyan", 55);
//	ThreebyLabel.initLabel(60, 160, "3x3", "Magenta", 35);
//	FivebyLabel.initLabel(160, 160, "5x5 ", "Red", 35);
//	SevenbyLabel.initLabel(260, 160, "7x7 ", "Yellow", 35);
//
//	//player controls init
//	Player1Label.initLabel(23, 200, "Player 1", "White", 30);
//	Player2Label.initLabel(123, 200, "Player 2", "White", 30);
//	Player1S.initLabel(63, 250, "S", "White", 40);
//	Player2S.initLabel(163, 250, "S", "White", 40);
//	Player1O.initLabel(63, 320, "O", "White", 40);
//	Player2O.initLabel(163, 320, "O", "White", 40);
//
//	//gamemode controls
//	SimpleGameBtn.initRadioButton(43, 60, 13, 8);
//	GeneralGameBtn.initRadioButton(43, 100, 13, 8);
//
//	//board selections
//	ThreeByThree.initRadioButton(43, 160, 11, 8);
//	FiveByFive.initRadioButton(143, 160, 11, 8);
//	SevenBySeven.initRadioButton(243, 160, 11, 8);
//
//
//	//player move btn labels
//	S_moveP1.initRadioButton(43, 280, 11, 8);
//	O_moveP1.initRadioButton(43, 350, 11, 8);
//	//----------------------------------------//
//	S_moveP2.initRadioButton(143, 280, 11, 8);
//	O_moveP2.initRadioButton(143, 350, 11, 8);
//}
//
//void UI::handleUIinput() {
//	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
//		
//	}
//}