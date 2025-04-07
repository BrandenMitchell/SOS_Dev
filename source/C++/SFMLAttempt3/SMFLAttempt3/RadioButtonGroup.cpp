#pragma once




#include "RadioButtonGroup.h"
#include "RadioButton.h"
#include <vector>


void RadioButtonGroup::addRadioButton(RadioButton* button) {
	buttonsInGroup.push_back(button);

}

std::string RadioButtonGroup::findSelection() {
	std::string key;
	for (auto& button : buttonsInGroup) {
		if (button->getState() == true) {
			key = button->getName();
			return key;
		}
	}
}

void RadioButtonGroup::updateGroup(std::string key) {
	for (auto& button : buttonsInGroup) {
		if (button->getName() != key) {
			button->setState(false);
			button->setState(false);
			button->setInnerColor("Transparent");
			button->setInnerColor("Transparent");
		}
	}
}



void RadioButtonGroup::selectRadioButton(RadioButton* currentlySelected) {

	for (auto& button : buttonsInGroup) {
		if (button->getState() == true) {
			if (button != currentlySelected) {
				button->setState(false);
				button->setInnerColor("Transparent");

			
			}
			button->setState(false);
		}
		currentlySelected->setState(true);
		currentlySelected->setInnerColor("Black");
	}
	
	std::cout << "set the button to true"<< std::endl;

	
}
