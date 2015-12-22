#include "quads.h"
#include "abstractobject.h"
#include "propertypool.h"



QList<Property *> Quads::getMethod() const
{
     QStringList props = parent->getPorperties();
     for (QString &s : props)
     {
         s += " *4";
         if (s.contains("side"))
         {
             linked->addProp(s);
         }
     }
     props.filter("Area",Qt::CaseInsensitive);
     linked->addProp(props.filter("Area",Qt::CaseInsensitive).join(";"));
    DataPool::instance().fourTriangles = linked->getPorperties().filter("Area =").join("").replace("Area =","");
    qDebug() << linked->getPorperties().filter("Area =").join("") << "ДОЛЖНЫ БЫТЬ ПЛОЩАДЬ 4 ТРЕУГОЛЬНИКОВ.";
     linked->massInvoke(true);



     return QList<Property*>();
}
