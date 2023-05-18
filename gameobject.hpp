#pragma once 
#include "iupdateable.hpp"
#include "point.hpp"
#include "board.hpp"
#include "controls.hpp"
#include "conio.h"
#include <iostream>

class GameObject : public IUpdateable
{
    protected:
    Point position;
    Control ctrl;
    char symbol;

    public:
    GameObject(Point position, Control ctrl, char symbol, Board &board);
    Point getPosition() const;
    char getSymbol() const;
    void setPosition(Point position);
    //more validations to be added?
    virtual void update(char input) override;
    void move(char input);
    virtual void render(Board &other);
    //what happens here?
    virtual void onCollision(GameObject &other);
};