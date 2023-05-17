#pragma once
#include <iostream>
#include <vector>
#include "point.hpp"

//the play field

class Board
{
    private:
    int width;
    int height;
    std::vector<std::vector<char>> grid;

    public:
    Board(int width, int height);
    void clear();
    bool notBorder(Point position);
    void setCell(Point position, char symbol);
    char getCell(Point position) const;
    int getWidth () const;
    int getHeight() const;
    void render();
};