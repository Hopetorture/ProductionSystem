#include "abstractobject.h"
#include "isa.h"
#include "objectpool.h"
#include "quads.h"
#include "forms.h"
#include "consistsof.h"
#include "partof.h"
#include "linkfactory.h"

#include <QDebug>

AbstractObject::AbstractObject()
{
}

AbstractObject::~AbstractObject()
{

}

void AbstractObject::massInvoke(bool doPrintProp)
{
    if (doPrintProp)
        printProp();

    for (int i = 0; i < isaLinks.length(); i++)
    {
        if (!isaLinks[i]->getLinked()->visited)
        {
             isaLinks[i]->getMethod();
             isaLinks[i]->getLinked()->visited = true;
        }
    }
}

void AbstractObject::singleInvoke(QString s)
{
  for (int i = 0; i < isaLinks.length(); i++ )
  {
      if (isaLinks[i]->getLinkedId() == s )
      {
          isaLinks[i]->getMethod();
      }
  }
}

void AbstractObject::addLink(AbstractObject* obj,QString type)
{
    LinkFactory factory;

    Link *link = factory.getLink(type);
    link->setLink(obj);
    link->setParent(this);
    this->isaLinks.push_back(link);

}

void AbstractObject::init()
{

    for (int i = 0; i < stringLinks.length(); i++)
    {
        try
        {
            this->addLink (ObjectPool::instance().getPtr(stringLinks[i]),this->LinksType[i]);
        }

        catch(QString &s)
        {
            qDebug() << s;
        }

        catch(...)
        {
            qDebug() << "caught!";
        }
    }

}

