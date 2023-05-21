#include "gameobject.hpp"

GameObject::GameObject(char symbol, Board &board) : position(position),symbol(symbol) 
{
    board.setCell(position,symbol);
    this->spawn(board);
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

void GameObject::spawn(Board&board)
{
    unsigned int seed_value;
    srand(seed_value);
    int random_x = 1 + (rand() % board.getWidth() - 1);
    int random_y = 1 + (rand() % board.getHeight() - 1);
    this->setPosition(Point(random_x,random_y));
}

void GameObject::update(Board &board) 
{
    board.setCell(this->getPosition(), this->getSymbol());
}

void GameObject::render(Board &other)
{
    other.setCell(this->position,this->symbol);
    system("cls");
}

void GameObject::onCollision(Board &board)
{
    if (board.getCell(this->getPosition()) != ' ')
    {
        board.clear();
    }
}