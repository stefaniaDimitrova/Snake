#pragma once
#include "gameobject.hpp"

class Food : public GameObject
{
    protected :
    unsigned count = 0;

    public:
    Food();
    Food(char symbol, Board &board);
    // const unsigned getCount() const;
    virtual void onCollision(Board &board) override;
    virtual void update(Board &board);

    virtual ~Food() = default;
};