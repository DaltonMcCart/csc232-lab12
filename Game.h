/**
 * CSC232 Data Structures
 * Missouri State University, Spring 2019
 *
 * Lab 12 - Dynamic Programming: The Jumping Game
 * @file   Game.h
 * @author Jim Daehn <jdaehn@missouristate.edu>
 * @brief  JumpItGame specification.
 */

#ifndef LAB12_GAME_H
#define LAB12_GAME_H

/**
 * An enumeration of dynamic programming techniques used to dictate an implementation of this Game.
 */
enum Technique {
    BOTTOM_UP, TOP_DOWN
};

/**
 * A Game ADT that serves as the basis for any game implemented using either bottom-up or top-down techniques.
 */
class Game {
public:
    /**
     * Play the Game (using the bottom-up approach).
     * @return The score of playing this game.
     */
    virtual int play() = 0;

    /**
     * Play the Game using the given technique.
     * @param technique set to BOTTOM_UP or TOP_DOWN for each respective technique.
     * @return The score of playing this game.
     */
    virtual int play(Technique technique) = 0;

    /**
     * Default destructor.
     */
    virtual ~Game() = default;
};

#endif //LAB12_GAME_H
