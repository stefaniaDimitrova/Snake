#pragma once
#include <windows.h>
#include "board.hpp"
#include "snake.hpp"
#include "food.hpp"
#include "poison.hpp"
#include "ui.hpp"
#include "gameobject.hpp"

/*! Class Game which holds all the necessary objects fro the game */

class Game
{
    /*! Variables for the game:
    * board - gives us a board
    * food - gives us food object
    * poison - a poison object 
    * speed - it is used when we want to change the difficulty of the game, it keeps track of the current speed. By defaults, it is set to easy(1)
    * assisted - tells us whether the computer will be managing one of the players
    * players - vector of Snake objects where we will store our players
    * player - the number of players that will participate in the game, by default it is 2*/
    protected:
    Board board;
    Food food;
    Poison poison;
    int speed;
    bool assisted;
    std::vector<Snake> players;
    unsigned player = 2;

    public:
    /*! Default coustructor which creates all the objects that we need in the game and sets their default values */
    Game();

    /*! Getter for the players */
    std::vector <Snake> getPlayers() const;

    /*! Checks if the game has ended */
    bool gameOver();

    /*! Sets how many players will play */
    void setPlayers(unsigned num);

    /*! Sets the speed of the players */
    void setSpeed(int speed);

    /*! Sets the assistance */
    void setAssisted(bool ass);

    /*! Method to start the game */
    void start();
};