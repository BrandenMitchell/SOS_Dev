#pragma once
#ifndef SIMPLEMODE_H
#define SIMPLEMODE_H

#include "GameMode.h"
#include "GridClass.h"

class SimpleMode : public GameMode {

public:
	//default constructor 
	SimpleMode();
	void Rules() override;
	void GameOverSos(Grid& grid, int row, int col) override; //checks win condition
	void GameOverDraw(Grid& grid, int row, int col) override; //checks win condition
	void makeMove(Grid& grid, int row, int col, std::string key, int currPlayersTurn, int gridSize) override; //handles s and o game moves , key == is s or o move 
	bool isSOS(Grid& grid, int row, int col, int gridSize) override; //check if sos is made 
	bool isLastMove(Grid& grid, int row, int col, int gridSize) override;
	bool getGameState();
	void setEndString(std::string endtext);
	std::string getEndString();
	void renderEndScreen(sf::RenderWindow& window) override;
	void resetGame() override; 





private:
	int total = 0;
	std::string endingString ="";
	bool lastMoveMade = false;
	bool Player1Turn = true;
	bool Player2Turn = false;
	//0 for default , otherwise 1 or 2
	int currentPlayer = 0;
	// will be set to false when the game is over. 
	bool GameState = true;

};


#endif // SIMPLEMODE_H