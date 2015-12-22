#include "isa.h"
#include "abstractobject.h"



QList<Property *> IsA::getMethod() const
{
    linked->massInvoke(true);
    return QList<Property*>();
}

