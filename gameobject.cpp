#include "gameobject.hpp"

GameObject::GameObject() : position(Point(1,1)), symbol(' ') {}

GameObject::GameObject(char symbol, Board &board) : symbol(symbol) {}

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

void GameObject::spawn(Board &board)
{
    //used code for the spawner
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution <> dis_x(2,board.getWidth()-2);
    std::uniform_int_distribution <> dis_y(2,board.getHeight()-2);
    int random_x = dis_x(gen);
    int random_y = dis_y(gen);

    this->setPosition(Point(random_x,random_y));
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