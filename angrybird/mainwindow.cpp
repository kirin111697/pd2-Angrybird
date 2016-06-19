#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    canpress(false),
    skill(false),
    birdamt(0),
    tempScore(0),
    score(-300)
{
    ui->setupUi(this);
    qApp->installEventFilter(this);
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(&checkBound,SIGNAL(timeout()),this,SLOT(checkBird()));
    connect(this,SIGNAL(birdStop()),this,SLOT(killBird()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    world = new b2World(b2Vec2(0.0f, -9.8f));
    countScore = new collCheck;
    world->SetContactListener(countScore);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *){
    scene = new QGraphicsScene(0,0,width(),ui->graphicsView->height());
    ui->graphicsView->setScene(scene);

    ui->lcdNumber->display(0);
    gameitem::setGlobalSize(QSizeF(32,21.25),this->size());
    ground *grd = new ground(16,1.5,32,2,QPixmap(":/bg/res/HALLOWEEN2011_GROUND.png").scaled(width(),height()/6.0),world,scene);
    reBuild();
    timer.start(100/6);
}

void MainWindow::startGame(){
    if (birdamt<5){
        ground *ss = new ground(4.4,4.5,1,1.1,QPixmap(),world,scene);
        grdTemp = ss;
        //groundList.push_back(ss);
        addBird();
        birdamt++;
    }
    else{
        canpress=false;
        skill=false;
    }
}

void MainWindow::addBird(){
    //qDebug() << "added";
    if (birdamt==0){
        yellowbird *yellow = new yellowbird(4.3f,7.0f,0.7f,&timer,QPixmap(":/bg/res/angry-bird-yellow-icon.png"),world,scene);
        birdList.push_back(yellow);
        itemnow=yellow;
        it=&itemnow;
        canpress=true;
    }
    else if(birdamt==1){
        whitebird *white = new whitebird(4.3f,7.0f,0.8f,&timer,QPixmap(":/bg/res/angry-bird-white-icon.png"),world,scene);
        birdList.push_back(white);
        itemnow=white;
        it=&itemnow;
        canpress=true;
    }
    else if(birdamt==2){
        greenbird *green = new greenbird(4.6f,7.0f,0.5f,&timer,QPixmap(":/bg/res/greenbird_SMALL.png"),world,scene);
        birdList.push_back(green);
        itemnow=green;
        it=&itemnow;
        canpress=true;
    }
    else{
        redBird *red = new redBird(4.4f,7.0f,0.78f,&timer,QPixmap(":/bg/res/Angry_Bird_red_small.png"),world,scene);
        birdList.push_back(red);
        itemnow=red;
        it=&itemnow;
        canpress=true;
    }
}

void MainWindow::reBuild()
{
    itemList.push_back(new barrier(17,5,20.0/32.0,83.0/32.0,&timer,QPixmap(":/bg/res/BLOCK_ROCK_1_4_2.png"),world,scene));
    itemList.push_back(new barrier(21,5,20.0/32.0,83.0/32.0,&timer,QPixmap(":/bg/res/BLOCK_ROCK_1_4_2.png"),world,scene));
    itemList.push_back(new barrier(19.2,7,168.0/32.0,20.0/32.0,&timer,QPixmap(":/bg/res/BLOCK_ROCK_1_6.png"),world,scene));
    itemList.push_back(new barrier(14.87,5,20.0/32.0,83.0/32.0,&timer,QPixmap(":/bg/res/BLOCK_ROCK_1_4_2.png"),world,scene));
    itemList.push_back(new barrier(23.13,5,20.0/32.0,83.0/32.0,&timer,QPixmap(":/bg/res/BLOCK_ROCK_1_4_2.png"),world,scene));
    itemList.push_back(new barrier(14.87,8,83.0/32.0,20.0/32.0,&timer,QPixmap(":/bg/res/BLOCK_ROCK_1_4.png"),world,scene));
    itemList.push_back(new barrier(23.13,8,83.0/32.0,20.0/32.0,&timer,QPixmap(":/bg/res/BLOCK_ROCK_1_4.png"),world,scene));
    itemList.push_back(new barrier(18,9,20.0/32.0,83.0/32.0,&timer,QPixmap(":/bg/res/BLOCK_ROCK_1_4_2.png"),world,scene));
    itemList.push_back(new barrier(20,9,20.0/32.0,83.0/32.0,&timer,QPixmap(":/bg/res/BLOCK_ROCK_1_4_2.png"),world,scene));
    itemList.push_back(new barrier(19,11,83.0/32.0,20.0/32.0,&timer,QPixmap(":/bg/res/BLOCK_ROCK_1_4.png"),world,scene));
    barrier *piggy = new barrier(19.2f,4.0f,1.0f,&timer,QPixmap(":/bg/res/pigy-angry-birds.png"),world,scene);
    pigPointer=piggy;
    itemList.push_back(piggy);
}

void MainWindow::killBird(){
    delete (*it);
    std::cout << "KILL BIRD !" << std::endl;
    birdList.clear();
    //groundList.clear();
    //itemList.clear();
    startGame();
}

void MainWindow::checkBird(){
    b2Vec2 birdPos=static_cast<redBird*>(itemnow)->getPos();
    b2Vec2 birdVelo=static_cast<redBird*>(itemnow)->getVelocity();
    //std::cout << "x is " << birdPos.x << std::endl ;
    if (birdPos.x > 32 || birdPos.x < 0){
        emit birdStop();
        std::cout << "out of window !" << std::endl ;
        checkBound.stop();
    }
    //std::cout << "y is " << birdPos.y << std::endl ;
    if (birdPos.y < 3.3){
        if (birdVelo.x < 0.000000001 && birdVelo.y < 0.000000001){
            emit birdStop();
            std::cout << "too slow !" << std::endl ;
            checkBound.stop();
        }
    }
    else if (birdVelo.x==0 && birdVelo.y==0){
        emit birdStop();
        std::cout << "too slow !" << std::endl ;
        checkBound.stop();
    }
}

bool MainWindow::eventFilter(QObject *,QEvent *event){
    if(canpress==false){
        if(skill){
            if(event->type() == QEvent::MouseButtonPress){
                itemnow->click();
                skill=false;
            }
        }
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
        static_cast<redBird*>(itemnow)->setLinearVelocity(b2Vec2((startPos.x()-endPos.x())/5,(endPos.y()-startPos.y())/5));
        checkBound.start(100/6);
        skill=true;
    }
    return false;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    emit quitGame();
}

void MainWindow::tick()
{
    ui->lcdNumber->display(score);
    world->Step(1.0/60.0,6,2);
    scene->update();
    if (pigPointer != NULL){
        int p = static_cast<barrier*>(pigPointer)->point;
        //std::cout << "pig score is " << p << std::endl ;
        if(tempScore != p){
            tempScore = p;
            score += tempScore;
            //std::cout << "total score is " << score << std::endl ;
        }
    }
}

void MainWindow::QUITSLOT()
{
    std::cout << "Quit Game Signal receive !" << std::endl ;
}

void MainWindow::on_restart_clicked()
{
    if (birdamt<5){
        killBird();
    }
    for(int i=0;i < itemList.size();++i){
        it=&itemList[i];
        delete (*it);
    }
    itemList.clear();
    for(int i=0;i < birdList.size();++i){
        it=&birdList[i];
        delete (*it);
    }
    birdList.clear();
    reBuild();
    birdamt=0;
    canpress=false;
    score=-300;
    startGame();
}

void MainWindow::on_quit_clicked()
{
    this->close();
}
