#pragma once
#ifndef GAMEMODE_H
#define GAMEMODE_H
#include <iostream>
#include "GridClass.h"
#include "UI_Label.h"


class GameMode {

public:
	//virtual function to apply the two gamemodes we will have, Gamemodes will be easy to plug and play
	//defined in their own classes

	virtual void Rules() = 0;
	virtual void GameOverSos(Grid& grid, int row, int col) = 0; //checks win condition
	virtual void GameOverDraw(Grid& grid, int row, int col) = 0; //checks win condition
	virtual void makeMove(Grid& grid, int row, int col, std::string key,int currPlayersTurn, int gridSize) = 0; //handles s and o game moves 
	virtual bool isSOS(Grid& grid, int row, int col, int gridSize) = 0; //check if sos is made 
	virtual bool isLastMove(Grid& grid, int row, int col, int gridSize) = 0; //check if last possible move is made
	virtual void resetGame() =0 ; //reset game state


	//destructor
	virtual ~GameMode() = default;

private:

	int total = 0;
	bool Player1Turn = true;
	bool Player2Turn = false;
	

	// will be set to false when the game is over. 
	bool GameState = true; 

	
};

	
 
#endif // GAMEMODE_H 
