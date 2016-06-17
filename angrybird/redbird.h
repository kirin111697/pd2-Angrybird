#ifndef REDBIRD_H
#define REDBIRD_H

#include "gameitem.h"
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define BIRD_DENSITY 10.0f
#define BIRD_FRICTION 0.2f
#define BIRD_RESTITUTION 0.5f

class redBird : public gameitem
{
public:
    redBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void setLinearVelocity(b2Vec2 velocity);
};

#endif // REDBIRD_H
