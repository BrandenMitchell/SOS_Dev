#pragma once

#include "SFML/Graphics.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <vector>
#include <string>
#include "GridClass.h"
#include <map>
//grid class 

//constructor here 
//rows, cols will be given to determine the size of the game board, the value is what to make the value of each cell (default is 0 which is none)
Grid::Grid(int rows, int cols,float width, float height) : rows(rows), cols(cols), width(width),height(height) {
	//enables grid to have rows, and cols. all set to 0 by default
	grid.resize(rows, std::vector<int>(cols, 0));

	if (!font.loadFromFile("include/Pixellettersfull-BnJ5.ttf")) {
		std::cerr << "Error loading font!" << std::endl;
	}
	text.setFillColor(sf::Color::White);
	text.setFont(font);
	text.setCharacterSize(70);
	
}


//getters and setters


void Grid::ResetGrid() {
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			if (grid[r][c] == 1 || grid[r][c] == 2) {
				grid[r][c] = 0;
			}
		}
	}
}

void Grid::setCellState(int row, int col, int value) {
	//if in grid bounds set the grid cell at those coordinates to given 
	if (row >= 0 && row < rows && col >= 0 && col < cols) {
		grid[row][col] = value;

	}
}

int Grid::getCellState(int row, int col) const {
	//if in grid bounds return requested cell state
	if (row >= 0 && row < rows && col >= 0 && col < cols) {
		return grid[row][col];

	}
	//returns -1 if invalid range
	return -1;
}

//Gives me state of entire grid

std::vector<std::vector<int>> Grid::getGridVect() {
	
	/*for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {

			std::cout << "Row: " << r << "Col: " << c << getCellState(r, c) << std::endl;
		

		}
	}*/
	return grid;

}

std::vector<int> Grid::getDimensions() {
	std::vector <int> boardDimensions;
	float boardSize = rows;

	//list contains size (rows and cols) , width, height
	boardDimensions.push_back(boardSize);
	boardDimensions.push_back(width);
	boardDimensions.push_back(height);
	
	return boardDimensions;


}

float Grid::getWidth() {
	return width;
}


float Grid::getHeight() {
	return height;
}



//Draw game Board
void Grid::drawCells(sf::RenderWindow& window, float squareSize, float gridSize, float centerX, float centerY, float gridWidth) {
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

sf::Color Grid::get_Color(const std::string& color) {
	static const std::map<std::string, sf::Color> colorMap = {
		{"Red", sf::Color::Red},
		{"Green", sf::Color::Green},
		{"Blue", sf::Color::Blue},
		{"Black", sf::Color::Black},
		{"White", sf::Color::White},
		{"Yellow", sf::Color::Yellow},
		{"Magenta", sf::Color::Magenta},
		{"Cyan", sf::Color::Cyan}

	};
	auto it = colorMap.find(color);
	if (it != colorMap.end()) {
		return it->second;
	}
	else {
		// Return a default color (e.g., black) if the color is not found
		return sf::Color::Black;
	}

}
void Grid::setS_OColor(std::string color) {
	sf::Color S_OCol = get_Color(color);
	text.setFillColor(S_OCol);

}


//draw S and O 
void Grid::drawS_O(sf::RenderWindow& window, float squareSize, float centerX, float centerY) {
	
	for (int row = 0; row < rows; row++) {

		for (int col = 0; col < cols; col++) {
			//equal to 1 we draw S
			sf::Vector2f cellPos(centerX + col * squareSize, centerY + row * squareSize);
			if (grid[row][col] == 1) {
				text.setString("S");
				text.setFillColor(sf::Color::Green);
				text.setPosition(cellPos + sf::Vector2f(squareSize / 4, squareSize / 4));
				window.draw(text);

			}
			//equal to 2 we draw O
			else if (grid[row][col] == 2) {
				text.setString("O");
				text.setFillColor(sf::Color::Red);
				text.setPosition(cellPos + sf::Vector2f(squareSize / 4, squareSize / 4));
				window.draw(text);

			}
			
		}
	}


}



