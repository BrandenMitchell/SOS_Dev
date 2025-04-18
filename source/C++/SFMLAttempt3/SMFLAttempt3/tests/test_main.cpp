#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"

#include <string>  // Required for std::string
#include <vector>  // Required for std::vector
#include <iostream>

TEST_CASE("Intentional Failure Test") {
    REQUIRE(1 + 1 == 3); // This will FAIL
}

TEST_CASE("Force output test") {
    std::cout << "This test is running!\n";
    REQUIRE(1 + 1 == 3); // Intentional fail
}




TEST_CASE("Bot selects a random position and makes a valid move", "[bot][move]") {
    int gridSize = 3;
    Grid grid(gridSize);
    Bot bot;

    // Attach a game mode (SimpleMode or GeneralMode)
    std::shared_ptr<GameMode> mode = std::make_shared<SimpleMode>();
    bot.setGameMode(mode);

    // Make sure all cells are empty
    for (int r = 0; r < gridSize; ++r)
        for (int c = 0; c < gridSize; ++c)
            REQUIRE(grid.getCellState(r, c) == 0);

    bot.botMakeMove(grid, 1, gridSize); // 1 = player ID (blue/red)

    // After move, at least one cell should be filled (non-zero)
    bool foundMove = false;
    for (int r = 0; r < gridSize; ++r) {
        for (int c = 0; c < gridSize; ++c) {
            if (grid.getCellState(r, c) != 0) {
                foundMove = true;
            }
        }
    }

    REQUIRE(foundMove == true);
}

TEST_CASE("Bot handles full grid gracefully", "[bot][fullGrid]") {
    int gridSize = 3;
    Grid grid(gridSize);
    Bot bot;

    std::shared_ptr<GameMode> mode = std::make_shared<SimpleMode>();
    bot.setGameMode(mode);

    // Fill the grid manually (simulate end-game)
    for (int r = 0; r < gridSize; ++r)
        for (int c = 0; c < gridSize; ++c)
            grid.setCellState(r, c, 1); // Assume 1 = filled

    // Bot tries to move on a full board (should not crash)
    REQUIRE_NOTHROW(bot.botMakeMove(grid, 1, gridSize));
}

TEST_CASE("Bot detects game over correctly", "[bot][gameover]") {
    int gridSize = 3;
    Grid grid(gridSize);
    Bot bot;

    std::shared_ptr<GameMode> mode = std::make_shared<SimpleMode>();
    bot.setGameMode(mode);

    // Fill up the grid with no moves left
    for (int r = 0; r < gridSize; ++r)
        for (int c = 0; c < gridSize; ++c)
            grid.setCellState(r, c, 1); // Assume all cells are filled

    // Manually set the mode to finished
    mode->checkGameEnd(); //

    REQUIRE(bot.isBotGameOver() == true);
}

TEST_CASE("Bot can reset the game", "[bot][reset]") {
    int gridSize = 3;
    Grid grid(gridSize);
    Bot bot;

    std::shared_ptr<GameMode> mode = std::make_shared<SimpleMode>();
    bot.setGameMode(mode);

    // Fill one cell and trigger reset
    grid.setCellState(0, 0, 1); 
    bot.resetGame();

    // Make sure all cells are now empty again
    for (int r = 0; r < gridSize; ++r)
        for (int c = 0; c < gridSize; ++c)
            REQUIRE(grid.getCellState(r, c) == 0);
}