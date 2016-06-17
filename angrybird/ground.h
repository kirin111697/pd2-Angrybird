#ifndef GROUND_H
#define GROUND_H

#include "gameitem.h"
#include <QGraphicsScene>

class ground: public gameitem
{
public:
    ground(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // GROUND_H
