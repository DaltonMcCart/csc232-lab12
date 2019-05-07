/**
 * CSC232 Data Structures
 * Missouri State University, Spring 2019
 *
 * Lab 12 - Dynamic Programming: The Jumping Game
 * @file JumpItGame.cpp
 * @authors Jim Daehn <jdaehn@missouristate.edu>
 *          TODO: Put your name here
 * @brief JumpItGame implementation.
 */

#include "JumpItGame.h"

JumpItGame::JumpItGame(std::vector<int> board) : gameBoard{std::move(board)} {
    // Intentionally blank
}

int JumpItGame::play() {
    int score = play(BOTTOM_UP);
    return score;
}

int JumpItGame::play(Technique technique) {
    int score;
    switch (technique) {
        case BOTTOM_UP:
            score = jumpItBottomUp(gameBoard);
            buCacheTable.clear();
            break;
        case TOP_DOWN:
            score = jumpItTopDown(gameBoard, 0);
            tdCacheTable.clear();
            break;
        default:
            score = jumpItBottomUp(gameBoard);
            buCacheTable.clear();
            break;
    }
    return score;
}

// private helper function implementations

int JumpItGame::jumpItBottomUp(std::vector<int> board) {
    // TODO: Implement me
    return 0;
}

int JumpItGame::jumpItTopDown(std::vector<int> board, int currentPosition) {
    // TODO: Implement me
    return 0;
}

int JumpItGame::len(std::vector<int> board) {
    return static_cast<int>(board.size());
}


