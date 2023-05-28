#pragma once

class Point
{
    public:
    int x;
    int y;
    Point (int a, int b);
    Point();
    bool operator == (Point & other);
    bool operator != (Point &other);

    virtual ~Point() = default;
};
