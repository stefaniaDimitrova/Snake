#include "food.hpp"

Food::Food (char symbol, Board &board) : GameObject(symbol,board) {
    this->spawn(board);
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