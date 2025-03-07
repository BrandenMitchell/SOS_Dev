#pragma once

#ifndef LABEL_H
#define LABEL_H
#include <string>

#include "SFML/Graphics.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>




class Label {



public:


	Label(float x, float y, const std::string& labelText, const std::string& color, int size );

	//draw our label to the screen 

	void draw_Label(sf::RenderWindow& window);
	
	//set the file for the font (therefore the font)
	// update the font variable  
	void set_Font(std::string& filename);
	sf::Color get_Color(const std::string& color);

	void set_LabelPos(sf::Vector2f newPos);
	void set_labelText(std::string& labelText);

	void set_labelColor(const std::string& labelColor);

private:
	//inits Text class as label 
	sf::Text label;
	//will hold the font 
	sf::Font font;
	sf::Vector2f pos;


};
	

// LABEL_H
#endif 