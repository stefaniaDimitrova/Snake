//the apple that the snake eats
#pragma once
#include "gameobject.hpp"

class Food : public GameObject
{
    protected :
    unsigned count = 0;

    public:
    Food(char symbol, Board &board);
    virtual void onCollision(Board &board) override;
    virtual void update(Board &board);

    virtual ~Food() = default;
};