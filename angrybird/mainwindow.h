#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <QVector>
#include <iostream>

#include "gameitem.h"
#include "ground.h"
#include "redbird.h"
#include "yellowbird.h"
#include "whitebird.h"
#include "greenbird.h"
#include "barrier.h"
#include "collcheck.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *,QEvent *event);
    void closeEvent(QCloseEvent *);
    void startGame();
    void addBird();
    void reBuild();

signals:
    void birdStop();
    void quitGame();

private slots:
    void tick();
    void checkBird();
    void killBird();
    void QUITSLOT();
    void on_restart_clicked();
    void on_quit_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QVector<gameitem*>  itemList;
    QVector<gameitem*>  birdList;
    QVector<gameitem*>::iterator it;
    b2World *world;
    QTimer timer;
    QTimer checkBound;
    gameitem *itemnow;
    gameitem *pigPointer;
    ground *grdTemp;
    QPointF startPos;
    QPointF endPos;
    collCheck *countScore;
    int tempScore;
    bool canpress;
    bool skill;
    int birdamt;
    int score;
};

#endif // MAINWINDOW_H
