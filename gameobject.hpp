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
    GameObject();
    GameObject(char symbol, Board &board);
    Point getPosition() const;
    char getSymbol() const;
    void setPosition(Point position);
    void setSymbol(char symbol);
    virtual void spawn(Board &board) override;
    virtual void render(Board &other);
    virtual void onCollision(Board &board);
};