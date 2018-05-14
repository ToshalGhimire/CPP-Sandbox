#include "ad7point.h"
#include "ui_ad7point.h"
#include <QMessageBox>


/**
 * @brief helper function makes the x and y axis as well as the box surrounding it
 * @param scene
 */
void makegraph(QGraphicsScene * scene){

    QPen blackpen(Qt::black);

    //making line coords for the rectangle
    QLineF TopLine(scene->sceneRect().topLeft(),scene->sceneRect().topRight());
    QLineF Leftline(scene->sceneRect().topLeft(),scene->sceneRect().bottomLeft());
    QLineF Rightline(scene->sceneRect().topRight(),scene->sceneRect().bottomRight());
    QLineF Bottomline(scene->sceneRect().bottomLeft(),scene->sceneRect().bottomRight());


    blackpen.setWidth(4);

    //Making the box surrounding the rectangle
    scene->addLine(TopLine,blackpen);
    scene->addLine(Bottomline,blackpen);
    scene->addLine(Rightline,blackpen);
    scene->addLine(Leftline,blackpen);

    //Making the x and y axis
    scene->addLine(-200,0,200,0);
    scene->addLine(0,-200,0,200);



};

/**
 * @brief ctor makes the scene and then makes the graph line
 * @param parent
 */
AD7Point::AD7Point(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AD7Point)
{
    ui->setupUi(this);
    QApplication::setStyle("fusion");

    scene = new QGraphicsScene();


    ui->graphicsView->setScene(scene);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(-200,-200,400,400);

    //connect(QPushButton,SIGNAL(Qt::EnterKeyDefault),on_plotButton_clicked(),SLOT());

    makegraph(scene);


}

AD7Point::~AD7Point()
{
    delete ui;
}


/**
 * @brief when button is clicked it gets information from the LineEdits and makes a new point object and places it in the scene
 */
void AD7Point::on_plotButton_clicked()
{
    QBrush redBrush(Qt::red);
    QPen blackpen(Qt::black);

    //if else statments to make sure both LineEdits are filled with numbers
    if(ui->yLineEdit->text() == nullptr && ui->xLineEdit->text() == nullptr ){
        QMessageBox::information(this,"Missing","Missing both 'X' and 'Y' points",QMessageBox::Ok);
        return;
    }
    else if(ui->yLineEdit->text() == nullptr ){
        QMessageBox::information(this,"Missing Y","Please Enter a 'Y' value",QMessageBox::Ok);
        return;
    }
    else if(ui->xLineEdit->text() == nullptr){
       QMessageBox::information(this,"Missing X","Please Enter a 'X' value!",QMessageBox::Ok);
       return;
    }

    //geting info from LineEdit
    int xval = ui->xLineEdit->text().toInt();
    int yval = ui->yLineEdit->text().toInt();


    //makes a new temp object & adds it to the QList
    Point * temp = new Point(QColor(255, 0, 0, 127), xval - 5,-yval - 5);
    pointList.append(temp);
    temp->setFlag(QGraphicsItem::ItemIsSelectable);

    connect(temp,SIGNAL(rightclicked(Point*)),this,SLOT(Makeline(Point*))); // connecting the right clicks inorder to make lines
    connect(temp,SIGNAL(shiftclicked(Point*)),this,SLOT(Mark(Point*)));

    scene->addItem(temp);
}




/**
 * @brief changes label to the value of the distance of the two points that you shift clicked

 */
QGraphicsLineItem *lineItem;//stores the line distance to display
void AD7Point::on_Distance_clicked()
{
    if(lineItem)
        delete lineItem;
    //Random temp function, used to calcuate distance between the two shift clicked item
    Point * temp = new Point(QColor(255, 0, 0, 127), 0 - 5,-0 - 5);

    ui->label->setText(QString::fromUtf8(std::to_string(temp->Distance()).c_str()));

    //hides point1 and point2 label after 5 seconds
//        QTimer::singleShot(5000,[&](){ui->point1->setText("");});
//        QTimer::singleShot(5000,[&](){ui->point2->setText("");});

    //creates a line to see the distance
    QPen redpen(Qt::red);;
    redpen.setWidth(5);
    lineItem = scene->addLine(-210,0,-210,-temp->Distance(),redpen);











}

bool DeletePressed = false; //global for deletebutton clicked
/**
 * @brief when Delete Point button is pressed it hides all other signals and changes cursor to a cross, clicking on a point deletes it
 */
void AD7Point::on_Delete_clicked()
{

    if(!DeletePressed){
        //Delete button pressed
        DeletePressed = true;

        //connects all the left clicked signals to the DeletePoint method
        for(int i = 0; i < pointList.size();i++){

            connect(pointList[i],SIGNAL(leftclicked(Point*)),this,SLOT(DeletePoint(Point*)));

        }

        QApplication::setOverrideCursor(Qt::CrossCursor);
        ui->Delete->setText("Exit Delete");

        //hides all other buttons so user can only delete
        ui->plotButton->hide();
        ui->xLineEdit->hide();
        ui->yLineEdit->hide();
        ui->xLabel->hide();
        ui->yLabel->hide();
        ui->Distance->hide();
        ui->label->hide();
        ui->distancecalc->hide();
        ui->point1->hide();
        ui->point2->hide();
        ui->line_2->hide();
    }
    else{
        //Delete button pressed again
        DeletePressed = false;

        //disconnects all the signals
        for(int j = 0; j < pointList.size();j++){

            disconnect(pointList[j],SIGNAL(leftclicked(Point*)),this,SLOT(DeletePoint(Point*)));

        }

        QApplication::setOverrideCursor(Qt::ArrowCursor);
        ui->Delete->setText("Delete Point");

        //shows the buttons again after delete point is pressed again
        ui->plotButton->show();
        ui->xLineEdit->show();
        ui->yLineEdit->show();
        ui->xLabel->show();
        ui->yLabel->show();
        ui->Distance->show();
        ui->label->show();
        ui->distancecalc->show();
        ui->point1->show();
        ui->point2->show();
        ui->line_2->show();
    }


}


int prevX;
int prevY;
bool firstclick = true;
/**
 * @brief slot that makes the line after the right clicked signals is emmited fromt he point class
 *  sets the global variables above to some value at the start, then the second right click adds the line to the scene
 * @param Point* object
 */
void AD7Point::Makeline(Point * a){

     QPen blackpen(Qt::black);
     blackpen.setWidth(4);

     //first point so just store the x and y coords then do nothing
     if(firstclick){
         prevX = a->get_x();
         prevY = a->get_y();
         firstclick = false;
         return;
     }

     //add line to the scene (+5 offset) then sets prev globals to new value
    scene->addLine(prevX+5,prevY+5,a->get_x()+5,a->get_y()+5,blackpen);
    prevX = a->get_x();
    prevY = a->get_y();

    ui->statusBar->showMessage("Added new line!",1500);

}
/**
 * @brief delets a point from the Qlist then deletes the object
 * @param Point* Object
 */
void AD7Point::DeletePoint(Point* a){

    pointList.removeOne(a);
    delete a;

    if(pointList.size() == 0){
        scene->clear();
        makegraph(scene);
        firstclick = true;
    }
}


bool MarkPressed = false;
void AD7Point::Mark(Point* a){
    std::string temp = "";
    QString str;



    if(!MarkPressed){
        MarkPressed = true;

        temp += "Point 1: ( " + std::to_string(a->get_x()+5)  + " , "+ std::to_string(-a->get_y()+5) + " )";
        ui->point1->setText(QString::fromUtf8(temp.c_str()));
    }else{
        MarkPressed = false;

        temp += "Point 2: ( " + std::to_string(a->get_x()+5) +" , "+ std::to_string(-a->get_y()+5) + " )";
        ui->point2->setText(QString::fromUtf8(temp.c_str()));

    }



    qDebug() << "Item at: x = " << a->get_x()+5 << " y = " <<- a->get_y()+5 << " - Was Shiftclicked";

}

void AD7Point::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Return)
        on_plotButton_clicked();
}
