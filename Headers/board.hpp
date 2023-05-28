#pragma once
#include <iostream>
#include <vector>
#include "point.hpp"

class Board
{
    private:
    int width;
    int height;
    std::vector<std::vector<char>> grid;

    public:
    Board();
    void clear();
    bool notBorder(Point position);
    void setWidth(int a);
    void setHeight(int a);
    void setCell(Point position, char symbol);
    char getCell(Point position) const;
    int getWidth () const;
    int getHeight() const;
    void generateGrid();
    void render();

    virtual ~Board() = default;
};