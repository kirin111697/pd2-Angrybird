#ifndef YELLOBIRD_H
#define YELLOBIRD_H

#include "gameitem.h"
#include "redbird.h"

class yellobird:public gameitem,public redBird
{
public:
    yellobird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void collision();
    virtual void click();
};

#endif // YELLOBIRD_H
