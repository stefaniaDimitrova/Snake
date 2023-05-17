#include "board.hpp"

Board::Board(int width, int height) : width(width), height(height)
{
    //resizing the game board to height and width and initialising each space with a space char
    grid.resize(height,std::vector<char> (width, ' '));
    for (size_t i = 0; i < this->height; i++)
    {
        this->grid[i][0] = '|';
        this->grid[i][width-1] = '|';
    }
    for (size_t i = 0; i < this->width; i++)
    {
        this->grid[0][i] = '_';
        this->grid[height-1][i] = '-';
    }
    
    
}

void Board::clear()
{
    for (size_t i = 1; i < this->height-1; ++i)
    {
        for (size_t j = 1; j < this->width-1; j++)
        {
            this->grid[i][j] = ' ';
        }
    }
}

bool Board::notBorder(Point position)
{
    if (position.y == 0 || position.y == height-1 
        || position.x == 0 || position.x == width-1)
    {
        return false;
    }
    return true;
    
}

void Board::setCell(Point position, char symbol)
{
    if (!notBorder(position))
    {
        //exception
        std::cout << "You cannot acces the border!" << std::endl;
        return;
    }
    this->grid[position.y][position.x] = symbol;
}

char Board::getCell (Point position) const
{
    return this->grid[position.y][position.x];
}

int Board::getWidth() const
{
    return this->width;
}

int Board::getHeight() const
{
    return this->height;
}

void Board::render()
{
    for (size_t i = 0; i < this->height; ++i)
    {
        for (size_t j = 0; j < this->width; j++)
        {
            std::cout << this->grid[i][j];
        }
        std::cout << std::endl;
    }
}
