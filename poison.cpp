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
    // std::ofstream ofs("log.txt", std::ios::app);
    // ofs << "Poison position: " << this -> position.x << ' ' << this -> position.y << '\n';
    // ofs.close();

}

void Poison::onCollision(Board &board)
{
    if (board.getCell(this->getPosition()) != '~')
    {
        board.setCell(this->getPosition(), ' ');
        count --;
    }
}
