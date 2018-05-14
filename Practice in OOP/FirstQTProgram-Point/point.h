#ifndef POINT_H
#define POINT_H

#include <QColor>
#include <QGraphicsItem>
#include <QObject>


class Point : public QObject ,public QGraphicsItem {
    Q_OBJECT

public:
    Point(QColor color, const int x, const int y);  // constructor

    int get_x() const { return x_; }  // inline member function
    int get_y() const { return y_; }  // inline member function

    double Distance() const;  // member function

    QRectF boundingRect() const override;
    QPainterPath shape() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;

    bool pressed;

    //Point *returnpoint(Point *a);

    static int FirstX_;
    static int FirstY_;
    static int SecondX_;
    static int SecondY_;
    QColor color_;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);// override;

public slots:


signals:
    void rightclicked(Point* temp);
    void leftclicked(Point* temp);

    void shiftclicked(Point* temp);

private:
  int x_;
  int y_;



  static const int width_ = 10;


  // if you declare the operator as a friend, then it isn't
  // part of the object
  // friend will let this method access the private fields
  friend bool operator==(const Point &first, const Point &other);
};  // class Point


#endif // POINT_H
