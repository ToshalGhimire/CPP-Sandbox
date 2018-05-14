#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <math.h>

using namespace std;



class Point
{ //start of class declaration

    public:
        Point();//defualt constructor witch sets private variables to 0
        Point(int,int); //constructor witch sets private variables to the arguments entered

        //getters and setters for private variables "x_" and "y_"
        int get_x_() { return x_; }
        void set_x_(int val) { x_ = val; }
        int get_y_() { return y_; }
        void set_y_(int val) { y_ = val; }

        double Distance(Point dist); //distance function; calculate the distance to another point object

    //private variables for x-coordinates and y-coordinates
    private:
        int x_;
        int y_;

};//end of class point

//operator overload function
bool operator==(Point, Point);


#endif // POINT_H
