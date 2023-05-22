#include "poison.hpp"

Poison::Poison (char symbol, Board &board) : GameObject(symbol,board)
{
    this->spawn(board);
    this->counter ++;
    board.setCell(this->getPosition(),this->symbol);
}

void Poison::onCollision(Board &board)
{
    if (board.getCell(this->getPosition()) != '~')
    {
        board.setCell(this->getPosition(), ' ');
        counter --;
    }
}

void Poison::update(Board &board) 
{
    this->onCollision(board);
    if (this->counter < 1)
    {
        this->spawn(board);
        counter ++;
    }
    
}
