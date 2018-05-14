#ifndef CELL_H
#define CELL_H
#include <stdlib.h>     /* srand, rand */
#include <time.h>

#include <QColor>
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsSceneMouseEvent>

#include <QDebug>

class Cell : public QGraphicsItem
{

public:
     Cell(QGraphicsItem *parent = nullptr);

     void RandomPopulation();
     void CaseManager(int Case);
     void change();

     bool getAlive(){return m_alive;}
     void setAlive(bool a){m_alive = a;}
     void MakeZombie(){this->m_isZombie = true;}
     void MakeNormal(){this->m_isZombie = false;}




     bool m_NeedsToChange = false;
protected:
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    QRectF boundingRect() const;

    QPainterPath shape() const;


    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

private:
    bool m_alive;
    int m_neighbors;

    bool m_isZombie = false;
};

#endif // CELL_H
