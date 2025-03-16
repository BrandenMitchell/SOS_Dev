#pragma once
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "GameMode.h"

#include  <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <string>
#include <vector>
#include <iostream>
#include "GridClass.h"
#include "UI_Label.h"
#include "RadioButton.h"
#include "RadioButtonGroup.h"
#include "Game.h"
#include "SimpleMode.h"
#include "GeneralGame.h"


class Game {

public:
    Game(std::unique_ptr<GameMode> mode, int rows, int cols );
    void start();


    

private:
    std::unique_ptr<GameMode> mode;
    Grid grid;
    float squareSize; 
    sf::RenderWindow window;
    sf::Event event;
    float CenterGameBoardX;
    float CenterGameBoardY;
    float centerX;

    //UI labels
    Label TitleLable;
    Label SimpleLabel;
    Label GeneralLabel;
    Label ThreebyLabel;
    Label FivebyLabel;
    Label SevenbyLabel;
    //Player controls labels
    Label Player1Label;
    Label Player2Label;
    Label Player1S;
    Label Player2S;
    Label Player1O;
    Label Player2O;


	RadioButton SimpleGameBtn;
	RadioButton GeneralGameBtn;


	//Game Board size Button 
	RadioButton ThreeByThree;
    RadioButton FiveByFive;
	RadioButton SevenBySeven;

	////Player 1 and 2 contro
	//p1
    RadioButton S_moveP1;
    RadioButton O_moveP1;
	//p2
    RadioButton S_moveP2;
    RadioButton O_moveP2;

	//game mode btn group
	RadioButtonGroup ModebtnGroup;
	

	//game board size btn group
	RadioButtonGroup BoardbtnGroup;


	//Player button groups
	//p1
	RadioButtonGroup Player1BtnGroup;

	//p2
	RadioButtonGroup Player2BtnGroup;
	
    
    

    void handleEvents();
    void handleInput(); // handle mouse interaction witht the game
    void updateGameLogic(); //update the game logic
    void render();  //render current game sate
};

#endif // GAME_H