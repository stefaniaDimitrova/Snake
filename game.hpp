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
    Food food;
    Poison poison;
    int counter = 0;
    int speed;
    bool assisted;
    std::vector<Snake> players;
    unsigned player = 2;

    public:
    Game();
    std::vector <Snake> getPlayers() const;
    bool gameOver();
    void setPlayers(unsigned num);
    void setSpeed(int speed);
    void setAssisted(bool ass);
    void goToNextLevel();
    int generateRandomFood();
    void start();
};