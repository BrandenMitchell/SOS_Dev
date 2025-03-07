#pragma once
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "GameMode.h"
#include "GridClass.h"


class Game {

public:
    Game(std::unique_ptr<GameMode> mode, int rows, int cols );
    void start();

private:
    std::unique_ptr<GameMode> mode;
    Grid grid;

};

#endif // GAME_H