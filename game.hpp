#pragma once
#include "board.hpp"
#include "snake.hpp"
#include "food.hpp"
#include "poison.hpp"
#include "ui.hpp"
#include "gameobject.hpp"

class Game
{
    protected:

    Board board;
    // std::vector<Food> eatables;
    Food food;
    Poison poison;
    int counter = 0;
    std::vector<Snake> players;
    // Snake player1;
    // Snake player2;
    unsigned player = 2;

    public:
    Game();
    std::vector <Snake> getPlayers() const;
    bool gameOver();
    void setPlayers(unsigned num);
    void goToNextLevel();
    int generateRandomFood();
    void start();
};