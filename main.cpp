/**
 * CSC232 Data Structures
 * Missouri State University, Spring 2019
 *
 * Lab 12 - Dynamic Programming: The Jumping Game
 * @file   Main.cpp
 * @author Jim Daehn <jdaehn@missouristate.edu>
 * @brief  Entry point for lab12 target.
 */

#include <iostream>
#include <fstream>
#include "Game.h"
#include "JumpItGame.h"

/* Function prototypes */

/**
 * Entry point to the lab12 target.
 * @return EXIT SUCCESS is returned if all games are played successfully, EXIT FAILURE if the game data
 * could not be read.
 */
int main();

/**
 * Read data for a number of boards from a text file
 * @param filename the name of the file containing the board data
 * @return A vector of game boards (i.e., vector of ints) read from the given file is returned.
 */
std::vector<std::vector<int>> readGameBoardsFrom(const std::string &filename);

/**
 * Report error reading the given filename and terminate abnormally.
 * @param filename the name of the file that could not be opened or read
 */
void fileReadError(const std::string& filename);

/* Function implementations */

int main() {
    int score;
    Game* game = new JumpItGame();
    score = game->play();
    delete game;

    std::cout << "Default game score: " << score << std::endl;

    std::vector<std::vector<int>> boards = readGameBoardsFrom("lab12.txt");
    std::cout << std::endl;
    std::cout << "Playing game boards from file (using memoization)" << std::endl;
    int gameNum{1};
    for (const auto& board: boards) {
        game = new JumpItGame(board);
        score = game->play();
        std::cout << "Game " << gameNum++ << " score: " << score << std::endl;
        delete game;
    }

    std::cout << "\nPlaying game boards from file (using tabulation)" << std::endl;
    gameNum = 1;
    for (const auto& board: boards) {
        game = new JumpItGame(board);
        score = game->play(TOP_DOWN);
        std::cout << "Game " << gameNum++ << " score: " << score << std::endl;
        delete game;
    }

    exit(EXIT_SUCCESS);
}

std::vector<std::vector<int>> readGameBoardsFrom(const std::string &filename) {
    // attempt to open file for reading
    std::ifstream src{filename};
    if (!src) {
        // apparently couldn't read the file
        fileReadError(filename);
    }

    std::vector<std::vector<int>> boards;
    std::string line;
    while (std::getline(src, line)) {
        std::string delimiter{", "};
        size_t pos{0};
        std::string token;
        std::vector<int> board;
        // iterate through each token (except the last one) in the current line
        while((pos = line.find(delimiter)) != std::string::npos) {
            token = line.substr(0, pos);
            // convert the token to an int and push it into the current game board
            board.push_back(std::stoi(token));
            // erase what we just read so we can find the next token
            line.erase(0, pos + delimiter.length());
        }
        // finally convert and add the last token to the current game board
        board.push_back(std::stoi(line));
        // add the current game board to the vector of game boards
        boards.push_back(board);
    }
    // release file handle
    src.close();

    return boards;
}

void fileReadError(const std::string& filename) {
    std::cerr << "Unable to open file: " << filename << std::endl;
    std::cerr << "Terminating program abnormally" << std::endl;
    exit(EXIT_FAILURE);
}