#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <time.h>
#include <stdio.h>

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QVector>
#include <QTimer>
#include <QKeyEvent>
#include <QMessageBox>

#include "cell.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void makeboard(int col,int row);
    int AliveCounter();
    void MakeDice();
    void MakeGraph();

protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_Restart_clicked();
    void on_stepButton_clicked();
    void on_Play_clicked();
    void on_stopButton_clicked();
    void on_RollDice_clicked();
    void on_zombieButton_clicked();

    void on_horizontalSlider_sliderMoved(int position);
    void on_horizontalSlider_valueChanged(int value);



private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QGraphicsScene * m_scene;
    QGraphicsScene * m_scene_graph;
    QVector< QVector<Cell*> > board ;

    int m_col;
    int m_row;

    //zombie information fields
    bool isSpawned = false;
    int m_ZIndexI;
    int m_ZIndexJ;

    int turnCount = 0;

    //graph info
    int m_percent;
    int offset = 20;

    QVector<QGraphicsRectItem*> graph;


};

#endif // MAINWINDOW_H
