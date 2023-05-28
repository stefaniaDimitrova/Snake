#pragma once
#include "board.hpp"

class ISpawner
{
    public:
    virtual void spawn(Board &board) = 0;
};