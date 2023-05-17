#pragma once
#include "board.hpp"
#include "snake.hpp"
#include "gameobject.hpp"

class Game
{
    protected:
    Board a;
    std::vector <GameObject> eatable;
};