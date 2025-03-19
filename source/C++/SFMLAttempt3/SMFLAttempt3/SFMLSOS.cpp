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
#include "GameMode.h"
#include "SimpleMode.h"
#include "GeneralGame.h"


//using namespace std;



//function declaration and definitions











//MainLoop
int main(){
	
	float gridSize = 5.f; //game board dimensions 3x3, 6x6 etc
	float gridWidth = 800; //game board width
	float gridHeight = 800; //game board height

	float squareSize = gridWidth / gridSize; //cell size
	std::unique_ptr<GameMode> mode = std::make_unique<SimpleMode>();
	Game SimpGame(std::move(mode), gridSize, gridSize);
	SimpGame.start();
	




//	//---------------- UI elements  -----------------\\	
//
//	//---------------- declarations  -----------------\\
//
//
//	
//
//
//
//
//	while(window.isOpen()) {
//
//		
//
//		sf::Event event;
//		while (window.pollEvent(event)) {
//			if (event.type == sf::Event::Closed) {
//				window.close();
//				
//
//
//			}
//			if (event.type == sf::Event::Resized) {
//				//on resize update the window area / size
//				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
//				window.setView(sf::View(visibleArea));
//
//			
//
//				//on resize update the center for the game grid
//				CenterGameBoardX = event.size.width / 2.f - gridWidth / 2.f;
//				CenterGameBoardY = event.size.height / 2.f - gridHeight / 2.f;
//				centerX = event.size.width / 2.f - 80;
//				float titleLabelY = 23;
//				sf::Vector2f titleLabelPos;
//				titleLabelPos.x = centerX;
//				titleLabelPos.y = titleLabelY;
//
//				TitleLable.set_LabelPos(titleLabelPos);
//
//
//
//
//				//calculate square size on resize
//				squareSize = gridWidth/ gridSize;
//
//
//
//
//			}
//			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
//				
//				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
//				
//			/*	ThreeByThree.handleClick(mousePos.x, mousePos.y);
//				FiveByFive.handleClick(mousePos.x, mousePos.y);
//				SevenBySeven.handleClick(mousePos.x, mousePos.y);*/
//
//				if (SimpleGameBtn.handleClick(event.mouseButton.x, event.mouseButton.y)) {
//					// Ensure only one button is active at a time
//					GeneralGameBtn.setState(false);
//					GeneralGameBtn.setInnerColor("Transparent");
//					SimpleLabel.set_labelColor("Green");
//					GeneralLabel.set_labelColor("Cyan");
//					std::unique_ptr<GameMode> mode = std::make_unique<SimpleMode>();
//					Game SimpGame(std::move(mode),gridSize,gridSize);
//					SimpGame.start();
//					grid.ResetGrid();
//
//					
//
//
//				}
//				else if (GeneralGameBtn.handleClick(event.mouseButton.x, event.mouseButton.y)) {
//					SimpleGameBtn.setState(false);
//					SimpleGameBtn.setInnerColor("Transparent");
//					SimpleLabel.set_labelColor("White");
//
//					GeneralLabel.set_labelColor("Green");
//					std::unique_ptr<GameMode> mode = std::make_unique<GeneralMode>();
//					Game GenGame(std::move(mode), gridSize, gridSize);
//					GenGame.start();
//					grid.ResetGrid();
//					
//				}
//				if (!SimpleGameBtn.getState()) {
//					SimpleLabel.set_labelColor("White");
//
//				}
//				if (!GeneralGameBtn.getState()) {
//					GeneralLabel.set_labelColor("Cyan");
//
//				}
//
//
//				if (ThreeByThree.handleClick(mousePos.x, mousePos.y)) {
//					// Ensure only one button is active at a time
//					SevenBySeven.setState(false);
//					FiveByFive.setState(false);
//					SevenBySeven.setInnerColor("Transparent");
//					FiveByFive.setInnerColor("Transparent");
//					ThreebyLabel.set_labelColor("White");
//					grid.ResetGrid();
//					Player1_turn = true;
//					Player2_turn = false;
//
//					gridSize = 3.f;
//
//				}
//				else if (FiveByFive.handleClick(mousePos.x, mousePos.y)) {
//					SevenBySeven.setState(false);
//					ThreeByThree.setState(false);
//					SevenBySeven.setInnerColor("Transparent");
//					ThreeByThree.setInnerColor("Transparent");
//					FivebyLabel.set_labelColor("White");
//					grid.ResetGrid();
//					Player1_turn = true;
//					Player2_turn = false;
//					gridSize = 5.f;
//				
//				}
//				else if (SevenBySeven.handleClick(mousePos.x, mousePos.y)) {
//					FiveByFive.setState(false);
//					ThreeByThree.setState(false);
//					FiveByFive.setInnerColor("Transparent");
//					ThreeByThree.setInnerColor("Transparent");
//					SevenbyLabel.set_labelColor("White");
//					grid.ResetGrid();
//					Player1_turn = true;
//					Player2_turn = false;
//					gridSize = 7.f;
//				}
//				if (!ThreeByThree.getState()) {
//					ThreebyLabel.set_labelColor("Magenta");
//
//				}
//				if (!FiveByFive.getState()) {
//					FivebyLabel.set_labelColor("Red");
//
//				}
//				if (!SevenBySeven.getState()) {
//					SevenbyLabel.set_labelColor("Yellow");
//
//				}
//
//				//Making a move 
//				if (S_moveP1.handleClick(mousePos.x, mousePos.y)) {
//					
//					O_moveP1.setState(false);
//					O_moveP1.setInnerColor("Transparent");
//					
//
//				}
//				else if (O_moveP1.handleClick(mousePos.x, mousePos.y)) {
//					S_moveP1.setState(false);
//					S_moveP1.setInnerColor("Transparent");
//				
//
//				}
//				else if (S_moveP2.handleClick(mousePos.x, mousePos.y)) {
//					O_moveP2.setState(false);
//					O_moveP2.setInnerColor("Transparent");
//				}
//
//				else if (O_moveP2.handleClick(mousePos.x, mousePos.y)) {
//					S_moveP2.setState(false);
//					S_moveP2.setInnerColor("Transparent");
//					
//				}
//			
//
//			
//				
//
//				
//					
//				
//		
//
//				/*std::cout << "mouse is alive" << mousePos.x << mousePos.y << std::endl;*/
//				std::cout << "Player 1 turn: " << Player1_turn << std::endl;
//				std::cout << "Player 2 turn: " << Player2_turn << std::endl;
//				if (mousePos.x >= CenterGameBoardX && mousePos.x <= CenterGameBoardX + gridSize * squareSize && mousePos.y >= CenterGameBoardY && mousePos.y <= CenterGameBoardY + gridSize * squareSize) {
//					
//					int col = (mousePos.x - CenterGameBoardX) / squareSize;
//					int row = (mousePos.y - CenterGameBoardY) / squareSize;
//					if (row >= 0 && row < gridSize && col >= 0 && col < gridSize) {
//						std::cout << "Mouse is at: row = " << row << ", col = " << col << std::endl;
//						
//						//For now this is how you change from S to O 
//						if (S_moveP1.getState() and Player1_turn) {
//							
//							if (grid.getCellState(row, col) == 0) {
//								grid.setCellState(row, col, 1);
//								Player1_turn = false;
//								Player2_turn = true;
//								S_moveP1.setState(false);
//							}
//							
//						}
//						else if (O_moveP1.getState() and Player1_turn) {
//							
//							if (grid.getCellState(row, col) == 0) {
//								grid.setCellState(row, col, 2);
//								Player1_turn = false;
//								Player2_turn = true;
//								O_moveP1.setState(false);
//							}
//							
//
//							
//						}
//
//						if (S_moveP2.getState() and Player2_turn) {
//
//							if (grid.getCellState(row, col) == 0) {
//								grid.setCellState(row, col, 1);
//								Player2_turn = false;
//								Player1_turn = true;
//								S_moveP2.setState(false);
//							}
//							
//						}
//						else if (O_moveP2.getState() and Player2_turn) {
//
//							if (grid.getCellState(row, col) == 0) {
//								grid.setCellState(row, col, 2);
//								Player2_turn = false;
//								Player1_turn = true;
//								O_moveP2.setState(false);
//							}
//							
//
//						}
//
//
//						/*if (Player2_turn) {
//							if (S_moveP2.getState()) {
//								if (grid.getCellState(row, col) == 0) {
//									grid.setCellState(row, col, 1);
//								}
//								Player2_turn = false;
//								Player1_turn = true;
//							}
//						}
//						else if (Player2_turn) {
//							if (O_moveP2.getState()) {
//								if (grid.getCellState(row, col) == 0) {
//									grid.setCellState(row, col, 2);
//								}
//								Player2_turn = false;
//								Player1_turn = true;
//							}
//						
//						}*/
//
//						/*if (grid.getCellState(row, col) == 0 || grid.getCellState(row, col) == 2) {
//							grid.setCellState(row, col, 1);
//
//						}
//						else {
//							grid.setCellState(row, col, 2);
//						}*/
//				}
//					
//				
//				
//				}
//
//
//
//			}
//		}
//
//		//clear the screen and set the default color to black
//		window.clear(sf::Color::Black);
//		
//		//draw calls below here 
//		
//
//		
//
//		//test
//	
//
//
//		//test
//
//		//draws the game board
//		grid.drawCells(window, squareSize, gridSize,CenterGameBoardX, CenterGameBoardY,gridWidth);
//		Player1Label.draw_Label(window);
//		Player2Label.draw_Label(window);
//		Player1S.draw_Label(window);
//		Player2S.draw_Label(window);
//		Player1O.draw_Label(window);
//		Player2O.draw_Label(window);
//		TitleLable.draw_Label(window);
//		SimpleLabel.draw_Label(window);
//		GeneralLabel.draw_Label(window);
//		ThreebyLabel.draw_Label(window);
//		FivebyLabel.draw_Label(window);
//		SevenbyLabel.draw_Label(window);
//		SimpleGameBtn.drawButton(window);
//		GeneralGameBtn.drawButton(window);
//		ThreeByThree.drawButton(window);
//		FiveByFive.drawButton(window);
//		SevenBySeven.drawButton(window);
//		S_moveP1.drawButton(window);
//		O_moveP1.drawButton(window);
//		S_moveP2.drawButton(window);
//		O_moveP2.drawButton(window);
//		
//		
//		
//		//display screen
//		window.display();

	return 0;

};