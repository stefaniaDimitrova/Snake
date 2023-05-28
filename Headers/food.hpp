#pragma once
#include "gameobject.hpp"

/*! Class food which is inheritant of GameObject */
class Food : public GameObject
{
    /*! Count keeps track of how any objects of this type are currently on the board */
    protected :
    unsigned count = 0;

    public:
    /*! Default constructor which sets the symbol to ' ' */
    Food();

    /*! Parametric constructor that puts a symbol on the board
    *@param symbol tells us what char will be put on the board 
    *@param board gives us the sizes of the field we have*/
    Food(char symbol, Board &board);
    
    /*! Method that sets the object's behaviour when it collides with another one */
    virtual void onCollision(Board &board) override;

    /*! Method that updates the current state of the object and makes any neccessary changes */
    virtual void update(Board &board);

    /*! Virtual dectructor */
    virtual ~Food() = default;
};