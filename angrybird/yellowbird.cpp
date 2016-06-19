#include "yellowbird.h"

yellowbird::yellowbird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene)
  :gameitem(world)
{
    pic.setPixmap(pixmap);
    pic.setTransformOriginPoint(pic.boundingRect().width()/2,pic.boundingRect().height()/2);
    itemsize=QSize(radius*2,radius*2);

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.bullet = true;
    bodyDef.position.Set(x,y);
    bodyDef.userData = this;
    body = world->CreateBody(&bodyDef);

    b2CircleShape dynamicShape;
    dynamicShape.m_radius = radius;
    b2FixtureDef fixturedef;
    fixturedef.shape = &dynamicShape;
    fixturedef.density = BIRD_DENSITY;
    fixturedef.friction = BIRD_FRICTION;
    fixturedef.restitution = BIRD_RESTITUTION;
    body->SetAngularDamping(3);
    body->CreateFixture(&fixturedef);

    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));
    scene->addItem(&pic);
}

void yellowbird::collision()
{
    std::cout << "yellow bird hit something!" << std::endl ;
}

void yellowbird::click()
{
    std::cout << "click yellow !" << std::endl ;
    b2Vec2 v = body->GetLinearVelocity();
    body->SetLinearVelocity(b2Vec2(v.x*5,v.y*5));
}
