#include "poison.hpp"

Poison::Poison (char symbol, Board &board) : Food(symbol,board)
{
    std::cout << "Poison:" << std::endl;

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
