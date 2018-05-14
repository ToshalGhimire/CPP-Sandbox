#include "cell.h"
#include <QtGui>


Cell::Cell(QGraphicsItem *parent) : QGraphicsItem(parent)
{


}

/**
 * @brief This function randomizes the cell with 50-50 chance of being alive or dead
 *
 */
void Cell::RandomPopulation()
{
    if(rand() % 100 < 50){
        this->m_alive = true;
    }
    else{
        this->m_alive = false;
    }
}


/**
 * @brief change function changes the status of the cell. if alive it will die, if dead becomes alive
 */
void Cell::change()
{
    if(this->m_alive == true)
        this->m_alive = false;
    else
        this->m_alive = true;
}


/**
 * @brief this function flags if a cell has to change or not based on the total number of neighbors
 * @param sum of all its neighbors
 */
void Cell::CaseManager(int sum_neighbors)
{
    if(this->m_alive){
        //alive cell case

        //under/over population case
        if(sum_neighbors < 2 || sum_neighbors > 3){
            this->m_NeedsToChange = true;
        }else{
            this->m_NeedsToChange = false;

        }

    }
    else{
        //dead cell with exactly 3 alive members

        if(sum_neighbors == 3){
            this->m_NeedsToChange = true;
        }else{
            this->m_NeedsToChange = false;
        }
    }

}

/**
 * @brief a rect of size 20
 * @return a rect of size 20
 */
QRectF Cell::boundingRect() const{
    return QRectF(0,0,20,20);
}

QPainterPath Cell::shape() const
{
    QPainterPath path;
    path.addRect(QRectF(0,0,20,20));
    return path;

}

/**
 * @brief if left clicked it becomes alive, if right clicked dies
 * @param event
 */
void Cell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mousePressEvent(event);

    if(event->button()== Qt::LeftButton)
        this->m_alive = true;


    if(event->button()== Qt::RightButton)
        this->m_alive = false;

    //emit click();


}

/**
 * @brief function is actualy never used or needed
 * @param event
 */
void Cell::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    update();

        if(this->m_alive == true)
            this->m_alive = false;
        else
            this->m_alive = true;

}

/**
 * @brief paints the color of the cell based on its boolean values. alive or dead based on if flag is true or false. red if zombie flag is set
 * @param painter
 * @param option
 * @param widget
 */
void Cell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    update();

    if(this->m_alive){
        painter->setBrush(Qt::black);
    }else{
        painter->setBrush(Qt::white);
    }


    if(this->m_isZombie)
        painter->setBrush(Qt::red);

    painter->drawRect(0,0,20,20);

}
