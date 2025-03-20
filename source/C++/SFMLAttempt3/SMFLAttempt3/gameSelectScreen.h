#pragma once
#ifndef GAMESELECTOR_H
#define GAMESELECTOR_H
#include "UI_Label.h";
#include "RadioButton.h"
#include <string>

class GameSelectionScene {
public:
	//default constructor
	GameSelectionScene();
	
	//render the title text and the two button options
	void RenderScene(sf::RenderWindow& window);
	//set buttons and Title Text
	void setTitleString(std::string labelText);
	void setUserText(std::string labelText);
	void handleEvent(sf::RenderWindow& window);
	void handleInput(sf::RenderWindow& window);
	bool getSceneState();
private:
	Label titleLabel;
	Label uiText;
	Label SimpleLabel;
	Label GeneralLabel;
	RadioButton SimpleGame;
	RadioButton GeneralGame;
	sf::Event event; 
	bool sceneEnds;


};

#endif GAMESELECTOR_H