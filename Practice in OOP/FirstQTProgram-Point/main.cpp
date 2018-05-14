/*
 * 
 * Toshal Ghimire
 * 
 *
 * Distance: calcuated using static variables, indicaters are in lablewidget, distance shows ont he left side in red
 *
 * Addline: used signals to calcuate it, and saved previous values in global var
 *
 * Delete point: used signals and global bool vars to delete it
 *
 *
 *
 * */

#include "ad7point.h"
#include <QApplication>




int Point::FirstX_ = 0;
int Point::FirstY_ = 0;
int Point::SecondX_ = 0;
int Point::SecondY_ = 0;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AD7Point w;

    w.setWindowTitle("Point application");
    w.show();

    return a.exec();
}
