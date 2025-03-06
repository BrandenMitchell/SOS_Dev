#pragma once
#include <string>
#include "UI_Label.h"
#include "SFML/Graphics.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <iostream>
#include <map>





Label::Label(float x, float y, const std::string& labelText, const std::string& color, int size){
	
	//load the font file
	//if fails throw err
	if (!font.loadFromFile("include/Pixellettersfull-BnJ5.ttf")) {
		std::cerr << "Error loading font!" << std::endl;
	}

	// initialize label object
	sf::Color label_color = Label::get_Color(color);
	label.setString(labelText);
	label.setFont(font);
	label.setFillColor(label_color);
	label.setPosition(sf::Vector2f(x, y));
	label.setCharacterSize(size);



}

//setup color for the label 
sf::Color Label::get_Color(const std::string& color) {
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

//draw our label to the screen 
void Label::draw_Label(sf::RenderWindow& window) {
	window.draw(label);

}

void Label::set_labelText(std::string& labelText) {
	label.setString(labelText);

}

void Label::set_labelColor(const std::string& labelColor) {
	sf::Color color = get_Color(labelColor);
	label.setFillColor(color);
}

//set the file for the font (therefore the font)
// update the font variable  
void Label::set_Font(std::string& filename) {
	if (!font.loadFromFile("include/"+filename+".ttf")) {
		std::cerr << "Error loading The New font!" << std::endl;
	}
}

	
	
	


