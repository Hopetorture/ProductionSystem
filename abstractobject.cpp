#include "abstractobject.h"
#include "isa.h"
#include "objectpool.h"
#include <QDebug>

AbstractObject::AbstractObject() //: QObject(parent)
{
}

AbstractObject::~AbstractObject()
{

}

void AbstractObject::coutProperties()
{
    printProp();
    //qDebug() << this->id << "ID";
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

void AbstractObject::init()
{
    // инициализировать указатели из текстового формата.
//    for (QString s : this->stringLinks)
//    {
//       // qDebug() << this->stringLinks;
//        ObjectPool::instance().getPtr(s); // обезопасить, когда не будет совпадений
//    }

    for (int i = 0; i < stringLinks.length(); i++)
    {
        try {
         // qDebug() << this->stringLinks[i]; //works
       //this->isaLinks.push_back(Link = new Link(ObjectPool::instance().getPtr(stringLinks[i])));
                Link *newLink = new IsA(ObjectPool::instance().getPtr(stringLinks[i]));
                this->isaLinks.push_back(newLink);
            }
        catch(QString s)
        {
            //qDebug() << s;
        }
        catch(...)
        {
            qDebug() << "caught!";
        }
    }
  //  qDebug() << this->stringLinks;

}

