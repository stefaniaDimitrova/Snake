#pragma once
#include "board.hpp"
#include "snake.hpp"
#include "gameobject.hpp"

class Game
{
    protected:
    Board board;
    std::vector <GameObject> eatables;
    unsigned num = 20;
    std::vector<Snake> players;
    unsigned play;

    public:
    Game();
    void start();
};