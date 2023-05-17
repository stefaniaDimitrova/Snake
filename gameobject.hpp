#pragma once 
#include "iupdateable.hpp"
#include "point.hpp"
#include "board.hpp"
#include "controls.hpp"
#include <iostream>

class GameObject : public IUpdateable
{
    private:
    

    protected:
    Point position;
    Control ctrl;
    char symbol;

    public:
    GameObject(Point position, Control ctrl, char symbol, Board &board);
    Point getPosition() const;
    char getSymbol() const;
    void setPosition(Point position);
    virtual void update() override;
    void move();
    virtual void render();
    virtual void onCollision(GameObject &other);
};