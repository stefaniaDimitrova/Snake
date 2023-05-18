#include "gameobject.hpp"

GameObject::GameObject(Point position, char symbol, Board &board) : position(position),symbol(symbol) 
{
    board.setCell(position,symbol);
}

Point GameObject::getPosition() const
{
    return this->position;
}
char GameObject::getSymbol() const
{
    return this->symbol;
}

void GameObject::setPosition(Point position)
{
    this->position = position;
}

void GameObject::setSymbol(char symbol)
{
    this->symbol = symbol;
}

void GameObject::update(char input) 
{
    //spawn
}

void GameObject::render(Board &other)
{
    other.setCell(this->position,this->symbol);
    system("cls");
}

void GameObject::onCollision(GameObject &other)
{
    //what happens here?
}