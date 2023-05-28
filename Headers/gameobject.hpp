#pragma once 
#include "iupdateable.hpp"
#include "point.hpp"
#include "board.hpp"
#include "controls.hpp"
#include "conio.h"
#include <random>
#include <iostream>

/*! Class GameObject that stores all the objects in the game */
class GameObject : public ISpawner
{
    /*! it has a position and a symbol */
    protected:
    Point position;
    char symbol;

    public:
    /*! Default constructor */
    GameObject();

    /*! Parametric consructor puting a specific symbol at a certain position*/
    GameObject(char symbol, Board &board);

    /*! Getter for the position */
    Point getPosition() const;

    /*! Getter for the symbol */
    char getSymbol() const;

    /*! Setter for the position */
    void setPosition(Point position);

    /*! Setter for the symbol */
    void setSymbol(char symbol);

    /*! Spawns a game object at a random position on the board
    * !The code for the spawn is not an original implementation!
    * !This is used code! */
    virtual void spawn(Board &board) override;

    /*! Puts the symbol on the board */
    virtual void render(Board &other);

    /*! Default behaviour on collision */
    virtual void onCollision(Board &board);
};