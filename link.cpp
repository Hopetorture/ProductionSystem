#include "link.h"
#include "abstractobject.h"

Link::Link()
{
    linked = nullptr;
}

Link::~Link()
{

}

QString Link::getParentId()
{
    return this->parent->id;
}

QString Link::getLinkedId()
{
 return this->linked->id;
}

