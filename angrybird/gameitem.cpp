#include "gameitem.h"
#include <iostream>

gameitem::gameitem(b2World *world):
    body(NULL),gameworld(world)
{
}

gameitem::~gameitem()
{
    gameworld->DestroyBody(body);
}

QSizeF gameitem::g_windowsize = QSizeF();
QSizeF gameitem::g_worldsize = QSizeF();

void gameitem::setGlobalSize(QSizeF worldsize, QSizeF windowsize)
{
    g_worldsize = worldsize;
    g_windowsize = windowsize;
}

void gameitem::paint()
{
    b2Vec2 pos = body->GetPosition();
    //std::cout << g_body->GetAngle() << std::endl;
    QPointF mapPoint;
    mapPoint.setX(((pos.x-itemsize.width()/2) * g_windowsize.width())/g_worldsize.width());
    mapPoint.setY((1.0f - (pos.y+itemsize.height()/2)/g_worldsize.height()) * g_windowsize.height());
    pic.setPos(mapPoint);
    pic.resetTransform();
    pic.setRotation(-(body->GetAngle()*180/3.14159));
}
