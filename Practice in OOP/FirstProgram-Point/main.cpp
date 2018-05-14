/**
Toshal Ghimire
Programming Exercise 1 - Points
This program has a class that defines a 2d point.
*/

#include <iostream>
#include "point.h"

using namespace std;

int main()
{

    //creating two Point object,defined a 3-4-5 triangle, distance function should return 5
    Point A(0,3);
    Point B(4,0);

    Point C(4,0);


    //outputs:
    cout.setf(ios::boolalpha);//returns boolean not binary
    cout<<"Point A = (0,3) \nPoint B = (4,0) \nPoint C = (4,0)\n\n";

    cout<<"------- Helper function check -------\n";
    //A.Distance(B) will return the distance from a to b (5 since 3-4-5).
    cout<<"Distance between point A and B is "<<A.Distance(B)<<endl;
    cout<<"Distance between point B and C is "<<B.Distance(C)<<endl;

    cout<<"\n------- Helper function check -------";
    //checking if == operator compares x and y values; will return 0 if different, 1 if same
    cout<<"\nAre C and A points the same?\nResult: "<<(C == A)<<endl;
    cout<<"\nAre C and B points the same?\nResult: "<<(C == B)<<endl;

    return 0;
}
