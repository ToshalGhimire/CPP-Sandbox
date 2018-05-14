#include <cmath>
#include <iostream>
#include <QtWidgets>

#include "point.h"

// starter code for AD7/PE 10
//int twopoints = 0;

/**
 * @brief  Creates a new Point object with coordinates x and y
 * @param color
 * @param x
 * @param y
 */
Point::Point(QColor color, const int x, const int y) {
  this->color_ = color;
  x_ = x;
  y_ = y;
  pressed = false;
}

QRectF Point::boundingRect() const
{
    return QRectF(x_, y_, width_, width_);
}

QPainterPath Point::shape() const
{
    QPainterPath path;
    path.addEllipse(x_, y_, width_, width_);
    return path;
}

bool shiftclick = false;

void Point::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    QRectF a = boundingRect();
    QBrush b(Qt::blue);



    if(!pressed){
    //if button is pressed it changes brush color to red

     b.setColor(Qt::red);


    }else{
        //if button is pressed it changes brush color to red

     b.setColor(Qt::blue);



    }


    //changes color of ellipse (our point)
    painter->fillRect(a,b);
    painter->drawRect(QRect(this->x_, this->y_, this->width_, this->width_));

}

bool t = false;//bool for shiftcliked point
void Point::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    update();

    //this if/else is used to change the color from blue to red
    if(!pressed){
        pressed = true;
    }else{
        pressed = false;
    }

    QGraphicsItem::mousePressEvent(event);

    update();

    //used to calcuate distance from two point items
    if(event->button() == Qt::LeftButton && !t){
        t = true;
       if(event->modifiers() == Qt::ShiftModifier ){
            shiftclick = true;
            emit shiftclicked(this);

            FirstX_ = this->x_;
            FirstY_ = this->y_;

        }
    } else if(event->button() == Qt::LeftButton && t){
        t = false;
        if(event->modifiers() == Qt::ShiftModifier ){
            shiftclick = true;

            emit shiftclicked(this);

            SecondX_ = this->x_;
            SecondY_ = this->y_;

        }
    }

    update();


    //emits when right mouse button is pressed
    if(event->button() == Qt::RightButton){
        emit rightclicked(this);
    }

    //emits when left mouse button is pressed
    if(event->button() == Qt::LeftButton){
        emit leftclicked(this);
    }

}



/**
  Calculates the distance between this point and another Point. changed it so it just uses the static variables
*/
double Point::Distance() const {
  double distance = (FirstX_ - SecondX_) * (FirstX_ - SecondX_);
  distance += (FirstY_ - SecondY_) * (FirstY_ - SecondY_);
  return sqrt(distance);
}


/**
  Makes it so the == operator will have the behavior that you
  expect when comparing points.
  You can overload pretty much any operator in c++
  @param first Point left hand side of the expression
  @param other Point right hand side of the expression
*/
bool operator==(const Point &first, const Point &other) {
  return first.x_ == other.x_ && first.y_ == other.y_;
}


