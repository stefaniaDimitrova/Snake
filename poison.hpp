#pragma once
#include "food.hpp"

class Poison : public Food
{
    public:
    Poison(char symbol, Board &board);

    virtual ~Poison() = default;
};