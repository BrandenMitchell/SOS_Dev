#pragma once
#ifndef RadioButtonGroup_H
#define RadioButtonGroup_H

#include "RadioButton.h"
#include <vector>


class RadioButtonGroup {
public:
	//more of a container no need to add params
	//create group
	RadioButtonGroup() = default;

	//add a button to the group 
	void addRadioButton(RadioButton* radioButton);

	//keeps currently selected button and unselects others in a group
	void selectRadioButton(RadioButton* currentlySelectedBtn);



private:
	std::vector<RadioButton*> buttonsInGroup;

};

#endif // !RadioButtonGroup_H
