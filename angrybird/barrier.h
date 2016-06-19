#ifndef BARRIER_H
#define BARRIER_H

#include "gameitem.h"
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <iostream>

#define BARRIER_DENSITY 25.0f
#define BARRIER_FRICTION 1.0f
#define BARRIER_RESTITUTION 0.2f
#define BARRIER_HP 1000

class barrier:public gameitem
{
public:
    barrier(float x,float y,float w,float h,QTimer *timer,QPixmap pixmap,b2World *world,QGraphicsScene *scene);
    barrier(float x,float y,float radius,QTimer *timer,QPixmap pixmap,b2World *world,QGraphicsScene *scene);
    virtual void collision();
    int point;

private:
    bool flag;

};

#endif // BARRIER_H
