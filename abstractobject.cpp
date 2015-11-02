#include "abstractobject.h"
#include "isa.h"

AbstractObject::AbstractObject() //: QObject(parent)
{
}

AbstractObject::~AbstractObject()
{

}

void AbstractObject::coutProperties()
{
    printProp();
    for (int i = 0; i < isaLinks.length(); i++)
    {
      isaLinks[i]->getMethod();
    }
}

void AbstractObject::addLink(AbstractObject* obj)
{
   // Link *a = new IsA(obj);
    Link *a = new IsA(obj);
    //IsA a;
    this->isaLinks.push_back(a);
}

