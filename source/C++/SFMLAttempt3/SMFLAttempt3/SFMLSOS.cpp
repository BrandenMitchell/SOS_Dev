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
	
	
	

	//game board

	
	float gridSize = 8.f; //game board dimensions 3x3, 6x6 etc
	float gridWidth = 800; //game board width
	float gridHeight = 800; //game board height
	
	float squareSize = gridWidth / gridSize; //cell size
	Grid grid(gridSize, gridSize);

	//finding center of board
	float CenterGameBoardX = window.getSize().x / 2.f - gridWidth / 2.f;
	float CenterGameBoardY = window.getSize().y / 2.f - gridHeight / 2.f;
	
	//Center of Screen
	float centerX = window.getSize().x / 2.f - 60;

	//Players init
	bool Player1_turn = true;
	bool Player2_turn = false;



	//---------------- UI elements  -----------------\\	
	Label TitleLable(centerX, 23, "SOS GAME", "Cyan",60);
	Label SimpleLabel(60,23, "Simple Game", "White", 55);
	Label GeneralLabel(60,65, "General Game", "Cyan", 55);
	Label ThreebyLabel(60,160, "3x3", "Magenta", 35);
	Label FivebyLabel(160, 160, "5x5 ", "Red", 35);
	Label SevenbyLabel(260, 160, "7x7 ", "Yellow", 35);

	Label Player1Label(23, 200, "Player 1", "White",30);
	Label Player2Label(123, 200, "Player 2", "White", 30);

	Label Player1S(63, 250, "S", "White", 40);
	Label Player2S(163, 250, "S", "White", 40);
	Label Player1O(63, 320, "O", "White", 40);
	Label Player2O(163, 320, "O", "White", 40);

	//Game Mode button init
	RadioButton SimpleGameBtn(43, 60, 13, 8);
	RadioButton GeneralGameBtn(43, 100, 13, 8);

	
	
	
	
	//Game Board size Button init
	RadioButton ThreeByThree(43, 160, 11, 8);
	RadioButton FiveByFive(143, 160, 11, 8);
	RadioButton SevenBySeven(243, 160, 11, 8);

	////Player 1 and 2 controls
	//p1
	RadioButton S_moveP1(43, 280, 11, 8);
	RadioButton O_moveP1(43, 350, 11, 8);
	//p2
	RadioButton S_moveP2(143, 280, 11, 8);
	RadioButton O_moveP2(143, 350, 11, 8);

	//game mode btn group
	RadioButtonGroup ModebtnGroup;
	ModebtnGroup.addRadioButton(&GeneralGameBtn);
	ModebtnGroup.addRadioButton(&SimpleGameBtn);

	//game board size btn group
	RadioButtonGroup BoardbtnGroup;
	BoardbtnGroup.addRadioButton(&ThreeByThree);
	BoardbtnGroup.addRadioButton(&FiveByFive);
	BoardbtnGroup.addRadioButton(&SevenBySeven);

	//Player button groups
	//p1
	RadioButtonGroup Player1BtnGroup;
	Player1BtnGroup.addRadioButton(&S_moveP1);
	Player1BtnGroup.addRadioButton(&O_moveP1);
	//p2
	RadioButtonGroup Player2BtnGroup;
	Player2BtnGroup.addRadioButton(&S_moveP2);
	Player2BtnGroup.addRadioButton(&O_moveP2);
	
	//---------------- UI elements  -----------------\\	

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
				centerX = event.size.width / 2.f - 80;
				float titleLabelY = 23;
				sf::Vector2f titleLabelPos;
				titleLabelPos.x = centerX;
				titleLabelPos.y = titleLabelY;

				TitleLable.set_LabelPos(titleLabelPos);




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
					std::unique_ptr<GameMode> mode = std::make_unique<SimpleMode>();
					Game SimpGame(std::move(mode),gridSize,gridSize);
					SimpGame.start();
					grid.ResetGrid();

					


				}
				else if (GeneralGameBtn.handleClick(event.mouseButton.x, event.mouseButton.y)) {
					SimpleGameBtn.setState(false);
					SimpleGameBtn.setInnerColor("Transparent");
					SimpleLabel.set_labelColor("White");

					GeneralLabel.set_labelColor("Green");
					std::unique_ptr<GameMode> mode = std::make_unique<GeneralMode>();
					Game GenGame(std::move(mode), gridSize, gridSize);
					GenGame.start();
					grid.ResetGrid();
					
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
					grid.ResetGrid();
					Player1_turn = true;
					Player2_turn = false;

					gridSize = 3.f;

				}
				else if (FiveByFive.handleClick(mousePos.x, mousePos.y)) {
					SevenBySeven.setState(false);
					ThreeByThree.setState(false);
					SevenBySeven.setInnerColor("Transparent");
					ThreeByThree.setInnerColor("Transparent");
					FivebyLabel.set_labelColor("White");
					grid.ResetGrid();
					Player1_turn = true;
					Player2_turn = false;
					gridSize = 5.f;
				
				}
				else if (SevenBySeven.handleClick(mousePos.x, mousePos.y)) {
					FiveByFive.setState(false);
					ThreeByThree.setState(false);
					FiveByFive.setInnerColor("Transparent");
					ThreeByThree.setInnerColor("Transparent");
					SevenbyLabel.set_labelColor("White");
					grid.ResetGrid();
					Player1_turn = true;
					Player2_turn = false;
					gridSize = 7.f;
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

				//Making a move 
				if (S_moveP1.handleClick(mousePos.x, mousePos.y)) {
					
					O_moveP1.setState(false);
					O_moveP1.setInnerColor("Transparent");
					

				}
				else if (O_moveP1.handleClick(mousePos.x, mousePos.y)) {
					S_moveP1.setState(false);
					S_moveP1.setInnerColor("Transparent");
				

				}
				else if (S_moveP2.handleClick(mousePos.x, mousePos.y)) {
					O_moveP2.setState(false);
					O_moveP2.setInnerColor("Transparent");
				}

				else if (O_moveP2.handleClick(mousePos.x, mousePos.y)) {
					S_moveP2.setState(false);
					S_moveP2.setInnerColor("Transparent");
					
				}
			

			
				

				
					
				
		

				/*std::cout << "mouse is alive" << mousePos.x << mousePos.y << std::endl;*/
				std::cout << "Player 1 turn: " << Player1_turn << std::endl;
				std::cout << "Player 2 turn: " << Player2_turn << std::endl;
				if (mousePos.x >= CenterGameBoardX && mousePos.x <= CenterGameBoardX + gridSize * squareSize && mousePos.y >= CenterGameBoardY && mousePos.y <= CenterGameBoardY + gridSize * squareSize) {
					
					int col = (mousePos.x - CenterGameBoardX) / squareSize;
					int row = (mousePos.y - CenterGameBoardY) / squareSize;
					if (row >= 0 && row < gridSize && col >= 0 && col < gridSize) {
						std::cout << "Mouse is at: row = " << row << ", col = " << col << std::endl;
						
						//For now this is how you change from S to O 
						if (S_moveP1.getState() and Player1_turn) {
							
							if (grid.getCellState(row, col) == 0) {
								grid.setCellState(row, col, 1);
								Player1_turn = false;
								Player2_turn = true;
								S_moveP1.setState(false);
							}
							
						}
						else if (O_moveP1.getState() and Player1_turn) {
							
							if (grid.getCellState(row, col) == 0) {
								grid.setCellState(row, col, 2);
								Player1_turn = false;
								Player2_turn = true;
								O_moveP1.setState(false);
							}
							

							
						}

						if (S_moveP2.getState() and Player2_turn) {

							if (grid.getCellState(row, col) == 0) {
								grid.setCellState(row, col, 1);
								Player2_turn = false;
								Player1_turn = true;
								S_moveP2.setState(false);
							}
							
						}
						else if (O_moveP2.getState() and Player2_turn) {

							if (grid.getCellState(row, col) == 0) {
								grid.setCellState(row, col, 2);
								Player2_turn = false;
								Player1_turn = true;
								O_moveP2.setState(false);
							}
							

						}


						/*if (Player2_turn) {
							if (S_moveP2.getState()) {
								if (grid.getCellState(row, col) == 0) {
									grid.setCellState(row, col, 1);
								}
								Player2_turn = false;
								Player1_turn = true;
							}
						}
						else if (Player2_turn) {
							if (O_moveP2.getState()) {
								if (grid.getCellState(row, col) == 0) {
									grid.setCellState(row, col, 2);
								}
								Player2_turn = false;
								Player1_turn = true;
							}
						
						}*/

						/*if (grid.getCellState(row, col) == 0 || grid.getCellState(row, col) == 2) {
							grid.setCellState(row, col, 1);

						}
						else {
							grid.setCellState(row, col, 2);
						}*/
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
		Player1Label.draw_Label(window);
		Player2Label.draw_Label(window);
		Player1S.draw_Label(window);
		Player2S.draw_Label(window);
		Player1O.draw_Label(window);
		Player2O.draw_Label(window);
		TitleLable.draw_Label(window);
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
		S_moveP1.drawButton(window);
		O_moveP1.drawButton(window);
		S_moveP2.drawButton(window);
		O_moveP2.drawButton(window);
		
		
		
		//display screen
		window.display();

	}

	return 0;

};