#pragma once
#ifndef COMPUTERBOT_H
#define COMPUTERBOT_H
#include "SimpleMode.h"
#include "GridClass.h"
#include "GeneralGame.h"


class Bot{

public:
	Bot();

	void initBot(std::shared_ptr<GameMode> modeType);//default constructor , set the starting gameBotmode
	 
	void botMakeMove(Grid& grid, int currPlayersTurn, int gridSize);//bot makes a move using the prior defined move functions of Simple and General
	
	bool isBotGameOver();//checks the state of the game the bot is involved in 

	void resetGame();//reset bot information and game state
	 
	//chooose random move type and move position 
	std::string pickLetter();
	sf::Vector2i chooseGridSpace(Grid& grid, int gridSize);
	
	std::string getEndString(); // Get the final string for the bots game if they win, draw 

	void setGameMode(std::shared_ptr<GameMode> newMode); //change the gamemode dynamically 


private:
	
	std::shared_ptr<GameMode> mode;
};


#endif // COMPUTERBOT_H