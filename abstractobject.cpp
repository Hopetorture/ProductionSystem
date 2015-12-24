#include "abstractobject.h"
#include "isa.h"
#include "objectpool.h"
#include "quads.h"
#include "forms.h"
#include "consistsof.h"
#include "partof.h"
#include "linkfactory.h"

#include <QDebug>


AbstractObject::~AbstractObject()
{
}

void AbstractObject::printProp() const
{
    for (Property* p : properties)
    {
        qDebug() << p->data;
    }
}

QStringList AbstractObject::getPorperties() const
{
    QStringList res;
    for (Property* p : properties)
    {
        res.push_back(p->data);


    }
    return res;
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
            // isaLinks[i]->getLinked()->visited = true;
        }
    }
}

void AbstractObject::singleInvoke(QString s)
{
    for(Link* link : isaLinks)
    {       
        if (link->getLinkType() == s)
        {
            link->getMethod();
        }
        else
        {
           // qWarning() << "wrong argument in Single Invoke  " << s;
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
    int i=0;
    for (QString s : stringLinks)
    {
        try
        {
            this->addLink (ObjectPool::instance().getPtr(s),this->LinksType[i]);
        }

        catch(QString &s)
        {
            qDebug() << s;
        }

        catch(...)
        {
            qDebug() << "caught!";
        }

        i++;
    }

}

