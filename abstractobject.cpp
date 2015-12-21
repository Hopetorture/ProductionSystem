#include "abstractobject.h"
#include "isa.h"
#include "objectpool.h"
#include "quads.h"
#include "forms.h"
#include "consistsof.h"
#include "partof.h"

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
        if (!isaLinks[i]->getLinked()->visited)
        {
           // qDebug() << i << ": i";
           // qDebug() << isaLinks.length() << "Lenght";

             isaLinks[i]->getMethod();
             isaLinks[i]->getLinked()->visited = true; // чет кривота.
        }
    }
}

void AbstractObject::addLink(AbstractObject* obj,QString type)
{
   // Link *a = new IsA(obj);
    /// переделать в case
    if (type == "IsA")
    {
      Link *a = new IsA(obj);
      this->isaLinks.push_back(a);
    }
    else if (type == "quads")
    {
        Link *a = new Quads(obj);
        this->isaLinks.push_back(a);
        qDebug() << "A QUAD LINK!!";
    }
    else if (type == "forms")
    {
        Link *a = new Forms(obj);
        this->isaLinks.push_back(a);
        qDebug() << "A Forms LINK!!";
    }
    else if (type == "consistOf")
    {
        Link *a = new ConsistsOf(obj);
        this->isaLinks.push_back(a);
        qDebug() << "A ConsistsOf LINK!!";
    }
    else if (type == "partof")
    {
        Link *a = new PartOf(obj);
        this->isaLinks.push_back(a);
        qDebug() << "A PartOf LINK!!";
    }
    else
    {
        qDebug() << "unknown Link in:";
        qDebug() << this->id;
        qDebug() << type;
    }


    //IsA a;

}

void AbstractObject::init()
{
    // инициализировать указатели из текстового формата.
//    for (QString s : this->stringLinks)
//    {
//       // qDebug() << this->stringLinks;
//        ObjectPool::instance().getPtr(s); // обезопасить, когда не будет совпадений
//    }
   // qDebug() << this->stringLinks << "links";
   // qDebug() << this->LinksType << " LINKS TYPE";
    for (int i = 0; i < stringLinks.length(); i++)
    {
        try {
         // qDebug() << this->stringLinks[i]; //works
       //this->isaLinks.push_back(Link = new Link(ObjectPool::instance().getPtr(stringLinks[i])));
               // Link *newLink = new IsA(ObjectPool::instance().getPtr(stringLinks[i]));
            //qDebug() << this->LinksType.at(i) << "linktype";
            this->addLink (ObjectPool::instance().getPtr(stringLinks[i]),this->LinksType[i]);
         //   qDebug() << ObjectPool::instance().getPtr(stringLinks[i])->linktype() << "QSTRINGLIST HERE";
         //   qDebug() << "DEBUG----";
            //ObjectPool::instance().getPtr(stringLinks[i])->dbg() ;

          //  qDebug() << "DEBUG----";
               // this->isaLinks.push_back(newLink);
                // нужно разобраться тут, что бы конкретное инстанциирование связей был в
                // одном месте.
            }
        catch(QString &s)
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

