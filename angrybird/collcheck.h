#ifndef COLLCHECK_H
#define COLLCHECK_H

#include "gameitem.h"
#include <Box2D/Box2D.h>

class collCheck:public b2ContactListener
{
public:
    collCheck();
    void BeginContact(b2Contact *contact);
};

#endif // COLLCHECK_H
