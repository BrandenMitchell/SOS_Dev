#pragma once
#include "Game.h"
#include "GridClass.h"
#include <vector>




Game::Game(std::unique_ptr<GameMode> mode, int rows, int cols)
	: mode(std::move(mode)), grid(rows, cols, 800.f, 600.f), window(sf::VideoMode(1200, 1080), "SOSGAME") {
	
	float width = grid.getWidth();
	float height = grid.getHeight();
	gridSize = rows;

	
	window.setFramerateLimit(60);
	CenterGameBoardX = window.getSize().x / 2.f - width / 2.f;
	CenterGameBoardY = window.getSize().y / 2.f - height / 2.f;
	
	centerX = window.getSize().x / 2.f - 60;
	squareSize = width / rows;

	//ui labels init
	TitleLable.initLabel(800, 23, "SOS GAME", "Cyan", 60);
	SimpleLabel.initLabel(60, 23, "Simple Game", "White", 55);
	GeneralLabel.initLabel(60, 65, "General Game", "Cyan", 55);
	ThreebyLabel.initLabel(60, 160, "3x3", "Magenta", 35);
	FivebyLabel.initLabel(160, 160, "5x5 ", "Red", 35);
	SevenbyLabel.initLabel(260, 160, "7x7 ", "Yellow", 35);
	
	//player controls init
	Player1Label.initLabel(23, 200, "Player 1", "White", 30);
	Player2Label.initLabel(123, 200, "Player 2", "White", 30);
	Player1S.initLabel(63, 250, "S", "White", 40);
	Player2S.initLabel(163, 250, "S", "White", 40);
	Player1O.initLabel(63, 320, "O", "White", 40);
	Player2O.initLabel(163, 320, "O", "White", 40);
	
	SimpleGameBtn.initRadioButton(43, 60, 13, 8);
	GeneralGameBtn.initRadioButton(43, 100, 13, 8);


	ThreeByThree.initRadioButton(43, 160, 11, 8);
	FiveByFive.initRadioButton(143, 160, 11, 8);
	SevenBySeven.initRadioButton(243, 160, 11, 8);


	
	S_moveP1.initRadioButton(43, 280, 11, 8);
	O_moveP1.initRadioButton(43, 350, 11, 8);
	
	S_moveP2.initRadioButton(143, 280, 11, 8);
	O_moveP2.initRadioButton(143, 350, 11, 8);

}


void Game::start() {
	std::cout << "Game is Loading...\n" << std::endl;
	if (dynamic_cast<SimpleMode*>(mode.get())) {
		// mode is pointing to an instance of SimpleGame
		std::cout << "The current game mode is SimpleGame." << std::endl;
	}
	else if (dynamic_cast<GeneralMode*>(mode.get())) {
		// mode is pointing to an instance of GeneralGame
		std::cout << "The current game mode is GeneralGame." << std::endl;
	}
	else {
		// mode is of some other type will check for the gamemode select screen 
		std::cout << "The current game mode is unknown." << std::endl;
	}
	mode->Rules();

	//updateGameLogic();
	
	handleEvents();
	render();

	
	
	
}
void Game::renderNewScreen(std::string key) {
	window.clear();
	RadioButton SimpleGameBtnend;
	RadioButton GeneralGameBtnend;
	SimpleGameBtnend.initRadioButton(300, 300, 20, 16);
	GeneralGameBtnend.initRadioButton(600, 300, 20, 16);

	Label SimpleLabelend;
	Label GeneralLabelend;
	Label userDirection;
	SimpleLabelend.initLabel(250, 300, "Simple Game", "White", 50);
	GeneralLabelend.initLabel(500, 300, "General Game", "Green", 50);
	userDirection.initLabel(300, 200, "Choose Your Game Mode", "White", 50);
	
	if (key == "main-menu") {
		//do the main menu button select screen
		std::string userText = "Choose Your Game Mode";
		userDirection.set_labelText(userText);

		TitleLable.draw_Label(window);
		userDirection.draw_Label(window);
		SimpleLabelend.draw_Label(window);
		GeneralLabelend.draw_Label(window);
		SimpleGameBtnend.drawButton(window);
		GeneralGameBtnend.drawButton(window);
		window.display();
		if (SimpleGameBtnend.handleClick(event.mouseButton.x, event.mouseButton.y)) {

			// Ensure only one button is active at a time
			GeneralGameBtnend.setState(false);
			GeneralGameBtnend.setInnerColor("Transparent");
			SimpleLabelend.set_labelColor("Green");
			GeneralLabelend.set_labelColor("Cyan");
			SimpGame = true;
			GenGame = false;
			Player1_turn = true;
			Player2_turn = false;
			grid.ResetGrid();
			window.clear();
			GameRunning = true;
			MainMenu = false;
			simpleGame.resetGame();

			

		}
		else if (GeneralGameBtnend.handleClick(event.mouseButton.x, event.mouseButton.y)) {
			SimpleGameBtnend.setState(false);
			SimpleGameBtnend.setInnerColor("Transparent");
			GeneralLabelend.set_labelColor("Green");
			SimpleLabelend.set_labelColor("Cyan");
			SimpGame = false;
			GenGame = true;
			Player1_turn = true;
			Player2_turn = false;
			grid.ResetGrid();
			window.clear();
			GameRunning = true;
			MainMenu = false;
			generalGame.resetGame();
		}
	}
	else if (key == "simple-end") {
		//end screen for the simple game
		Label gameOver;
		std::string userText = "Press Space to play again!" ;

		std::string GameOverLabelText = simpleGame.getEndString();
		gameOver.initLabel(300, 300, GameOverLabelText, "White", 50);
		userDirection.set_labelText(userText);
		gameOver.draw_Label(window);
		userDirection.draw_Label(window);
		window.display();
		while (window.pollEvent(event)) {
			
			if (event.type == sf::Event::Closed) {
				window.close();

			}
			if (event.type == sf::Event::Resized) {
				//on resize update the window area / size
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				window.setView(sf::View(visibleArea));



			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space ) {
				std::cout << "Loading Game Select..." << std::endl;
				window.clear();
				GameRunning = false;
				simpleEnd = false;
				MainMenu = true;
				

				
				

			}
			

			
		}
		

	
	}	
	else if (key == "general-end") {
		//end screen for the general game
		Label gameOverG;
		std::string userText = "Press Space to play again!";
		
		std::string GameOverLabelText = generalGame.getEndString();
		
		gameOverG.initLabel(300, 300, GameOverLabelText, "White", 50);
		userDirection.set_labelText(userText);
		gameOverG.draw_Label(window);
		userDirection.draw_Label(window);
		window.display();
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {
				window.close();

			}
			if (event.type == sf::Event::Resized) {
				//on resize update the window area / size
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				window.setView(sf::View(visibleArea));



			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
				std::cout << "Loading Game Select..." << std::endl;
				window.clear();
				GameRunning = false;
				generalEnd = false;
				MainMenu = true;

			}



		}
	}
}

void Game::handleEvents() {

	float width = grid.getWidth();
	float height = grid.getHeight();
	
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			//std::cout << "Game is open...\n" << std::endl;
			if (event.type == sf::Event::Closed) {
				window.close();



			}
			if (event.type == sf::Event::Resized) {
				//on resize update the window area / size
			

				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				window.setView(sf::View(visibleArea));

				

				////on resize update the center for the game grid
				CenterGameBoardX = event.size.width / 2.f - width / 2.f;
				CenterGameBoardY = event.size.height / 2.f - height / 2.f;
				centerX = event.size.width / 2.f - 80;


				float titleLabelY = 23;
				sf::Vector2f titleLabelPos;
				titleLabelPos.x = centerX;
				titleLabelPos.y = titleLabelY;

				TitleLable.set_LabelPos(titleLabelPos);



				

				//calculate square size on resize
				squareSize = width / gridSize;




			}
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
				handleInput();

			}
		
		
		}
		


		updateGameLogic();

	}
	window.clear(sf::Color::Black);
	


}




// handle mouse interaction with the game
void Game::handleInput() { 
	//std::cout << "Handling Input...\n" << std::endl;
	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);



		if (SimpleGameBtn.handleClick(event.mouseButton.x, event.mouseButton.y)) {
			// Ensure only one button is active at a time
			GeneralGameBtn.setState(false);
			GeneralGameBtn.setInnerColor("Transparent");
			SimpleLabel.set_labelColor("Green");
			GeneralLabel.set_labelColor("Cyan");
			SimpGame = true;
			GenGame = false;
			std::cout << "simple game Loading" << std::endl;
			std::cout << SimpGame << std::endl;
			Player1_turn = true;
			Player2_turn = false;
			grid.ResetGrid();
			simpleGame.resetGame();

		}
		else if (GeneralGameBtn.handleClick(event.mouseButton.x, event.mouseButton.y)) {
			SimpleGameBtn.setState(false);
			SimpleGameBtn.setInnerColor("Transparent");
			SimpleLabel.set_labelColor("White");

			GeneralLabel.set_labelColor("Green");
			SimpGame = false;
			GenGame = true;
			std::cout << "general game Loading" << std::endl;
			Player1_turn = true;
			Player2_turn = false;
			grid.ResetGrid();
			generalGame.resetGame();
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

			Player1_turn = true;
			Player2_turn = false;
			gridSize = 3.f;
			grid.ResetGrid();
			window.clear();
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
			window.clear();


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
			window.clear();

			
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

		if (mousePos.x >= CenterGameBoardX && mousePos.x <= CenterGameBoardX + gridSize * squareSize && mousePos.y >= CenterGameBoardY && mousePos.y <= CenterGameBoardY + gridSize * squareSize) {
			int col = (mousePos.x - CenterGameBoardX) / squareSize;
			int row = (mousePos.y - CenterGameBoardY) / squareSize;
			std::string key = "";

			if (row >= 0 && row < gridSize && col >= 0 && col < gridSize) {
				std::cout << "Mouse is at: row = " << row << ", col = " << col << std::endl;
				//dev info delete later 
				std::cout << SimpGame << std::endl;
				std::cout << GenGame << std::endl;

				if (SimpGame == true) {
					//Simple game is mode
					
			
					if (S_moveP1.getState() and Player1_turn) {
						// call simple or general mode makeSmove()
						//pass it a reference to the grid , the row and col
						key = "s";

						if (grid.getCellState(row, col) == 0) {
							simpleGame.makeMove(grid, row, col, key,1, gridSize);
								
							Player1_turn = false;
							Player2_turn = true;
							S_moveP1.setState(false);
						}

					}
					else if (O_moveP1.getState() and Player1_turn) {
						key = "o";

						if (grid.getCellState(row, col) == 0) {
							simpleGame.makeMove(grid, row, col, key, 1, gridSize);
								



							Player1_turn = false;
							Player2_turn = true;
							O_moveP1.setState(false);
						}

					}

					if (S_moveP2.getState() and Player2_turn) {
						key = "s";

						if (grid.getCellState(row, col) == 0) {
							simpleGame.makeMove(grid, row, col, key,2,gridSize);

							Player2_turn = false;
							Player1_turn = true;
							S_moveP2.setState(false);
						}

					}
					else if (O_moveP2.getState() and Player2_turn) {
						key = "o";

						if (grid.getCellState(row, col) == 0) {
							simpleGame.makeMove(grid, row, col, key,2, gridSize);

							Player2_turn = false;
							Player1_turn = true;
							O_moveP2.setState(false);
						}


					}
					if (!simpleGame.getGameState()) {
						//the simple game has ended. 
						
						
						SimpGame = false;
						SimpleGameBtn.setState(false);
						GameRunning = false;
						simpleEnd = true;



					}

				

					
					
				}
				else if (GenGame == true){
					//else General Game is mode
					if (S_moveP1.getState() and Player1_turn) {
						
						key = "s";

						if (grid.getCellState(row, col) == 0) {
							generalGame.makeMove(grid, row, col, key, 1, gridSize);

							Player1_turn = false;
							Player2_turn = true;
							S_moveP1.setState(false);
						}

					}
					else if (O_moveP1.getState() and Player1_turn) {
						key = "o";

						if (grid.getCellState(row, col) == 0) {
							generalGame.makeMove(grid, row, col, key, 1, gridSize);




							Player1_turn = false;
							Player2_turn = true;
							O_moveP1.setState(false);
						}

					}

					if (S_moveP2.getState() and Player2_turn) {
						key = "s";

						if (grid.getCellState(row, col) == 0) {
							generalGame.makeMove(grid, row, col, key, 2, gridSize);

							Player2_turn = false;
							Player1_turn = true;
							S_moveP2.setState(false);
						}

					}
					else if (O_moveP2.getState() and Player2_turn) {
						key = "o";

						if (grid.getCellState(row, col) == 0) {
							generalGame.makeMove(grid, row, col, key, 2, gridSize);

							Player2_turn = false;
							Player1_turn = true;
							O_moveP2.setState(false);
						}


					}
					if (!generalGame.getGameState()) {
						//the general game has ended. 


						GenGame = false;
						GeneralGameBtn.setState(false);
						GameRunning = false;
						generalEnd = true;



					}
				
				
				
				
				}
				else {
					std::cout << "GAME MODE ERR OCCURED" << std::endl;

				}
				updateGameLogic();
				
				
			}
			

		}
	

	
	}
	
}
	



//update the game logic
void Game::updateGameLogic() {
	if (!(GameRunning) and MainMenu == true) {
		//run  main menu screen 
		std::string main = "main-menu";
		renderNewScreen(main);

	}
	else if (!(GameRunning) and simpleEnd == true) {
		std::string ending = "simple-end";
		renderNewScreen(ending);

	}
	else if (!(GameRunning) and generalEnd == true) {
		std::string ending = "general-end";
		
		renderNewScreen(ending);

	}
	else {
		render();
	}
		
	
	 
}


//render current game sate
void Game::render() {
	window.clear(sf::Color::Black);
	//std::cout << "Game is Rendering...\n" << std::endl;
	std::vector<int> dimensions = grid.getDimensions();
	
	float width = dimensions[1];
	
	grid.drawCells(window, squareSize, gridSize, CenterGameBoardX, CenterGameBoardY, width);
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

	
	
	window.display();

}
