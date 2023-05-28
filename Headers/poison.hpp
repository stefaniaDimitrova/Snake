#pragma once
#include "food.hpp"

/*! Class Poison */
class Poison : public Food
{
    public:
    /*! Default constructor */
    Poison();

    /*! Parametric constructor */
    Poison(char symbol, Board &board);

    /*! Behaviour when it collides with another object */
    virtual void onCollision(Board &board) override;

    /*! Default destructor */
    virtual ~Poison() = default;
};