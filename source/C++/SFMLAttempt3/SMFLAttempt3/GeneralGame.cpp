#pragma once

#include "GeneralGame.h"
#include "GridClass.h"

void GeneralMode::Rules() {
	std::cout << "General game rules" << std::endl;

	
}


GeneralMode::GeneralMode() {
	//Constructor

}


void GeneralMode::GameOverSos(Grid& grid, int row, int col) {
	//General game is over when the last move is made and the totals are added up in one players favor. 
	
	// Player 1 winds  
	if (P1total > P2total) {
		winner = "Player 1";
		winning_total = P1total;
		std::cout << "General Game has ended, the winner is " << winner << ", Congratulations you have a total of: " << winning_total << std::endl;
		setEndString("General Game has ended, the winner is " + winner + ". Congratulations, you have a total of: " + std::to_string(winning_total)+ " points!");
	}
	//Player 2 wins
	else {
		winner = "Player 2";
		winning_total = P2total;
		std::cout << "General Game has ended, the winner is " << winner << ", Congratulations you have a total of: " << winning_total << std::endl;
		setEndString("General Game has ended, the winner is " + winner + ". Congratulations, you have a total of: "+ std::to_string(winning_total) + " points!");
	}
	grid.ResetGrid();
	GameState = false;
	lastMoveMade = false;

}


void GeneralMode::GameOverDraw(Grid& grid, int row, int col) {
	// general game can end in a draw when all available spots on the board are filled and the totals are equall  

	std::cout << "General Game has ended in a DRAW, good game" << std::endl;
	grid.ResetGrid();
	GameState = false;
	lastMoveMade = false;
	setEndString("General Game has ended in a DRAW. Player 1 total: " + std::to_string(P1total) + ". Player 2 total: " + std::to_string(P2total) + ". Good Game");
	
}


//handles s and o game moves , key == is s or o move 
void GeneralMode::makeMove(Grid& grid, int row, int col, std::string key, int currPlayersTurn, int gridSize) {
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

//check if sos is made 
bool GeneralMode::isSOS(Grid& grid, int row, int col, int gridSize) {
	std::vector<std::vector<int>> gridState = grid.getGridVect();
	int rows = gridSize;
	int cols = gridSize;

	// Check for SOS horizontally, vertically, and diagonally
	for (int r = 0; r < rows; ++r) {
		for (int c = 0; c < cols; ++c) {
			// Check horizontal (to the right)
			if (c + 2 < cols && gridState[r][c] == 1 && gridState[r][c + 1] == 2 && gridState[r][c + 2] == 1) {
				incrementTotals();

				
				
			}
			// Check vertical (downwards)
			else if (r + 2 < rows && gridState[r][c] == 1 && gridState[r + 1][c] == 2 && gridState[r + 2][c] == 1) {
				incrementTotals();

				
			}
			// Check diagonal top-left to bottom-right
			else if (r + 2 < rows && c + 2 < cols && gridState[r][c] == 1 && gridState[r + 1][c + 1] == 2 && gridState[r + 2][c + 2] == 1) {
				incrementTotals();

				
			}
			// Check diagonal top-right to bottom-left
			else if (r + 2 < rows && c - 2 >= 0 && gridState[r][c] == 1 && gridState[r + 1][c - 1] == 2 && gridState[r + 2][c - 2] == 1) {
				incrementTotals();

				
			}
		}
	}
	if (P1total == P2total) {
		if (!lastMoveMade) {
			return false;
		}
		else {
			//game is a draw
			GameOverDraw(grid, row, col);
			return false;
		}
	}
	else if (P1total != P2total) {
		if (!lastMoveMade) {
			
			return false;
		}
		else {
			std::cout << "the game has ended and one player has won" << std::endl;
			GameOverSos(grid, row, col);
			return false;
		}
		
	}
	return false; // No SOS found

}


void GeneralMode::incrementTotals() {
	//if currplayer is player 1
	if (currentPlayer == 1) {
		P1total += 1;
		
	}
	//if currplayer is player 2
	else if (currentPlayer == 2) {
		P2total += 1;
	}

	std::cout <<"player 1: "<< P1total << "  player2: " << P2total << std::endl;

}

bool GeneralMode::isLastMove(Grid& grid, int row, int col, int gridSize) {
	int OpenPositions = gridSize * gridSize;

	for (int r = 0; r < gridSize; r++) {
		for (int c = 0; c < gridSize; c++) {
			if (grid.getCellState(r, c) != 0) {
				OpenPositions -= 1;
				/*std::cout << "this many open pos: " << OpenPositions << std::endl;*/


			}

		}
	}
	if (OpenPositions > 0) {
		std::cout << "this not last move " << std::endl;
		lastMoveMade = false;
		isSOS(grid, row, col, gridSize);
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


//getters-setters
bool GeneralMode::getGameState() {
	return GameState; 
}


void GeneralMode::setEndString(std::string endtext) {
	endingString = endtext;
}


std::string GeneralMode::getEndString() {
	return endingString;
}




void GeneralMode::resetGame() {
	GameState = true;
	P1total = 0;
	P2total = 0;
	winning_total = 0;
	winner = "";
}


