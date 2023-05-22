#pragma once
#include "gameobject.hpp"

class Poison : public GameObject
{
    protected:
    unsigned counter = 0;

    public:
    Poison(char symbol, Board &board);

    virtual void onCollision(Board &board) override;
    virtual void update(Board &board) override;

    virtual ~Poison() = default;
};