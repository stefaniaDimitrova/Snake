#pragma once

/*! Class contol to set the chars that each player will use to move */
class Control
{
    /*! Char variables representing the different directions */
    private:
    char up, down, left, right;

    public:
    /*! Default constructor setting all the chars to ' ' */
    Control();

    /*! Parametric constructor
        *@param up is what char controls the up direction
        * @param down is what char controls the down direction
        * @param left is what controls the left direction
        * @param right is what controls the right direction */
    Control(char up, char down, char left, char right);

    /*! Getter for the up char */
    const char getUp() const;

    /*! Getter for the down char */
    const char getDown() const;

    /*! Getter for the left char */
    const char getLeft() const;

    /*! Getter for the rigth char */
    const char getRight() const;

    /*! Default destructor because we don't have any dynamic variables */
    virtual ~Control() = default;
};