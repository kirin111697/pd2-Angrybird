#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <iostream>

#include "gameitem.h"
#include "ground.h"
#include "redbird.h"
#include "barrier.h"

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

signals:
    void birdStop();
    void quitGame();

private slots:
    void tick();
    void checkBird();
    void killBird();
    void QUITSLOT();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QTimer timer;
    QTimer checkBound;
    redBird *itemnow;
    ground *grdTemp;
    QPointF startPos;
    QPointF endPos;
    bool canpress;
};

#endif // MAINWINDOW_H
