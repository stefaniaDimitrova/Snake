#include "gameobject.hpp"

GameObject::GameObject(Point position, Control ctrl, char symbol, Board &board) : position(position), ctrl(ctrl),symbol(symbol) 
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

void GameObject::update(char input)
{
    //update position using user input
    
    this->move(input);


    //check for collision
    
}

void GameObject::move(char input)
{   
        if (input == ctrl.down)
        {
            position.y++;
        }
        else if (input == ctrl.up)
        {
            position.y--;
        }
        else if (input == ctrl.left)
        {
            position.x--;
        }
        else if (input == ctrl.right)
        {
            position.x++;
        }
        else if (input == 'q')
        {
           return;
        }
    }

void GameObject::render(Board &other)
{
    other.setCell(this->position,this->symbol);
    system("cls");
}

void GameObject::onCollision(GameObject &other)
{

}