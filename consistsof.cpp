#include "consistsof.h"
#include "abstractobject.h"




QList<Property *> ConsistsOf::getMethod() const
{
   qDebug() << parent->id << "Состоит из" << linked->id << " ";
   qDebug() << linked->getPorperties().filter("Area",Qt::CaseInsensitive);

   return QList<Property*>();
}
