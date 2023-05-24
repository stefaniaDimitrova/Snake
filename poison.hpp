#pragma once
#include "food.hpp"

class Poison : public Food
{
    public:
    Poison(char symbol, Board &board);

    virtual void onCollision(Board &board) override;

    virtual ~Poison() = default;
};