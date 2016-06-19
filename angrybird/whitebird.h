#ifndef WHITEBIRD_H
#define WHITEBIRD_H

#include "gameitem.h"
#include "redbird.h"
#include <iostream>

class whitebird:public gameitem
{
public:
    whitebird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void click();
};

#endif // WHITEBIRD_H
