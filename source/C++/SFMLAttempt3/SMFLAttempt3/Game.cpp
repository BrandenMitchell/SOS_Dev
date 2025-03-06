#pragma once
#include "Game.h"

Game::Game(std::unique_ptr<GameMode> mode) : mode(std::move(mode)) {

}
void Game::start() {
	std::cout << "Game is Loading...\n" << std::endl;
	mode->Rules();
}