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

	if (col - 1 >= 0 && col + 1 < cols) {
		if (gridState[row][col - 1] == 1 && gridState[row][col] == 2 && gridState[row][col + 1] == 1) {
			incrementTotals();
			std::cout << "SOS formed horizontally at (" << row << ", " << col << ")\n";
		}
	}
	if (col + 2 < cols) {
		if (gridState[row][col] == 1 && gridState[row][col + 1] == 2 && gridState[row][col + 2] == 1) {
			incrementTotals();
			std::cout << "SOS formed horizontally at (" << row << ", " << col << ")\n";
		}
	}
	if (col - 2 >= 0) {
		if (gridState[row][col-2] == 1 && gridState[row][col - 1] == 2 && gridState[row][col ] == 1) {
			incrementTotals();
			std::cout << "SOS formed horizontally at (" << row << ", " << col << ")\n";
		}
	}

	// Vertical: check if "S O S" is formed at the current column (top-down)
	if (row - 1 >= 0 && row + 1 < rows) {
		if (gridState[row - 1][col] == 1 && gridState[row][col] == 2 && gridState[row + 1][col] == 1) {
			incrementTotals();
			std::cout << "SOS formed vertically at (" << row << ", " << col << ")\n";
		}
	}
	if (row + 2 < rows ) {
		if (gridState[row][col] == 1 && gridState[row + 1][col] == 2 && gridState[row + 2][col] == 1) {
			incrementTotals();
		}
		

	}
	if (row - 2 >= 0) {
		if (gridState[row-2][col] == 1 && gridState[row - 1][col] == 2 && gridState[row][col] == 1) {
			incrementTotals();
		}
	}

	// Diagonal (top-left to bottom-right): check if "S O S" is formed
	if (row - 1 >= 0 && col - 1 >= 0 && row + 1 < rows && col + 1 < cols) {
		if (gridState[row - 1][col - 1] == 1 && gridState[row][col] == 2 && gridState[row + 1][col + 1] == 1) {
			incrementTotals();
			std::cout << "SOS formed diagonally (top-left to bottom-right) at (" << row << ", " << col << ")\n";
		}
	}
	if (row + 2 < rows && col + 2 < cols) {
		if (gridState[row][col] == 1 && gridState[row +1][col + 1] == 2 && gridState[row + 2][col + 2] == 1) {
			incrementTotals();
			std::cout << "SOS formed diagonally (top-left to bottom-right) at (" << row << ", " << col << ")\n";
		}
	}
	if (row - 2 >= 0 && col - 2 >= 0) {
		if (gridState[row-2][col-2] == 1 && gridState[row - 1][col - 1] == 2 && gridState[row][col] == 1) {
			incrementTotals();
			std::cout << "SOS formed diagonally (top-left to bottom-right) at (" << row << ", " << col << ")\n";
		}
	}
	// Diagonal (top-right to bottom-left): check if "S O S" is formed
	if (row - 1 >= 0 && col + 1 < cols && row + 1 < rows && col - 1 >= 0) {
		if (gridState[row - 1][col + 1] == 1 && gridState[row][col] == 2 && gridState[row + 1][col - 1] == 1) {
			incrementTotals();
			std::cout << "SOS formed diagonally (top-right to bottom-left) at (" << row << ", " << col << ")\n";
		}
	}
	if (row -2 >= 0 and col +2 < cols) {
		if (gridState[row][col] == 1 && gridState[row - 1][col + 1] == 2 && gridState[row - 2][col + 2]) {
			incrementTotals();
			std::cout << "SOS formed diagonally (top-right to bottom-left) at (" << row << ", " << col << ")\n";
		}
	}
	if (col - 2 >= 0 and row + 2 < rows) {
		if (gridState[row+2][col-2] == 1 && gridState[row + 1][col - 1] == 2 && gridState[row][col]) {
			incrementTotals();
			std::cout << "SOS formed diagonally (top-right to bottom-left) at (" << row << ", " << col << ")\n";
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


