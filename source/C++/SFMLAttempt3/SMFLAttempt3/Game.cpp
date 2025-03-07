#pragma once
#include "Game.h"
#include "GridClass.h"



Game::Game(std::unique_ptr<GameMode> mode, int rows, int cols ) : mode(std::move(mode)), grid(rows,cols) {

}
void Game::start() {
	std::cout << "Game is Loading...\n" << std::endl;
	mode->Rules();
	
}