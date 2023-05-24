#include "food.hpp"

Food::Food (char symbol, Board &board) : GameObject(symbol,board) 
{
    std::cout << "Food:" << std::endl;

    this->spawn(board);
    this->count ++;
    board.setCell(this->getPosition(),this->symbol);

    std::cout << this->getPosition().x << " " << this->getPosition().y << std::endl;

}

void Food::onCollision(Board &board)
{
    if (board.getCell(this->getPosition()) != '+')
    {
        board.setCell(this->getPosition(), ' ');
        count --;
    }
}

void Food::update(Board &board)
{
   this-> onCollision(board);
    if (count < 1)
    {
        this->spawn(board);
        count++;
    }
}