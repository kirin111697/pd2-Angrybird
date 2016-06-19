#ifndef REDBIRD_H
#define REDBIRD_H

#include "gameitem.h"
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <iostream>

#define BIRD_DENSITY 5.0f
#define BIRD_FRICTION 1.0f
#define BIRD_RESTITUTION 0.5f

class redBird : public gameitem
{
public:
    redBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void setLinearVelocity(b2Vec2 velocity);
    b2Vec2 getPos();
    b2Vec2 getVelocity();
};

#endif // REDBIRD_H
