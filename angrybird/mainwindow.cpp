#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qApp->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *){
    scene = new QGraphicsScene(0,0,width(),ui->graphicsView->height());
    ui->graphicsView->setScene(scene);

    world = new b2World(b2Vec2(0.0f, -9.8f));
    gameitem::setGlobalSize(QSizeF(27,17),this->size());
    ground *grd = new ground(16,1.5,32,2,QPixmap(":/new/bg/HALLOWEEN2011_GROUND.png").scaled(width(),height()/6.0),world,scene);
    ground *ss = new ground(4.0,5.525,0.5,1,QPixmap(),world,scene);
    redBird *red = new redBird(4.0f,10.0f,0.27f,&timer,QPixmap(":/new/bg/Angry_Bird_red_small.png").scaled(width()/14.0,height()/9.0),world,scene);
   // red->setLinearVelocity(b2Vec2(10,2));

    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    timer.start(100/6);
}


bool MainWindow::eventFilter(QObject *,QEvent *event){
    if(event->type() == QEvent::MouseButtonPress)
    {
        startPos=static_cast<QMouseEvent*>(event)->pos();
        std::cout << "Press !" << std::endl ;
    }
    if(event->type() == QEvent::MouseMove)
    {
        /* TODO : add your code here */
        //std::cout << "Move !" << std::endl ;
    }
    if(event->type() == QEvent::MouseButtonRelease)
    {
        std::cout << "Release !" << std::endl;
        endPos=static_cast<QMouseEvent*>(event)->pos();
        itemnow->setLinearVelocity(b2Vec2((startPos.x()-endPos.x())/40,(startPos.y()-endPos.y())/40));
    }
    return false;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    emit quitGame();
}

void MainWindow::tick()
{
    world->Step(1.0/60.0,6,2);
    scene->update();
}

void MainWindow::QUITSLOT()
{
    std::cout << "Quit Game Signal receive !" << std::endl ;
}
