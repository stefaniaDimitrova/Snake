#include "../Headers/food.hpp"

Food::Food()
{
    this->symbol = ' ';
}

Food::Food (char symbol, Board &board) : GameObject(symbol,board) 
{
    this->spawn(board);
    this->count ++;
    board.setCell(this->getPosition(),this->symbol);
}

// const unsigned Food::getCount() const
// {
//     return this->count;
// }

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
   if (this->count < 1)
   {
    this->spawn(board);
    this->count++;
   }
}