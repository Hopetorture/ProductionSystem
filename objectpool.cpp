#include "objectpool.h"




void ObjectPool::pushObj(QString objID, QStringList objLinks, QStringList props,QStringList type)
{

    AbstractObject *obj = new AbstractObject;

        for (QString s : props)
        {           
          obj->addProp(s);
        }
    obj -> setID(objID);
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
        if (obj->id == s)
        {
            return obj;
        }

    }
    qWarning() << "getPtr() not returned a pointer. Consider changing a knowledge base";
    throw(qt_error_string());
}
