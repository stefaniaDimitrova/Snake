#include "gameobject.hpp"

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
    // int seed_value;
    // srand(seed_value);
    // int random_x = 1 + (rand() % board.getWidth() - 1);
    // int random_y = 1 + (rand() % board.getHeight() - 1);
    // if (seed_value < 0)
    // {
    //     seed_value *= -1;
    // }
    

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution <> dis_x(1,board.getWidth()-1);
    std::uniform_int_distribution <> dis_y(1,board.getHeight()-1);
    int random_x = dis_x(gen);
    int random_y = dis_y(gen);

    this->setPosition(Point(random_x,random_y));
}

void GameObject::update(Board &board) 
{

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