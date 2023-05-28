#pragma once
#include <iostream>
#include <vector>
#include "point.hpp"

/*! Class Board */

class Board
{
    /*! 
    * Variables in the class Board: 
    * width - the number of columns;
    * height - the number of rows
    * grid - a vector of characters representing the board
    */
    private:
    int width;
    int height;
    std::vector<std::vector<char>> grid;

    public:
    /*! Default constructor for board, setting the height and width to 0*/
    Board();

    /*! Method to make all the fields in the board empty again (' ')*/
    void clear();

    /*! Checking if a certain position leaves the bounds of the board
    * @return true if the point is on the border or outside of it
    * @return false if the point is inside the borders
    * @param position gives us the position that we are going to check */
    bool notBorder(Point position);

    /*! Sets the width to a certain value
        @param a is the width that the board is going to have */ 
    void setWidth(int a);

    /*! Sets the height to a certain value
        @param a is the width that the board is going to have */ 
    void setHeight(int a);

    /*! Puts a specific symbol on the board
        @param position tells us where the symbol will be put
        @param symbol tells us what the symbol is going to be */ 
    void setCell(Point position, char symbol);

    /*! @return the symbol that is in a certain position */ 
    char getCell(Point position) const;

    /*! @return the width of the board */
    int getWidth () const;

    /*! @return the height of the board */
    int getHeight() const;

    /*! Generates a board with heigth rows and width columns ans puts border symbols in the edges:
       * | - left and right border
       * _ - upper border
       * - - lower border */
    void generateGrid();

    /*! Prints the board in the terminal */
    void render();

    /*! Default constructor because there is no dynamic memory */
    virtual ~Board() = default;
};