#include "isa.h"
#include "abstractobject.h"


//IsA::IsA(AbstractObject* o)
//{
//        linked = o;
//}

//IsA::~IsA()
//{

//}

QList<Property *> IsA::getMethod() const
{
   // linked->coutProperties();
    linked->coutProperties();
    return QList<Property*>();
}

