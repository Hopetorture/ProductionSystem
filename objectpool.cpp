#include "objectpool.h"
#include "propertypool.h"




void ObjectPool::pushObj(QString objID, QStringList objLinks, QStringList props,QStringList type)
{
    AbstractObject *obj = new AbstractObject(objID);

    for (QString s : props)
    {
      obj->addProp(s);
    }
    obj -> addStrLink(objLinks); // тексто-ссылки на др. объекты.
    obj -> addLinksType(type);
    this -> pool.push_back(obj);

}

void ObjectPool::pushObj(AbstractObject *obj)
{
    this->pool.push_back(obj);
}

AbstractObject *ObjectPool::getPtr(QString s)
{

    for (AbstractObject* obj : pool)
    {
        if ( s == "" )
        {
            throw(QString("empty"));
        }
        if (obj->getID() == s)
        {
            return obj;
        }
    }
    qWarning() << "getPtr() not returned a pointer. Consider changing a knowledge base";
    throw(qt_error_string());
}

void ObjectPool::init()
{

    for (int i = 0; i < pool.length(); i++)
    {
        pool[i]->init();
    }
}

void ObjectPool::clean()
{
    pool.clear();
    DataPool::instance().clear();
}
