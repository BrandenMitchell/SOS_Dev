#pragma once
#include "Game.h"
#include "GridClass.h"
#include <vector>




Game::Game(std::unique_ptr<GameMode> mode, int rows, int cols)
	: mode(std::move(mode)), grid(rows, cols, 800.f, 600.f), window(sf::VideoMode(1200, 1080), "SOSGAME") {
	
	float width = grid.getWidth();
	float height = grid.getHeight();

	
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
	mode->Rules();
	updateGameLogic();
	handleEvents();
	render();

	
	
	
}


void Game::handleEvents() {
	while (window.isOpen()) {
		std::cout << "Game is open...\n" << std::endl;
		if (event.type == sf::Event::Closed) {
			window.close();



		}
		if (event.type == sf::Event::Resized) {
			//on resize update the window area / size
			sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
			window.setView(sf::View(visibleArea));

			float width = grid.getWidth();
			float height = grid.getHeight();

			////on resize update the center for the game grid
			CenterGameBoardX = event.size.width / 2.f - width / 2.f;
			CenterGameBoardY = event.size.height / 2.f - height / 2.f;
			centerX = event.size.width / 2.f - 80;
			
			
			/*float titleLabelY = 23;
			sf::Vector2f titleLabelPos;
			titleLabelPos.x = centerX;
			titleLabelPos.y = titleLabelY;

			TitleLable.set_LabelPos(titleLabelPos);*/



			std::vector<int> dimensions =  grid.getDimensions();
			int gridSize = dimensions[0];

			//calculate square size on resize
			squareSize = width / gridSize;




		}
	}
}


// handle mouse interaction witht the game
void Game::handleInput() {
	std::cout << "Handling Input...\n" << std::endl;
}


//update the game logic
void Game::updateGameLogic() {
	std::cout << "Updating Logic ...\n" << std::endl;
}


//render current game sate
void Game::render() {
	std::cout << "Game is Rendering...\n" << std::endl;
	std::vector<int> dimensions = grid.getDimensions();
	int rows = dimensions[0];
	float width = dimensions[1];


	grid.drawCells(window, squareSize, rows, CenterGameBoardX, CenterGameBoardY, width);
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
}
