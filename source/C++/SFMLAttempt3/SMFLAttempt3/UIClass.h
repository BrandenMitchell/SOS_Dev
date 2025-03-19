
//#pragma once
//#ifndef UIClass_H
//#define UIClass_H
//
//#include <SFML/Graphics.hpp>
//#include  <SFML/Graphics.hpp>
//#include <SFML/Graphics/Text.hpp>
//#include <SFML/Graphics/Font.hpp>
//#include <string>
//#include <vector>
//#include <iostream>
//#include "UI_Label.h"
//#include "RadioButton.h"
//#include "RadioButtonGroup.h"
//#include "Game.h"
//
//
//
//class UI {
//
//public:
//    UI(sf::RenderWindow& window);
//
//    void updateUI();
//    void handleUIinput();
//    void renderUI();
//
//
//
//
//
//private:
//    
//    sf::RenderWindow window;
//    sf::Event event;
//
//
//    //UI labels
//    Label TitleLable;
//    Label SimpleLabel;
//    Label GeneralLabel;
//    Label ThreebyLabel;
//    Label FivebyLabel;
//    Label SevenbyLabel;
//    //Player controls labels
//    Label Player1Label;
//    Label Player2Label;
//    Label Player1S;
//    Label Player2S;
//    Label Player1O;
//    Label Player2O;
//
//
//    RadioButton SimpleGameBtn;
//    RadioButton GeneralGameBtn;
//
//
//    //Game Board size Button 
//    RadioButton ThreeByThree;
//    RadioButton FiveByFive;
//    RadioButton SevenBySeven;
//
//    ////Player 1 and 2 contro
//    //p1
//    RadioButton S_moveP1;
//    RadioButton O_moveP1;
//    //p2
//    RadioButton S_moveP2;
//    RadioButton O_moveP2;
//
//    //game mode btn group
//    RadioButtonGroup ModebtnGroup;
//
//
//    //game board size btn group
//    RadioButtonGroup BoardbtnGroup;
//
//
//    //Player button groups
//    //p1
//    RadioButtonGroup Player1BtnGroup;
//
//    //p2
//    RadioButtonGroup Player2BtnGroup;
//
//};
//
//#endif // UIClass_H