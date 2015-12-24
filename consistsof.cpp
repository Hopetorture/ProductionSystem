#include "consistsof.h"
#include "abstractobject.h"




void ConsistsOf::getMethod()
{
   qDebug() << parent->getID() << "Состоит из" << linked->getID() << " ";
   qDebug() << linked->getPorperties().filter("Area",Qt::CaseInsensitive);
}
