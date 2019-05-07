/**
 * CSC232 Data Structures
 * Missouri State University, Spring 2019
 *
 * Lab 12 - Dynamic Programming: The Jumping Game
 * @file   JumpItGame.h
 * @author Jim Daehn <jdaehn@missouristate.edu>
 * @brief  JumpItGame specification.
 */

#ifndef LAB12_JUMPITGAME_H
#define LAB12_JUMPITGAME_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

#include "Game.h"

class JumpItGame : public Game {
public:
    /**
     * Initializing constructor.
     * @param board a game board for this game
     */
    explicit JumpItGame(std::vector<int> board = std::vector<int>{0, 5, 75, 7, 43, 11});

    /**
     * Play the Jump It Game (using the bottom-up approach).
     * @return The score of playing this game.
     */
    int play() override;

    /**
     * Play the Jump It Game using the given technique.
     * @param technique set to BOTTOM_UP or TOP_DOWN for each respective technique.
     * @return The score of playing this game.
     */
    int play(Technique technique) override;

private:
    /**
     * The playing board for this game.
     */
    std::vector<int> gameBoard;

    /**
     * An independent associative array, i.e., table, to cache solutions to sub-problems in the bottom-up
     * implementation.
     */
    std::map<int, int> buCacheTable;

    /**
     * An independent associative array, i.e., table, to cache solutions to sub-problems in the top-down implementation.
     */
    std::map<int, int> tdCacheTable;

    /**
     * Bottom-up solution to the Jump It Game
     * @param board the game board
     * @return The lowest cost in navigating the board by the rules of the game is returned.
     */
    int jumpItBottomUp(std::vector<int> board);

    /**
     * Top-down solution to the Jump It Game
     * @param board the game board
     * @param currentPosition the current cell in the game board
     * @return The lowest cost in navigating the board by the rules of the game is returned.
     */
    int jumpItTopDown(std::vector<int> board, int currentPosition);

    /**
     * Get the size of the playing board.
     * @param board the current Jump It playing board
     * @return The size of the board, as an int, is returned.
     */
    int len(std::vector<int> board);
};


#endif //LAB12_JUMPITGAME_H
