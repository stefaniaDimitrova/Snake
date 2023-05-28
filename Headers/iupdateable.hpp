#pragma once
#include "board.hpp"
/*! Interface that holds the spawn function */
class ISpawner
{
    public:
    virtual void spawn(Board &board) = 0;
};