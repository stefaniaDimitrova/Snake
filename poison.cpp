#include "poison.hpp"
#include <fstream>

Poison::Poison()
{
    this->symbol = ' ';
}

Poison::Poison (char symbol, Board &board) : Food(symbol,board)
{

    count ++;
    board.setCell(getPosition(),symbol);
}

void Poison::onCollision(Board &board)
{
    if (board.getCell(this->getPosition()) != '~')
    {
        board.setCell(this->getPosition(), ' ');
        count --;
    }
}
