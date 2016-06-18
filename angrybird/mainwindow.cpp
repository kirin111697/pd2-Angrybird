#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    canpress(false)
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
    gameitem::setGlobalSize(QSizeF(32,21.25),this->size());
    ground *grd = new ground(16,1.5,32,2,QPixmap(":/new/bg/HALLOWEEN2011_GROUND.png").scaled(width(),height()/6.0),world,scene);
    barrier *bar1 = new barrier(20,5,20.0/32.0,83.0/32.0,&timer,QPixmap(":/new/bg/BLOCK_ROCK_1_4_2.png"),world,scene);
    barrier *bar2 = new barrier(17,5,20.0/32.0,83.0/32.0,&timer,QPixmap(":/new/bg/BLOCK_ROCK_1_4_2.png"),world,scene);
    // red->setLinearVelocity(b2Vec2(10,2));

    barrier *piggy = new barrier(19.0f,4.0f,1.2f,&timer,QPixmap(":/new/bg/pigy-angry-birds.png"),world,scene);

    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(&checkBound,SIGNAL(timeout()),this,SLOT(checkBird()));
    connect(this,SIGNAL(birdStop()),this,SLOT(killBird()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    timer.start(100/6);
}

void MainWindow::startGame(){//要加其他隻時記得處理彈弓的地板，玩玩第一隻之後會被刪掉
    ground *ss = new ground(4.4,4.5,0.1,1,QPixmap(),world,scene);
    grdTemp = ss;
    addBird();
}

void MainWindow::addBird(){
    redBird *red = new redBird(4.4f,10.0f,0.78f,&timer,QPixmap(":/new/bg/Angry_Bird_red_small.png"),world,scene);
    itemnow=red;
    canpress=true;
}

void MainWindow::killBird(){
    delete itemnow;
    std::cout << "KILL BIRD !" << std::endl ;
    startGame();
}

void MainWindow::checkBird(){
    b2Vec2 birdPos=itemnow->getPos();
    b2Vec2 birdVelo=itemnow->getVelocity();
    std::cout << "x is " << birdPos.x << std::endl ;
    if (birdPos.x > 32 || birdPos.x < 0){
        emit birdStop();
        std::cout << "out of window !" << std::endl ;
        checkBound.stop();
    }
    std::cout << "y is " << birdPos.y << std::endl ;
    if (birdPos.y < 3.3){
        if (birdVelo.x < 0.00000000001 && birdVelo.y < 0.000000000001){
            emit birdStop();
            std::cout << "too slow !" << std::endl ;
            checkBound.stop();
        }
    }
}

bool MainWindow::eventFilter(QObject *,QEvent *event){
    if(canpress==false){
        return false;
    }
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
        delete grdTemp;
        canpress=false;
        itemnow->setLinearVelocity(b2Vec2((startPos.x()-endPos.x())/5,(endPos.y()-startPos.y())/5));
        checkBound.start(100/6);
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
