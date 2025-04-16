#include "ComputerBot.h"
#include <random>





Bot::Bot(std::shared_ptr<GameMode> modeType) {
	mode = modeType;

}



std::string  Bot::pickLetter() {
	static std::random_device rd;
	static std::mt19937 gen(rd()); // Mersenne Twister engine
	static std::uniform_int_distribution<> dist(0, 1); // Only 0 or 1

	int randomValue = dist(gen); // Randomly get 0 or 1
	return (randomValue == 0) ? "s" : "o"; // Choose 'S' or 'O'
}


sf::Vector2i Bot::chooseGridSpace(Grid& grid, int gridSize) {
	std::vector<std::vector<int>>  openPositions;
	sf::Vector2i randomGridPos;

	for (int r = 0; r < gridSize; r++) {
		for (int c = 0; c < gridSize; c++) {
			if (grid.getCellState(r, c) == 0) {
				openPositions.push_back(std::vector<int>({r, c}));
			}
		}
	}
	if (!openPositions.empty()) {
		static std::random_device rd;
		static std::mt19937 gen(rd());
		std::uniform_int_distribution <> dist(0, openPositions.size() - 1);
		int position = dist(gen);

		
		int row = openPositions[position][0];
		int col = openPositions[position][1];
		sf::Vector2i randomPos(row, col);
		return randomPos;
	}
	std::cout << "grid full " << std::endl;
}



void Bot::botMakeMove(Grid& grid, int currPlayersTurn, int gridSize) {
	//for bot to move we need to get a random spot on the grid, pick a letter, 
	std::string key = pickLetter();
	std::cout << "letter selected" << std::endl;
	sf::Vector2i gridPos = chooseGridSpace(grid, gridSize);
	std::cout << "random pos selected" << std::endl;

	mode->makeMove(grid, gridPos.x, gridPos.y, key, currPlayersTurn, gridSize);

}
void Bot::endGameBot() {

}
void Bot::resetGame() {

}
void Bot::isLastMove() {

}

void Bot::setGameMode(std::shared_ptr<GameMode> newMode) {
	mode = newMode;
}
