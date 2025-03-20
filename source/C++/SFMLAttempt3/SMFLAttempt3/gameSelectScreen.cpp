#pragma once

#include "gameSelectScreen.h"


//default constructor
GameSelectionScene::GameSelectionScene() {
	//init the ui elements 
	titleLabel.initLabel(300, 300, "SOS GAME", "cyan", 60);
	uiText.initLabel(300, 380, "Choose a Game Mode !", "cyan", 60);
	SimpleGame.initRadioButton(300, 400, 18, 14);
	GeneralGame.initRadioButton(400, 400, 18, 14);
	sceneEnds = false;
	SimpleLabel.initLabel(280, 400, "Simple Game", "white", 50);
	GeneralLabel.initLabel(380, 400, "General Game", "white", 50);


	}

//render the title text and the two button options
void GameSelectionScene::RenderScene(sf::RenderWindow& window) {

		std::cout << "made it to render func" << std::endl;
		window.clear(sf::Color::Black);
		titleLabel.draw_Label(window);
		uiText.draw_Label(window);
		SimpleLabel.draw_Label(window);
		GeneralLabel.draw_Label(window);
		SimpleGame.drawButton(window);
		GeneralGame.drawButton(window);
		window.display();

	


	

}
bool GameSelectionScene::getSceneState() {
	return sceneEnds;

}
//set buttons and Title Text
void GameSelectionScene::setTitleString(std::string labelText){
	titleLabel.set_labelText(labelText);
}


void GameSelectionScene::setUserText(std::string labelText) {
	uiText.set_labelText(labelText);

}

void GameSelectionScene::handleInput(sf::RenderWindow& window) {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);



		if (SimpleGame.handleClick(event.mouseButton.x, event.mouseButton.y)) {
			// Ensure only one button is active at a time
			GeneralGame.setState(false);
			GeneralGame.setInnerColor("Transparent");
			SimpleLabel.set_labelColor("Green");
			GeneralLabel.set_labelColor("Cyan");
			sceneEnds = true;
			

		}
		else if (GeneralGame.handleClick(event.mouseButton.x, event.mouseButton.y)) {
			// Ensure only one button is active at a time
			SimpleGame.setState(false);
			SimpleGame.setInnerColor("Transparent");
			GeneralLabel.set_labelColor("Green");
			SimpleLabel.set_labelColor("Cyan");
			sceneEnds = true;

		}
		
	}
}



void GameSelectionScene::handleEvent(sf::RenderWindow& window) {
	
	
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
			
				int centerX = event.size.width / 2.f - 80;

			}
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
				handleInput(window);

			}


		}

	
	}

	




}

//Label titleLabel;
//Label userText;
//RadioButton SimpleGame;
//RadioButton GeneralGame;


