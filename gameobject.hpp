#pragma once 
#include "iupdateable.hpp"
#include "point.hpp"
#include "board.hpp"
#include "controls.hpp"
#include "conio.h"
#include <random>
#include <iostream>

class GameObject : public ISpawner
{
    protected:
    Point position;
    char symbol;

    public:
    GameObject(char symbol, Board &board);
    Point getPosition() const;
    char getSymbol() const;
    void setPosition(Point position);
    void setSymbol(char symbol);
    //more validations to be added?
    virtual void spawn(Board &board) override;
    virtual void update(Board &board);
    virtual void render(Board &other);
    //what happens here?
    virtual void onCollision(Board &board);
};