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
    int n = len(board);

    buCacheTable[n - 1] = board[n - 1];
    buCacheTable[n-2] = board[n-2] + board[n-1];

    for (int i = n-3; i > -1; i--){
        buCacheTable[i] = board[i] + std::min(buCacheTable[i+1], buCacheTable[i+2]);
    }
    return buCacheTable[0];
}

int JumpItGame::jumpItTopDown(std::vector<int> board, int currentPosition) {
    int n = len(board);

    if (tdCacheTable[currentPosition] == 0) {
        if (currentPosition == n - 1){
            tdCacheTable[currentPosition] = board[n-1];
        }
        else if (currentPosition == n-2) {
            tdCacheTable[currentPosition] = board[n-2] + board[n-1];
        }
        else {
            int tdCacheTable1 = jumpItTopDown(board, currentPosition+1);
            int tdCacheTable2 = jumpItTopDown(board, currentPosition+2);
            tdCacheTable[currentPosition] = board[currentPosition] + std::min(tdCacheTable1, tdCacheTable2);
        }
    }

    return tdCacheTable[currentPosition];
}

int JumpItGame::len(std::vector<int> board) {
    return static_cast<int>(board.size());
}


