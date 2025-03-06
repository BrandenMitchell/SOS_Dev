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
	Grid(int rows, int cols) : rows(rows), cols(cols)  {
		//enables grid to have rows, and cols. all set to 0 by default
		grid.resize(rows, std::vector<int>(cols, 0));
	
		if (!font.loadFromFile("include/Pixellettersfull-BnJ5.ttf")) {
			std::cerr << "Error loading font!" << std::endl;
		}
		

	}


	//getters and setters

	

	void setCellState(int row, int col, int value) {
		//if in grid bounds set the grid cell at those coordinates to given 
		if (row >= 0 && row < rows && col >= 0 && col < cols) {
			grid[row][col] = value;

		}
	}

	int getCellState(int row, int col) const {
		//if in grid bounds return requested cell state
		if (row >= 0 && row < rows && col >= 0 && col < cols) {
			return grid[row][col];

		}
		//returns -1 if invalid range
		return -1;
	}

	//Gives me state of entire grid

	void getGridVect(int rows, int cols) {
		for (int r = 0; r < rows; r++) {
			for (int c = 0; c < cols; c++) {
			
				std::cout <<"Row: "<<r<<"Col: "<<c<< getCellState(r, c) << std::endl;
			
			}
		}
	}



	//Draw game Board
	void drawCells(sf::RenderWindow& window, float squareSize, float gridSize, float centerX, float centerY, float gridWidth) {
		//creates a grid cell, size of the square size 
		sf::RectangleShape cell(sf::Vector2f(squareSize, squareSize));

		for (int row = 0; row < gridSize; row++) {
			for (int col = 0; col < gridSize; col++) {
				//define center offset
				float offsetX = centerX;

				float offsetY = centerY;
				//set pos
				cell.setPosition(offsetX + col * squareSize, offsetY + row * squareSize);

				//customize game board
				cell.setFillColor(sf::Color::Transparent);
				cell.setOutlineColor(sf::Color::Cyan);
				cell.setOutlineThickness(1.f);
				//draw cell 
				window.draw(cell);


				//inside the DrawCells Function we will check 
			}

		}
		//call func to draw S and O 
		drawS_O(window, squareSize, centerX, centerY);


	}

	//draw S and O 
	void drawS_O(sf::RenderWindow& window, float squareSize, float centerX, float centerY) {
		sf::Text text("",font,50);
		for (int row = 0; row < rows; row++) {

			for (int col = 0; col < cols; col++) {
				//equal to 1 we draw S
				sf::Vector2f cellPos(centerX + col * squareSize, centerY + row * squareSize);

				if (grid[row][col] == 1) {
					text.setString("S");
					text.setFillColor(sf::Color::Red);
					text.setPosition(cellPos + sf::Vector2f(squareSize / 4, squareSize / 4));
					window.draw(text);

				}
				//equal to 2 we draw O
				else if (grid[row][col] == 2) {
					text.setString("O");
					text.setFillColor(sf::Color::Blue);
					text.setPosition(cellPos + sf::Vector2f(squareSize / 4, squareSize / 4));
					window.draw(text);

				}
			}
		}


	}


private:
	//private vars for class 
	//rows, cols will be given to determine the size of the game board, the value is what to make the value of each cell (default is 0 which is none)
	int rows, cols;

	// in my gridState 0 is none , 1 is S, 2 is O 
	int value = 0;
	//this is a vector of integers called grid (will hold game board state)
	std::vector<std::vector<int>> grid;
	sf::Font font;



};
