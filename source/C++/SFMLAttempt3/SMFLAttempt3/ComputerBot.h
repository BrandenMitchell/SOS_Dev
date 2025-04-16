#pragma once
#ifndef COMPUTERBOT_H
#define COMPUTERBOT_H
#include "SimpleMode.h"
#include "GridClass.h"
#include "GeneralGame.h"


class Bot{

public:
	//default constructor , set the game mode
	Bot(std::shared_ptr<GameMode> modeType);

	void botMakeMove(Grid& grid, int currPlayersTurn, int gridSize);
	void endGameBot();
	void resetGame();
	void isLastMove(); 
	std::string pickLetter();
	sf::Vector2i chooseGridSpace(Grid& grid, int gridSize);

	void setGameMode(std::shared_ptr<GameMode> newMode);




private:
	std::shared_ptr<GameMode> mode;



//	std::string endingString = "";
//	bool lastMoveMade = false;
//	bool Player1Turn = true;
//	bool Player2Turn = false;
//	//0 for default , otherwise 1 or 2
//	int currentPlayer = 0;
//	// will be set to false when the game is over. 
//	bool GameState = true;

};


#endif // COMPUTERBOT_H