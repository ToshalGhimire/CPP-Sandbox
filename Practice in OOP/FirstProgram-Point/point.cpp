#include "Point.h"


//class constructor sets coordinates to user defined values in main
Point::Point(int x, int y)
{
    x_ = x;
    y_ = y;
}

//default constructor sets coordinates to the origin
Point::Point()
{
   x_ = 0;
   y_ = 0;
}

/**
    Returns distance between the object calling this function and the object passed in as parameter.

    @param a point object
    @return distance between two points
*/
double Point::Distance(Point dist)
{
    //set (x1,y1), (x2,y2) to objects values
    int x1 = this->get_x_();
    int y1 = this->get_y_();
    int x2 = dist.get_x_();
    int y2 = dist.get_y_();

    //calculates distance using the distance formula
    double distance = sqrt(pow((x2-x1),2) + pow((y2-y1),2));

    return distance;
}

/**
    Helper function for == operator overloading ; checks if two points are the same, false if different.

    @param two Point objects
    @return true if same; false if different
*/
bool operator==(Point A, Point B) {
    if(A.get_x_()== B.get_x_() && A.get_y_()== B.get_y_())
        return true;
    else
        return false;
}
