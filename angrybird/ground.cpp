#include "ground.h"

ground::ground(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene):gameitem(world)
{
    pic.setPixmap(pixmap);
    itemsize = QSize(w,h);

    b2BodyDef groundDef;
    groundDef.userData = this;
    groundDef.position.Set(x,y);

    body = world->CreateBody(&groundDef);
    b2PolygonShape bodyBox;
    bodyBox.SetAsBox(w/2,h/2);
    body->CreateFixture(&bodyBox,9.0f);

    scene->addItem(&pic);
    paint();
}
