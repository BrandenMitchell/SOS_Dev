//Cleaned up SOS development
//Branden Mitchell 


//includes
#pragma once
#include  <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <string>
#include <vector>
#include <iostream>
#include "GridClass.h"
#include "UI_Label.h"
#include "RadioButton.h"
#include "RadioButtonGroup.h"
#include "Game.h"
#include "SimpleMode.h"
#include "GeneralGame.h"

//using namespace std;



//function declaration and definitions



//draws O ---NEEDS FINISHED
//void draw_O(sf::RenderWindow& window, float circlePosX, float circlePosY) {
//	 
//	
//	sf::CircleShape O(5.f);
//	//set pos of circle 
//	O.setPosition(circlePosX,circlePosY);
//	O.setOutlineColor(sf::Color::Blue);
//
//	window.draw(O);
//
//
//}
//
////draws S ---NEEDS FINISHED
//void draw_S(sf::RenderWindow& window, float textPosX, float textPosY) {
//	sf::Text text; 
//	text.setPosition(textPosX, textPosY);
//	text.setFillColor(sf::Color::Red);
//	window.draw(text);
//
//
//}
//
////handles mouse clicks ---NEEDS FINISHED Probably need a game board class bc i need access to the cells to check if they are in bounds 
//void handleClick(sf::RenderWindow& window,float mouseX, float mouseY) {
//
//
//}








//MainLoop
int main(){
	//Setting up window
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SOS Board Game");
	window.setFramerateLimit(60);

	//-------------Declarations-----------------\\
	
	
	Game SimpGame(std::make_unique<SimpleMode>());
	Game GenGame(std::make_unique<GeneralMode>());

	//game board

	
	float gridSize = 8.f; //game board dimensions 3x3, 6x6 etc
	float gridWidth = 800; //game board width
	float gridHeight = 800; //game board height
	
	float squareSize = gridWidth / gridSize; //cell size
	Grid grid(gridSize, gridSize);

	//finding center of board
	float CenterGameBoardX = window.getSize().x / 2.f - gridWidth / 2.f;
	float CenterGameBoardY = window.getSize().y / 2.f - gridHeight / 2.f;
	
	//Players init
	bool Player1_turn = true;
	bool Player2_turn = false;



	//---------------- UI elements  -----------------\\	
	Label SimpleLabel(60,23, "Simple Game", "White", 55);
	Label GeneralLabel(60,65, "General Game", "Cyan", 55);
	Label ThreebyLabel(60,160, "3x3", "Magenta", 35);
	Label FivebyLabel(160, 160, "5x5 ", "Red", 35);
	Label SevenbyLabel(260, 160, "7x7 ", "Yellow", 35);

	RadioButton SimpleGameBtn(43, 60, 13, 8);
	RadioButton GeneralGameBtn(43, 100, 13, 8);
	RadioButton ThreeByThree(43, 160, 11, 8);
	RadioButton FiveByFive(143, 160, 11, 8);
	RadioButton SevenBySeven(243, 160, 11, 8);

	RadioButtonGroup ModebtnGroup;
	ModebtnGroup.addRadioButton(&GeneralGameBtn);
	ModebtnGroup.addRadioButton(&SimpleGameBtn);

	RadioButtonGroup BoardbtnGroup;
	BoardbtnGroup.addRadioButton(&ThreeByThree);
	BoardbtnGroup.addRadioButton(&FiveByFive);
	BoardbtnGroup.addRadioButton(&SevenBySeven);



	//---------------- declarations  -----------------\\


	



	// Create Game loop
	while(window.isOpen()) {

		

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
				


			}
			if (event.type == sf::Event::Resized) {
				//on resize update the window area / size
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				window.setView(sf::View(visibleArea));

			

				//on resize update the center for the game grid
				CenterGameBoardX = event.size.width / 2.f - gridWidth / 2.f;
				CenterGameBoardY = event.size.height / 2.f - gridHeight / 2.f;
				

				//calculate square size on resize
				squareSize = gridWidth/ gridSize;




			}
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
				
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				
			/*	ThreeByThree.handleClick(mousePos.x, mousePos.y);
				FiveByFive.handleClick(mousePos.x, mousePos.y);
				SevenBySeven.handleClick(mousePos.x, mousePos.y);*/

				if (SimpleGameBtn.handleClick(event.mouseButton.x, event.mouseButton.y)) {
					// Ensure only one button is active at a time
					GeneralGameBtn.setState(false);
					GeneralGameBtn.setInnerColor("Transparent");
					SimpleLabel.set_labelColor("Green");
					GeneralLabel.set_labelColor("Cyan");


				}
				else if (GeneralGameBtn.handleClick(event.mouseButton.x, event.mouseButton.y)) {
					SimpleGameBtn.setState(false);
					SimpleGameBtn.setInnerColor("Transparent");
					SimpleLabel.set_labelColor("White");

					GeneralLabel.set_labelColor("Green");

				}
				if (!SimpleGameBtn.getState()) {
					SimpleLabel.set_labelColor("White");

				}
				if (!GeneralGameBtn.getState()) {
					GeneralLabel.set_labelColor("Cyan");

				}


				if (ThreeByThree.handleClick(mousePos.x, mousePos.y)) {
					// Ensure only one button is active at a time
					SevenBySeven.setState(false);
					FiveByFive.setState(false);
					SevenBySeven.setInnerColor("Transparent");
					FiveByFive.setInnerColor("Transparent");
					ThreebyLabel.set_labelColor("White");


				}
				else if (FiveByFive.handleClick(mousePos.x, mousePos.y)) {
					SevenBySeven.setState(false);
					ThreeByThree.setState(false);
					SevenBySeven.setInnerColor("Transparent");
					ThreeByThree.setInnerColor("Transparent");
					FivebyLabel.set_labelColor("White");

				
				}
				else if (SevenBySeven.handleClick(mousePos.x, mousePos.y)) {
					FiveByFive.setState(false);
					ThreeByThree.setState(false);
					FiveByFive.setInnerColor("Transparent");
					ThreeByThree.setInnerColor("Transparent");
					SevenbyLabel.set_labelColor("White");

				}
				if (!ThreeByThree.getState()) {
					ThreebyLabel.set_labelColor("Magenta");

				}
				if (!FiveByFive.getState()) {
					FivebyLabel.set_labelColor("Red");

				}
				if (!SevenBySeven.getState()) {
					SevenbyLabel.set_labelColor("Yellow");

				}
				

				
					
				
				
				std::cout << "btn1 state is: " << SimpleGameBtn.getState() << std::endl;
				std::cout << "btn2 state is: " << GeneralGameBtn.getState() << std::endl;
				

				std::cout << "mouse is alive" << mousePos.x << mousePos.y << std::endl;
				if (mousePos.x >= CenterGameBoardX && mousePos.x <= CenterGameBoardX + gridSize * squareSize && mousePos.y >= CenterGameBoardY && mousePos.y <= CenterGameBoardY + gridSize * squareSize) {
					
					int col = (mousePos.x - CenterGameBoardX) / squareSize;
					int row = (mousePos.y - CenterGameBoardY) / squareSize;
					if (row >= 0 && row < gridSize && col >= 0 && col < gridSize) {
						std::cout << "Mouse is at: row = " << row << ", col = " << col << std::endl;

						//For now this is how you change from S to O 
						if (grid.getCellState(row, col) == 0 || grid.getCellState(row, col) == 2) {
							grid.setCellState(row, col, 1);

						}
						else {
							grid.setCellState(row, col, 2);
						}
				}
				
				
				}



			}
		}

		//clear the screen and set the default color to black
		window.clear(sf::Color::Black);
		
		//draw calls below here 
		

		

		//test
	


		//test

		//draws the game board
		grid.drawCells(window, squareSize, gridSize,CenterGameBoardX, CenterGameBoardY,gridWidth);
		
		SimpleLabel.draw_Label(window);
		GeneralLabel.draw_Label(window);
		ThreebyLabel.draw_Label(window);
		FivebyLabel.draw_Label(window);
		SevenbyLabel.draw_Label(window);
		SimpleGameBtn.drawButton(window);
		GeneralGameBtn.drawButton(window);
		ThreeByThree.drawButton(window);
		FiveByFive.drawButton(window);
		SevenBySeven.drawButton(window);
		
		
		//display screen
		window.display();

	}

	return 0;

};