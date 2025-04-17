#pragma once
#ifndef GENERALGAME_H
#define GENERALGAME_H

#include "GameMode.h"
#include "GridClass.h"

class GeneralMode : public GameMode {

public:
	GeneralMode();
	void Rules() override;
	void GameOverSos(Grid& grid, int row, int col) override; //checks win condition
	void GameOverDraw(Grid& grid, int row, int col) override; //checks win condition
	void makeMove(Grid& grid, int row, int col, std::string key, int currPlayersTurn, int gridSize) override; //handles s and o game moves , key == is s or o move 
	bool isSOS(Grid& grid, int row, int col, int gridSize) override; //check if sos is made 
	bool isLastMove(Grid& grid, int row, int col, int gridSize) override;
	bool getGameState() override;
	void setEndString(std::string endtext) ;
	std::string getEndString() override;
	void resetGame() override;
	void incrementTotals();


private:
	//track the total for each player
	int P1total = 0;
	int P2total = 0;
	int winning_total = 0;
	std::string winner;
	//ending statement (gets rendered by main game window) 
	std::string endingString = "";
	//curr player and turns, last move tracker and game state
	bool lastMoveMade = false;
	bool Player1Turn = true;
	bool Player2Turn = false;
	
	
	//0 for default , otherwise 1 or 2
	int currentPlayer = 0;
	// will be set to false when the game is over. 
	bool GameState = true;

};


#endif // GENERALGAME_H
