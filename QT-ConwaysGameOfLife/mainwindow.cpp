#include "mainwindow.h"
#include "ui_mainwindow.h"


/**
 * @brief constructor for the mainwindow, takes care of alot of small things, such as asigning scene, making board, initilizing timer, tooltips and slider adjustmnets
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    m_scene = new QGraphicsScene();
    m_scene_graph = new QGraphicsScene();


    ui->graphicsView->setScene(m_scene);
    ui->graphicsView_2->setScene(m_scene_graph);
    //m_scene->setBackgroundBrush(Qt::blue);

    //m_scene->setSceneRect(exactRect);
    //QRectF exactRect(0,0, -400, -200);


    //function that makes the board
    this->makeboard(30,20);

    //timer and sliders
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(on_stepButton_clicked()));


    //slider range
    ui->horizontalSlider->setRange(1, 15);
    ui->horizontalSlider->setSingleStep(5);

    //tool tip information
    ui->RollDice->setToolTip("Click to roll a dice.");
    ui->Restart->setToolTip("Click to Restart the game.");
    ui->Play->setToolTip("Click to automaticly step.\nAdjust the slider for the speed.");
    ui->stepButton->setToolTip("Click to advance one turn.");

    m_scene_graph->addRect(0,0,600,100);

    QGraphicsRectItem * start = new QGraphicsRectItem(0,100-m_percent,20,m_percent);
    m_scene_graph->addItem(start);
    graph.push_back(start);

}




MainWindow::~MainWindow()
{
    delete ui;
}


/**
 * @brief makes the board for the Conway’s Game of Life. saves the row and col number in class field and stores all the cell into a 2d vector for future access.
 * @param col
 * @param row
 */
void MainWindow::makeboard(int col,int row)
{
    srand(time(0));

    m_col = col;
    m_row = row;
    board.clear();
    int posCountI = 0;
    int posCountJ = 0;

    for(int i = 0; i < m_col; i++){
        QVector<Cell*> tempvector;
        for(int j = 0; j < m_row; j++){

            Cell * temp = new Cell();
            temp->RandomPopulation();
            temp->setPos(posCountI,posCountJ);
            this->m_scene->addItem(temp);

            tempvector.push_back(temp); //filling rows

            posCountJ -=20;
        }
        board.push_back(tempvector); // filling columns
        posCountJ = 0;
        posCountI -=20;
    }
    AliveCounter();
}


/**
 * @brief counts the toal number of cells in the board and then sets the ui lable to display it
 * @return
 */
int MainWindow::AliveCounter()
{
    int counter = 0;
    for(int i = 0; i < m_col; i++){
        for(int j = 0; j < m_row; j++){

            if(board.at(i).at(j)->getAlive())
                counter++;

            }
        }


    double total = m_col * m_row;
    double percent = counter / total;
    double scale = 0.01;  // setting decimel places
    percent = (int)(percent / scale) * scale;

    m_percent = percent*100;

    QString str = "Alive Cells: ";
    str += QVariant(counter).toString();
    str += " (";
    str += QVariant(percent*100).toString();
    str += "%)";

    ui->AliveCounter->setText(str);

    return counter;
}

/**
 * @brief modhelper is a function that does the module operation needed to connect all four sides of the board with one another since c++ doesnt do module with negative numbers
 * @param a
 * @param b
 * @return a % b
 */
int modhelper(int a, int b){
    return(a%b+b)%b;
}



/**
 * @brief this function coutns the neighobors of each cell.
 * that number is passed into the CaseManager and that function determines if the cell needs to change or not.
 * the second set of forloops changes the cell if CaseManager sets the m_NeedsToChange flag to true
 *
 * This is the main function of the game. it also increments turncount and displays it
 *
 *
 */
void MainWindow::on_stepButton_clicked()
{

    //turn label update
    turnCount++;
    QString str = "Turn: ";
    str += QVariant(turnCount).toString();
    ui->turnLable->setText(str);

    int Acounter = 0;

    //counting forloops
    for(int i = 0; i < m_col; i++){
        for(int j = 0; j < m_row; j++){

            if(board.at(modhelper(i-1,m_col)).at(modhelper(j-1,m_row))->getAlive() == true){
                //bottom right
                Acounter++;
            }
            if(board.at(modhelper(i-1, m_col)).at(modhelper(j,m_row))->getAlive() == true){
                //bottom
                Acounter++;
            }
            if(board.at(modhelper(i-1,m_col)).at(modhelper(j+1,m_row))->getAlive() == true){
                //bottom left
                Acounter++;
            }
            if(board.at(modhelper(i,m_col)).at(modhelper(j-1,m_row))->getAlive() == true){
                //right
                Acounter++;
            }
            if(board.at(modhelper(i,m_col)).at(modhelper(j+1,m_row))->getAlive() == true){
                //left
                Acounter++;
            }
            if(board.at(modhelper(i+1,m_col)).at(modhelper(j-1,m_row))->getAlive() == true){
                //top right
                Acounter++;
            }
            if(board.at(modhelper(i+1,m_col)).at(modhelper(j,m_row))->getAlive() == true){
                //up
                Acounter++;
            }

            if(board.at(modhelper(i+1,m_col)).at(modhelper(j+1,m_row))->getAlive() == true){
                //top left
                Acounter++;
            }

            board.at(i).at(j)->CaseManager(Acounter);

            Acounter = 0;


        }

    }

    //changing forloop
    for(int i = 0; i < m_col; i++){
        for(int j = 0; j < m_row; j++){
            if(board.at(i).at(j)->m_NeedsToChange == true){
                board.at(i).at(j)->change();
            }
        }
    }

    AliveCounter();
    MakeGraph();
}



bool isPlaying = false;
/**
 * @brief button starts the timer that automaticly hits the step button based on the slider value
 */
void MainWindow::on_Play_clicked()
{

   isPlaying = true;

   int time = ui->horizontalSlider->value();
   timer->start(1000/time);


}
/**
 * @brief storps the timer
 */
void MainWindow::on_stopButton_clicked()
{
    isPlaying = false;

    timer->stop();
}


/**
 * @brief slider that controls the speed of the step function using Qtimer
 * @param position
 */
void MainWindow::on_horizontalSlider_sliderMoved(int position)
{

    QString str = "STEPS PER SECOND: ";

    str += QVariant(position).toString();

    ui->sliderinfo->setText(str);

    if(isPlaying){
        //if the game is already playing while you update the slider, the speed automaticly adjusts
        on_Play_clicked();
    }

}

/**
 * @brief slider that controls the speed of the step function using Qtimer
 * @param position
 */
void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    QString str = "STEPS PER SECOND: ";

    str += QVariant(value).toString();

    ui->sliderinfo->setText(str);

    if(isPlaying){
        on_Play_clicked();

    }
}

/**
 * @brief button that rolls the dice, first clears the 13 x 13 space to put the board in it, then calls MakeDice function
 */
void MainWindow::on_RollDice_clicked()
{
    //clear some area of the board to place dice in
    for(int i = 0; i < 13; i++){
        for(int j = 0; j < 13; j++){

            board.at(i).at(j)->setAlive(false);
        }
    }

    MakeDice();
}

/**
 * @brief using C++ random function it displays the dice based on the number rolled using a switch statment and carefully setting certian cells to true
 */
void MainWindow::MakeDice(){

    srand(time(0));

    //forloops for making the sides of the dice
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){

            if(j == 0 || j ==11)
                board.at(i).at(j)->setAlive(true);

            if(i == 0 || i ==11)
                board.at(i).at(j)->setAlive(true);


            }
        }

    board.at(0).at(0)->setAlive(false);
    board.at(0).at(11)->setAlive(false);
    board.at(11).at(0)->setAlive(false);
    board.at(11).at(11)->setAlive(false);

    //rolling and making status string
    int roll = (rand() % 6) + 1;
    QString str = "You rolled a ";
    str += QVariant(roll).toString();
    ui->statusBar->showMessage(str,1000);


    //roll display using switch
    switch (roll) {
    case 1:
        board.at(4).at(4)->setAlive(true);
        board.at(4).at(5)->setAlive(true);
        board.at(4).at(6)->setAlive(true);
        board.at(4).at(7)->setAlive(true);

        board.at(5).at(4)->setAlive(true);
        board.at(5).at(5)->setAlive(true);
        board.at(5).at(6)->setAlive(true);
        board.at(5).at(7)->setAlive(true);

        board.at(6).at(4)->setAlive(true);
        board.at(6).at(5)->setAlive(true);
        board.at(6).at(6)->setAlive(true);
        board.at(6).at(7)->setAlive(true);

        board.at(7).at(4)->setAlive(true);
        board.at(7).at(5)->setAlive(true);
        board.at(7).at(6)->setAlive(true);
        board.at(7).at(7)->setAlive(true);

        break;
    case 2:
        board.at(2).at(2)->setAlive(true);
        board.at(2).at(3)->setAlive(true);
        board.at(2).at(4)->setAlive(true);
        board.at(3).at(2)->setAlive(true);
        board.at(3).at(3)->setAlive(true);
        board.at(3).at(4)->setAlive(true);
        board.at(4).at(2)->setAlive(true);
        board.at(4).at(3)->setAlive(true);
        board.at(4).at(4)->setAlive(true);

        board.at(7).at(7)->setAlive(true);
        board.at(7).at(8)->setAlive(true);
        board.at(7).at(9)->setAlive(true);
        board.at(8).at(7)->setAlive(true);
        board.at(8).at(8)->setAlive(true);
        board.at(8).at(9)->setAlive(true);
        board.at(9).at(7)->setAlive(true);
        board.at(9).at(8)->setAlive(true);
        board.at(9).at(9)->setAlive(true);

        break;
    case 3:
        board.at(2).at(2)->setAlive(true);
        board.at(2).at(3)->setAlive(true);
        board.at(3).at(2)->setAlive(true);
        board.at(3).at(3)->setAlive(true);

        board.at(5).at(5)->setAlive(true);
        board.at(5).at(6)->setAlive(true);
        board.at(6).at(5)->setAlive(true);
        board.at(6).at(6)->setAlive(true);

        board.at(8).at(8)->setAlive(true);
        board.at(8).at(9)->setAlive(true);
        board.at(9).at(8)->setAlive(true);
        board.at(9).at(9)->setAlive(true);

        break;
    case 4:
        board.at(2).at(2)->setAlive(true);
        board.at(2).at(3)->setAlive(true);
        board.at(2).at(4)->setAlive(true);
        board.at(3).at(2)->setAlive(true);
        board.at(3).at(3)->setAlive(true);
        board.at(3).at(4)->setAlive(true);
        board.at(4).at(2)->setAlive(true);
        board.at(4).at(3)->setAlive(true);
        board.at(4).at(4)->setAlive(true);

        board.at(7).at(2)->setAlive(true);
        board.at(7).at(3)->setAlive(true);
        board.at(7).at(4)->setAlive(true);
        board.at(8).at(2)->setAlive(true);
        board.at(8).at(3)->setAlive(true);
        board.at(8).at(4)->setAlive(true);
        board.at(9).at(2)->setAlive(true);
        board.at(9).at(3)->setAlive(true);
        board.at(9).at(4)->setAlive(true);

        board.at(2).at(7)->setAlive(true);
        board.at(2).at(8)->setAlive(true);
        board.at(2).at(9)->setAlive(true);
        board.at(3).at(7)->setAlive(true);
        board.at(3).at(8)->setAlive(true);
        board.at(3).at(9)->setAlive(true);
        board.at(4).at(7)->setAlive(true);
        board.at(4).at(8)->setAlive(true);
        board.at(4).at(9)->setAlive(true);

        board.at(7).at(7)->setAlive(true);
        board.at(7).at(8)->setAlive(true);
        board.at(7).at(9)->setAlive(true);
        board.at(8).at(7)->setAlive(true);
        board.at(8).at(8)->setAlive(true);
        board.at(8).at(9)->setAlive(true);
        board.at(9).at(7)->setAlive(true);
        board.at(9).at(8)->setAlive(true);
        board.at(9).at(9)->setAlive(true);

        break;
    case 5:
        board.at(2).at(2)->setAlive(true);
        board.at(2).at(3)->setAlive(true);
        board.at(3).at(2)->setAlive(true);
        board.at(3).at(3)->setAlive(true);

        board.at(2).at(8)->setAlive(true);
        board.at(2).at(9)->setAlive(true);
        board.at(3).at(8)->setAlive(true);
        board.at(3).at(9)->setAlive(true);

        board.at(5).at(5)->setAlive(true);
        board.at(5).at(6)->setAlive(true);
        board.at(6).at(5)->setAlive(true);
        board.at(6).at(6)->setAlive(true);

        board.at(8).at(8)->setAlive(true);
        board.at(8).at(9)->setAlive(true);
        board.at(9).at(8)->setAlive(true);
        board.at(9).at(9)->setAlive(true);

        board.at(8).at(2)->setAlive(true);
        board.at(9).at(2)->setAlive(true);
        board.at(8).at(3)->setAlive(true);
        board.at(9).at(3)->setAlive(true);


        break;
    case 6:
        board.at(3).at(2)->setAlive(true);
        board.at(4).at(2)->setAlive(true);
        board.at(3).at(3)->setAlive(true);
        board.at(4).at(3)->setAlive(true);

        board.at(7).at(2)->setAlive(true);
        board.at(8).at(2)->setAlive(true);
        board.at(7).at(3)->setAlive(true);
        board.at(8).at(3)->setAlive(true);

        board.at(3).at(5)->setAlive(true);
        board.at(4).at(5)->setAlive(true);
        board.at(3).at(6)->setAlive(true);
        board.at(4).at(6)->setAlive(true);

        board.at(7).at(5)->setAlive(true);
        board.at(8).at(5)->setAlive(true);
        board.at(7).at(6)->setAlive(true);
        board.at(8).at(6)->setAlive(true);

        board.at(3).at(8)->setAlive(true);
        board.at(4).at(8)->setAlive(true);
        board.at(3).at(9)->setAlive(true);
        board.at(4).at(9)->setAlive(true);

        board.at(7).at(8)->setAlive(true);
        board.at(8).at(8)->setAlive(true);
        board.at(7).at(9)->setAlive(true);
        board.at(8).at(9)->setAlive(true);

        break;
    default:
        break;
    }

}



/**
 * @brief function that make the graph. if graph is out of index then it shifts everything by 20.
 *
 */
void MainWindow::MakeGraph()
{
    QGraphicsRectItem * temp = new QGraphicsRectItem(offset,100-m_percent,20,m_percent);
    //QGraphicsItem * temp1 = new
    m_scene_graph->addItem(temp);

    graph.push_back(temp);

    if(offset < 600){
        //first part of graph before it fills up, second part in else

        offset += 20;
    }else{

       //removing from scene, and vector
       delete graph.first();
       graph.removeFirst();

       //shift everything to the left by 20
       for(auto i: graph){
            i->setX(i->x()-20);
        }

    }

}


/**
 * @brief function that controls the zombie if it has Spawned. uses the modhelper function to connect the sides of the board. first if statment has details rest are the same
 * @param event
 */
void MainWindow::keyPressEvent(QKeyEvent *event)
{

    if(isSpawned){
       //main if to check if zombie has already spawned or not

        Cell * zombie = board.at(m_ZIndexI).at(m_ZIndexJ);//saves curent zombie cell

        if(event->text() == "w" || event->key()==Qt::Key_Up){
            //up case

            if(!board.at(modhelper(m_ZIndexI, m_col)).at(modhelper(m_ZIndexJ+1, m_row))->getAlive()){
                //runs if cell above is dead
                zombie->MakeNormal(); //makes current zombie into dead cell
                zombie = board.at(modhelper(m_ZIndexI, m_col)).at(modhelper(m_ZIndexJ+1, m_row)); //updates zombie to new cell above
                m_ZIndexJ = modhelper(m_ZIndexJ+1, m_row);//updates zombie index variable
                zombie->MakeZombie();//makes that cell into the new zombie
            }
        }
        if(event->text() == "s" || event->key()==Qt::Key_Down){
            //down case

            if(!board.at(modhelper(m_ZIndexI, m_col)).at(modhelper(m_ZIndexJ-1, m_row))->getAlive()){
                zombie->MakeNormal();
                zombie = board.at(modhelper(m_ZIndexI, m_col)).at(modhelper(m_ZIndexJ-1, m_row));
                m_ZIndexJ = modhelper(m_ZIndexJ-1, m_row);
                zombie->MakeZombie();
            }
        }
        if(event->text() == "d" || event->key()==Qt::Key_Right){
            //Right case

            if(!board.at(modhelper(m_ZIndexI-1, m_col)).at(modhelper(m_ZIndexJ, m_row))->getAlive()){
                zombie->MakeNormal();
                zombie = board.at(modhelper(m_ZIndexI-1, m_col)).at(modhelper(m_ZIndexJ, m_row));
                m_ZIndexI = modhelper(m_ZIndexI-1, m_col);
                zombie->MakeZombie();
            }
        }
        if(event->text() == "a" || event->key()==Qt::Key_Left){
            //Left case

            if(!board.at(modhelper(m_ZIndexI+1, m_col)).at(modhelper(m_ZIndexJ, m_row))->getAlive()){
                zombie->MakeNormal();
                zombie = board.at(modhelper(m_ZIndexI+1, m_col)).at(modhelper(m_ZIndexJ, m_row));
                m_ZIndexI = modhelper(m_ZIndexI+1, m_col);
                zombie->MakeZombie();
            }
        }

    }else{
        qDebug() << "Zombie hasnt spawned";
    }


}


/**
 * @brief firnds the first dead cell and makes it a zombie and records its index
 */
void MainWindow::on_zombieButton_clicked()
{

    if(!isSpawned){
        QMessageBox::information(this,"Zombie","Zombie has Spawned!\nUse the \'w\' ,\'a\' ,\'s\' ,\'d\' keys to move the Zombie");
        for(int i = 0; i < m_col; i++){
            for(int j = 0; j < m_row; j++){
                if(board.at(i).at(j)->getAlive() == false){
                    board.at(i).at(j)->MakeZombie();
                    m_ZIndexI = i;
                    m_ZIndexJ = j;
                    break;
                }
            }
            break;
         }
        isSpawned = true;
    }else{
        ui->statusBar->showMessage("Zombie already spawned");
    }
}


/**
 * @brief resets the board, turncout, and zombieSpawned flag, then makes a new board
 */
void MainWindow::on_Restart_clicked()
{
    turnCount = 0;
    isSpawned = false;

    m_scene_graph->clear();
    m_scene_graph->addRect(0,0,600,100);
    m_scene_graph->addRect(0,100-m_percent,20,m_percent);
    offset = 20;

    ui->turnLable->setText("Turn: 0 ");

    this->makeboard(m_col,m_row);
}

