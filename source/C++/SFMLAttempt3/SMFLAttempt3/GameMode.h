#pragma once
#ifndef GameMode_H
#define GameMode_H
#include <iostream>
class GameMode {

public:
	//virtual function to apply the two gamemodes we will have, Gamemodes will be easy to plug and play
	//defined in their own classes
	virtual void Rules() = 0;
	
	//destructor

	virtual ~GameMode() = default;

};


#endif // !GameMode_H
