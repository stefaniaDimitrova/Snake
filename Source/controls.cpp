#include"../Headers/controls.hpp"

Control::Control() : up(' '), down(' '), left(' '), right(' ') {}

Control::Control(char up, char down, char left, char right) :
                up(up), down(down), left(left), right(right){}

const char Control::getUp() const
{
    return this->up;
}

const char Control::getDown() const
{
    return this->down;
}

const char Control::getRight() const
{
    return this->right;
}

const char Control::getLeft() const
{
    return this->left;
}

