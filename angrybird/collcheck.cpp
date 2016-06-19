#include "collcheck.h"

collCheck::collCheck()
{
}

void collCheck::BeginContact(b2Contact *contact)
{
    static_cast<gameitem*>(contact->GetFixtureA()->GetBody()->GetUserData())->collision();
    static_cast<gameitem*>(contact->GetFixtureB()->GetBody()->GetUserData())->collision();
}
