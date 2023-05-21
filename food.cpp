#include "food.hpp"

Food::Food (char symbol, Board &board) : GameObject(symbol,board) 
{
    this->spawn(board);
    std::cout << "food" << std::endl;
    std::cout << "x: " << this->getPosition().x<< " y: " << this->getPosition().y<< std::endl; 

}

void Food::onCollision(Board &board)
{
    if (board.getCell(this->getPosition()) != '+')
    {
        board.setCell(this->getPosition(), ' ');
    }
    count --;
}

void Food::update(Board &board)
{
    if (count < 1)
    {
        this->spawn(board);
        count++;
    }
}