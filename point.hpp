#pragma once

class Point
{
    public:
    int x;
    int y;
    Point (int a, int b);
    Point();

    virtual ~Point() = default;
};
