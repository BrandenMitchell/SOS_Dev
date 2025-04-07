#pragma once

#include "SimpleMode.h"

SimpleMode::SimpleMode() {
	//inits here 

}



void SimpleMode::Rules() {

	std::cout << "simple Game rules" << std::endl;
    
}

bool SimpleMode::isSOS(Grid& grid, int row, int col, int gridSize) {
	std::vector<std::vector<int>> gridState = grid.getGridVect();
	int rows = gridSize;
	int cols = gridSize;

	// Check for SOS horizontally, vertically, and diagonally
	for (int r = 0; r < rows; ++r) {
		for (int c = 0; c < cols; ++c) {
			// Check horizontal (to the right)
			if (c + 2 < cols && gridState[r][c] == 1 && gridState[r][c + 1] == 2 && gridState[r][c + 2] == 1){
				GameOverSos(grid, row, col);

				return true;
			}
			// Check vertical (downwards)
			if (r + 2 < rows && gridState[r][c] == 1 && gridState[r + 1][c] == 2 && gridState[r + 2][c] == 1){
				GameOverSos(grid, row, col);
				return true;
			}
			// Check diagonal top-left to bottom-right
			if (r + 2 < rows && c + 2 < cols && gridState[r][c] == 1 && gridState[r + 1][c + 1] == 2 && gridState[r + 2][c + 2] == 1) {
				GameOverSos(grid, row, col);
				return true;
			}
			// Check diagonal top-right to bottom-left
			if (r + 2 < rows && c - 2 >= 0 && gridState[r][c] == 1 && gridState[r + 1][c - 1] == 2 && gridState[r + 2][c - 2] == 1) {
				GameOverSos(grid, row, col);
				return true;
			}
		}
	}
	if (lastMoveMade) {
		GameOverDraw(grid, row, col);

	}
	return false; // No SOS found
	
}

//checks if the last move of the game has been made *in a simple game*
bool SimpleMode::isLastMove(Grid& grid, int row, int col, int gridSize) {


	int OpenPositions = gridSize * gridSize;

	for (int r = 0; r < gridSize; r++) {
		for (int c = 0; c < gridSize; c++) {
			if (grid.getCellState(r, c) != 0) {
				OpenPositions -= 1;
				std::cout << "this many open pos: " << OpenPositions << std::endl;


			}

		}
	}
	if (OpenPositions > 0) {
		std::cout << "this not last move " << std::endl;
		
		isSOS(grid, row, col, gridSize);
		/*GameState = true;*/
		return false; 

	}
	else {
		std::cout << "this is last move stop" << std::endl;
		lastMoveMade = true;
		GameState = false;
		isSOS(grid, row, col, gridSize);
		return true;
	}
}

void  SimpleMode::GameOverDraw(Grid& grid, int row, int col) {
	// or simple game can end when all available spots on the board are filled. 

	std::cout << "Simple Game has ended in a DRAW, good game" << std::endl;
	grid.ResetGrid();
	setEndString("Simple Game has ended in a DRAW, good game");
	GameState = false;
	lastMoveMade = false;
}


void SimpleMode::GameOverSos(Grid& grid, int row, int col) {
	//simple game is over when the last made move results in an sos being formed 
	
	
	std::cout << "Simple Game has ended, the winner is Player: " << currentPlayer <<". Congratulations"<< std::endl;
	grid.ResetGrid();
	setEndString("Simple Game has ended, the winner is Player: "+ std::to_string(currentPlayer) + ". Congratulations");
	GameState = false;

	


}

void SimpleMode::resetGame() {
	GameState = true;
}


//what logic do we want to track every move?
//--- is this the last available spot on the grid? 
//		since its simple game if this is last available spot the game will also be a draw
// 
//---- Does this form an SOS?
//			since its simple game if it forms an sos the game is over and the current player wins 
void SimpleMode::makeMove(Grid& grid, int row, int col, std::string key, int currPlayersTurn,int gridSize) {

	//update the current player variable, should either be 1 or 2
	currentPlayer = currPlayersTurn;

	
	// make s  
	if (key == "s") {
		std::cout << "S move" << std::endl;
		grid.setCellState(row, col, 1);

	}

	// make o 
	else if (key == "o") {
		std::cout << "O move" << std::endl;
		grid.setCellState(row, col, 2);

	}
	//key failure protection
	else {
		std::cout << "key failed" << std::endl;
	}
	//check if its the last possible move in the game 
	// inside this we also check for the presence of an os
	isLastMove(grid, row, col, gridSize);
	
}



bool SimpleMode::getGameState() {
	return GameState;
}


void SimpleMode::setEndString(std::string endtext) {
	endingString = endtext;


}


std::string SimpleMode::getEndString() {
	return endingString;

	
}



