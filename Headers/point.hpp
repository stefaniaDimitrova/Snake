#pragma once

/*! Class Point */
class Point
{
    public:
    /*! X coordinate */
    int x;

    /*! Ycoordinate */
    int y;

    /*! Parametric constructor */
    Point (int a, int b);

    /*! Default constructor */
    Point();

    /*! Redefinition of operator == */
    bool operator == (Point & other);

    /*! Redefinition of operator == */
    bool operator != (Point &other);

    /*! Default destructor */
    virtual ~Point() = default;
};
