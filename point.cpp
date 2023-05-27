#include "point.hpp"

Point::Point (int a, int b) : x(a), y(b) {}

Point::Point() : x(1), y(1) {}

bool Point::operator == (Point & other)
{
    return (this->x == other.x && this->y == other.y);
}

bool Point::operator != (Point &other)
{
    return !(this->x == other.x && this->y == other.y);
}
