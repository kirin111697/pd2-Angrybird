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

signals:
    void quitGame();

private slots:
    void tick();
    void QUITSLOT();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QTimer timer;
    redBird *itemnow;
    QPointF startPos;
    QPointF endPos;
};

#endif // MAINWINDOW_H
