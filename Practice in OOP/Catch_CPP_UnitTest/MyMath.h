#ifndef _MYMATH_H_
#define _MYMATH_H_



// Example function for the beginning tests
unsigned int Factorial( unsigned int number );



struct Point {
  int x;
  int y;
};


class Rectangle {
public:
  Rectangle(Point p1, Point p2); //ctor sets arguments to wrong points

  int GetWidth();
  int GetHeight();


  // returns true iff this rectangle shares any points with the other one
  bool Overlaps(Rectangle& other);

  // returns the area of this rectangle
  int CalculateArea();

  // moves the bottom left coordinate down one and to the left one
  // moves the upper right coordinate up one and to the right one
  void Expand();

  // moves the bottom left coordinate up one and to the right one
  // moves the upper right coordinate down one and to the left one
  void Shrink();

private:
  Point p1_; // bottom left corner
  Point p2_; // upper right corner
};


#endif // _MYMATH_H_
