#pragma once
#ifndef GAME_H
#define GAME_H

#include <memory>
#include "GameMode.h"

class Game {
public:
    Game(std::unique_ptr<GameMode> mode);
    void start();

private:
    std::unique_ptr<GameMode> mode;
};

#endif // GAME_H