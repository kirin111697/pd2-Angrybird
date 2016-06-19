#include "barrier.h"

barrier::barrier(float x,float y,float w,float h,QTimer *timer,QPixmap pixmap,b2World *world,QGraphicsScene *scene)
    :gameitem(world)
{
    flag=false;
    point=0;
    pic.setPixmap(pixmap);
    pic.setTransformOriginPoint(pic.boundingRect().width()/2,pic.boundingRect().height()/2);
    itemsize=QSize(w,h);

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.bullet = true;
    bodyDef.position.Set(x,y);
    bodyDef.userData = this;
    body = world->CreateBody(&bodyDef);

    b2PolygonShape dynamicShape;
    dynamicShape.SetAsBox(w/2,h/2);
    b2FixtureDef fixturedef;
    fixturedef.shape = &dynamicShape;
    fixturedef.density = BARRIER_DENSITY;
    fixturedef.friction = BARRIER_FRICTION;
    fixturedef.restitution = BARRIER_RESTITUTION;
    body->SetAngularDamping(3);
    body->CreateFixture(&fixturedef);

    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));
    scene->addItem(&pic);
}

barrier::barrier(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene)
    :gameitem(world)
{
    flag=true;
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
    fixturedef.density = BARRIER_DENSITY;
    fixturedef.friction = BARRIER_FRICTION;
    fixturedef.restitution = BARRIER_RESTITUTION;
    body->SetAngularDamping(3);
    body->CreateFixture(&fixturedef);

    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));
    scene->addItem(&pic);
}

void barrier::collision(){
    if(flag){
        std::cout << "hit pig !" << std::endl ;
        point+=1000;
    }
    else{
        std::cout << "collision in barrier!" << std::endl;
    }
}
