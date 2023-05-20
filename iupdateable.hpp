#pragma once
#include "board.hpp"

class IUpdateable
{
    public:
    virtual void update(char input, Board &board) = 0;
};