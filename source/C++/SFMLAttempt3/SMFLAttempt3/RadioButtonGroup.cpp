#pragma once




#include "RadioButtonGroup.h"
#include "RadioButton.h"
#include <vector>


void RadioButtonGroup::addRadioButton(RadioButton* radioButton) {
	buttonsInGroup.push_back(radioButton);

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