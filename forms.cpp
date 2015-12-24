#include "forms.h"
#include "abstractobject.h"
#include "propertypool.h"




void Forms::getMethod()
{
    QString side;
    if (linked->getID() == "LittleSquare")
       {
         side = "Сторона: ";
         side += parent->getPorperties().filter("side B").replaceInStrings("*4","").join(" ");
         side += " - ";
         side += parent->getPorperties().filter("side A").replaceInStrings("*4","").join(" ");
       }
    else
    {
        side = parent->getPorperties().filter("side C").replaceInStrings("*4","").join("");
    }
    linked->addProp(side);

    QString area = "Area = ( " ;
    linked->addProp(area + side.replace("Сторона:", "") + " )" + "^2");

    qDebug() << parent->getID() << "образует: " << linked->getID() << "cо стороной" << side <<  "и свойствами: ";

    qDebug() << "RECTANGLE: ";
    linked->printProp();

    QString tmp = linked->getPorperties().filter("Area",Qt::CaseInsensitive).join(" ");
    tmp.replace("Area ="," ");
    DataPool::instance().strList.append(tmp);

    if (linked->getID() == "LittleSquare")
    {
        linked->massInvoke(false);

    }

}
