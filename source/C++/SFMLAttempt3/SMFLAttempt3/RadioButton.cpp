#pragma once


#include <iostream>
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include "RadioButton.h"


//default constructor 
RadioButton::RadioButton(float x, float y, float OuterRadius, float InnerRadius): buttonPos(x,y), isSelected(false) {
	//initialize radius
	outerRadius = OuterRadius;
	innerRadius = InnerRadius;

	//initialize inner circle 
	outerCircle.setRadius(outerRadius);
	outerCircle.setPointCount(30);
	outerCircle.setFillColor(sf::Color::Blue);
	outerCircle.setPosition(x - outerRadius, y - outerRadius);
	
	//initialize outer circle
	innerCircle.setRadius(innerRadius);
	innerCircle.setPointCount(30);
	
	//this makes it default to be "unselected"
	innerCircle.setFillColor(sf::Color::Transparent);
	innerCircle.setPosition(x - innerRadius, y - innerRadius);
	isSelected = false;



}


//handle logic for a clicked button
//update state of button via isSelected and make sure clicking of button happens inside the bounds of the button
//We will pass this function x,y mouse pos and check if in bounds, if so flip selected
bool RadioButton::handleClick(float x, float y) {
	if (outerCircle.getGlobalBounds().contains(x, y)) {
		isSelected = !isSelected;
		if (isSelected) {
			innerCircle.setFillColor(innerCircleColor);
			return true;

		}
		else {
			innerCircle.setFillColor(sf::Color::Transparent);
			return true;
		}
	}
	else {
		return false;

	}

}


sf::Color RadioButton::get_Color(const std::string& color) {
	static const std::map<std::string, sf::Color> colorMap = {
		{"Red", sf::Color::Red},
		{"Green", sf::Color::Green},
		{"Blue", sf::Color::Blue},
		{"Black", sf::Color::Black},
		{"White", sf::Color::White},
		{"Yellow", sf::Color::Yellow},
		{"Magenta", sf::Color::Magenta},
		{"Transparent", sf::Color::Transparent},
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

//draw button
void RadioButton::drawButton(sf::RenderWindow& window) {
	window.draw(outerCircle);
	window.draw(innerCircle);

}

//change state
void RadioButton::setState(bool state) {
	isSelected = state;

}

//change inner and outer color of the radio buttons
void RadioButton::setColor(std::string& innerColor, std::string outerColor) {
	sf::Color outCol = RadioButton::get_Color(outerColor);
	sf::Color innCol = RadioButton::get_Color(innerColor);
	
	outerCircle.setFillColor(outCol);
	innerCircle.setFillColor(innCol);

}

void RadioButton::setInnerColor(std::string innerColor) {
	sf::Color innCol = RadioButton::get_Color(innerColor);
	innerCircle.setFillColor(innCol);
}


//reset the buttons selected state
void RadioButton::reset() {
	isSelected = false;

}


//setters 
void RadioButton::setOuterRadius(float r) {
	if (r > innerRadius) {
		outerRadius = r;
	}


}


void RadioButton::setInnerRadius(float r) {
	if (r < outerRadius) {
		innerRadius = r;
	}
	
	
}


//might not need this 
void RadioButton::changePos(float x, float y) {
	buttonPos = sf::Vector2f(x, y);

}


//getters
float RadioButton::getOuterRadius() {
	return outerRadius;
}


float RadioButton::getInnerRadius() {
	return innerRadius;
}


sf::Vector2f RadioButton::getPosition() {
	return buttonPos;
}



bool RadioButton::getState() {
	if (isSelected) {
		/*std::cout << "true" << std::endl;*/
		return true;
	}
	else {
		//std::cout << "false" << std::endl;
		return false;
	}

}