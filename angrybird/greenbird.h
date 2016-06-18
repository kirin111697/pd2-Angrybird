#ifndef GREENBIRD_H
#define GREENBIRD_H

#include "gameitem.h"
#include "redbird.h"
#include <iostream>

class greenbird:public redBird
{
public:
    greenbird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void click();
};

#endif // GREENBIRD_H
