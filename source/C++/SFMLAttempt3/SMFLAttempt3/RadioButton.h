#pragma once
#ifndef RadioButton_H
#define RadioButton_H
#include <iostream>
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>



class RadioButton {


public:
	//default constructor 
	RadioButton(float x, float y, float OuterRadius, float InnerRadius);

	//handle logic for a clicked button
	//update state of button via isSelected and make sure clicking of button happens inside the bounds of the button
	bool handleClick(float x, float y);

	//color func to handle mapping developer colors to useful built in colors
	sf::Color get_Color(const std::string& color);


	//draw button
	void drawButton(sf::RenderWindow& window);

	//change inner and outer color of the radio buttons
	void setColor(std::string& innerColor, std::string outerColor);

	void setInnerColor(std::string innerColor);
	//reset the buttons selected state
	void reset();
	//change state
	void setState(bool state);

	//getters and setters 
	void setOuterRadius(float r);

	void setInnerRadius(float r);
	
	//might not need this 
	void changePos(float x, float y);

	float getOuterRadius();
	float getInnerRadius();
	sf::Vector2f getPosition();
	bool getState();

private:
	//inner and outer circle objects for the radio buttons
	sf::CircleShape outerCircle;
	sf::CircleShape innerCircle;
	
	//Radio button position
	sf::Vector2f buttonPos;

	//inner and outer radius measurements (size of cirlces)
	float outerRadius;
	float innerRadius;

	//tracks state of the button
	bool isSelected;

	sf::Color innerCircleColor; 


};
#endif 