#include <iostream>

#include "MyMath.h"


/*
    new ctor that makes sure that the points are in the right area, so p2 is infact top right, and p1 is in fact bottom left

*/
Rectangle::Rectangle(Point p1, Point p2){

    p1_ = (p1.x <= p2.x && p1.y <= p1.y) ? p1 : p2; 
    p2_ = (p1.x <= p2.x && p1.y <= p1.y) ? p2 : p1; 

}


/*
    expands the Rectangle

*/
void Rectangle::Expand(){
    p1_.x -=1;
    p1_.y -=1;

    p2_.x +=1;
    p2_.y +=1;

}
/*
    Shrinks the Rectangle

*/
void Rectangle::Shrink(){
    p1_.x +=1;
    p1_.y +=1;

    p2_.x -=1;
    p2_.y -=1;

}

/*
    calculates the area

*/
int Rectangle::CalculateArea(){
    int area = this->GetWidth() * this->GetHeight();
    return area;

}


/*
    returns the Width of rectangle

*/
int Rectangle::GetWidth(){
    int width = p2_.x - p1_.x;
    return width;
}


/*
    returns the Height of rectangle

*/
int Rectangle::GetHeight(){
    int height = p2_.y - p1_.y;
    return height;
}


/*
    see if two points in the rectangle are the same

*/
bool Rectangle::Overlaps(Rectangle& other){

     if(p1_.x == other.p1_.x && p1_.y == other.p1_.y){
        return true;
    }
     else if(p1_.x == other.p2_.x && p1_.y == other.p2_.y){
        return true;
    }
    else if(p2_.x == other.p1_.x && p2_.y == other.p1_.y){
        return true;
    }
    else if(p2_.x == other.p2_.x && p2_.y == other.p2_.y){
        return true;
    }
    else{
        return false;
    }

}
