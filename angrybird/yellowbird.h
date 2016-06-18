#ifndef YELLOWBIRD_H
#define YELLOWBIRD_H

#include "gameitem.h"
#include "redbird.h"
#include <iostream>

class yellowbird:public redBird
{
public:
    yellowbird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void collision();
    virtual void click();
};

#endif // YELLOBIRD_H
