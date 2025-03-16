#pragma once

#include "SFML/Graphics.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <vector>
#include <string>

//grid class 
class Grid {


public:
	//constructor here 
	//rows, cols will be given to determine the size of the game board, the value is what to make the value of each cell (default is 0 which is none)
	Grid(int rows, int cols, float width, float height);


	//getters and setters
	float getWidth();

	float getHeight();
	
	void ResetGrid();

	void setCellState(int row, int col, int value);
	int getCellState(int row, int col) const;

	//Gives me state of entire grid

	void getGridVect(int rows, int cols);

	std::vector<int> getDimensions();


	//Draw game Board
	void drawCells(sf::RenderWindow& window, float squareSize, float gridSize, float centerX, float centerY, float gridWidth);
	//draw S and O 
	void drawS_O(sf::RenderWindow& window, float squareSize, float centerX, float centerY);


private:
	//private vars for class 
	//rows, cols will be given to determine the size of the game board, the value is what to make the value of each cell (default is 0 which is none)
	int rows, cols;
	float width, height;

	// in my gridState 0 is none , 1 is S, 2 is O 
	int value = 0;
	//this is a vector of integers called grid (will hold game board state)
	std::vector<std::vector<int>> grid;
	sf::Font font;



};
