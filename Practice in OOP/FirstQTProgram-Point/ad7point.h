#ifndef AD7POINT_H
#define AD7POINT_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QTimer>

#include <vector>
#include <QList>
#include <iostream>

#include "point.h"


namespace Ui {
class AD7Point;
class Point;
}


class AD7Point : public QMainWindow
{
    Q_OBJECT

public:
    explicit AD7Point(QWidget *parent = 0);
    ~AD7Point();


public slots:
    void Makeline(Point *a);
    void DeletePoint(Point *a);
    void Mark(Point *a);
protected:
    //void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void keyPressEvent(QKeyEvent* event);
private slots:
    void on_plotButton_clicked(); //plots the numbers from LineEdit
    void on_Distance_clicked(); // calcuates distance of two shift clicked points, 0 if none was clicked
    void on_Delete_clicked(); //delet points

private:
    Ui::AD7Point *ui;
    QGraphicsScene * scene;

    QList<Point*> pointList; //QList for storing all my point items

};

#endif // AD7POINT_H
