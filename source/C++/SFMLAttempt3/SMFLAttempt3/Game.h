#pragma once
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <memory>
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
#include <functional>
#include "GameMode.h"
#include "SimpleMode.h"
#include "GeneralGame.h"
#include "ComputerBot.h"

class Game {

public:
    Game(std::unique_ptr<GameMode> mode, int rows, int cols );
    void start();
    void initUI();
    void initUIButtons();
    void initLabels();
    void updateUIOnMouseInput(sf::Vector2i mousePos);
    void updateGameButtons(sf::Vector2i mousePos);
    void updateSizeButtons(sf::Vector2i mousePos);
    void updatePlayerMoveUI(sf::Vector2i mousePos);
    void playerOneMoves(int row, int col, std::string gameType);
    void playerTwoMoves(int row, int col, std::string gameType);
    void validateMove(int row, int col, std::string gameType, std::string key, int currPlayer);

private:
    std::unique_ptr<GameMode> mode;
    Grid grid;
    bool simpleEnd = false;
    bool generalEnd = false;
    bool GameRunning = false; 
    bool MainMenu = true;
    bool SimpGame = false;
    bool GenGame = false;
    float width;
    float squareSize; 
    int gridSize; 
    sf::RenderWindow window;
    sf::Event event;
    float CenterGameBoardX;
    float CenterGameBoardY;
    float centerX;
    bool Player1_turn = true;
    bool Player2_turn = false;
    std::string endText = "";

    bool Player1IsHuman = true;
    bool Player2IsHuman = true;
    bool botPresent = false;
    bool botWon = false;
    std::string botEndString;
    
    //UI labels
    Label TitleLable;
    Label SimpleLabel;
    Label GeneralLabel;
    Label ThreebyLabel;
    Label FivebyLabel;
    Label SevenbyLabel;

    Label SimpleLabelend;
    Label GeneralLabelend;
    Label userDirection;

    //Player controls labels
    Label Player1Label;
    Label Player2Label;
    Label Player1S;
    Label Player2S;

    Label HumanLabelP1;
    Label ComputerLabelP1;
    
    Label HumanLabelP2;
    Label ComputerLabelP2;
    
    Label Player1O;
    Label Player2O;
    Label GameEnded;

	RadioButton SimpleGameBtn;
	RadioButton GeneralGameBtn;

    RadioButton SimpleGameBtnend;
    RadioButton GeneralGameBtnend;

	//Game Board size Button 
	RadioButton ThreeByThree;
    RadioButton FiveByFive;
	RadioButton SevenBySeven;
    RadioButtonGroup sizebtns;
	////Player 1 and 2 contro
	//p1
    RadioButton S_moveP1;
    RadioButton O_moveP1;
    RadioButton HumanBtnP1;
    RadioButton ComputerBtnP1;

	//p2
    RadioButton S_moveP2;
    RadioButton O_moveP2;
    RadioButton HumanBtnP2;
    RadioButton ComputerBtnP2;
	//game mode btn group
	RadioButtonGroup ModebtnGroup;
	

	//game board size btn group
	RadioButtonGroup BoardbtnGroup;


	//Player button groups
	//p1
	RadioButtonGroup Player1BtnGroup;

	//p2
	RadioButtonGroup Player2BtnGroup;
   
    SimpleMode simpleGame;
    GeneralMode generalGame;

    
    
    void handleEvents();
    void handleInput(); // handle mouse interaction witht the game
    void updateGameLogic(); //update the game logic
    void render();  //render current game sate
    void RenderMenus(std::string key);
    void renderMainMenu();
    void updateSimpleUI();
    void updateGeneralUI();
    void renderEndScreen(std::string key);
    void clearStatus();
    void makingGameMoves(int row, int col, std::string gameType);
    void checkGameEnd(std::string game);
    void checkGameEndBot(Bot PlayerBot, std::string game);
    void resetBots(Bot PlayerBot);
};



#endif // GAME_H