#include "objectpool.h"




void ObjectPool::pushObj(QString objID, QStringList objLinks, QStringList props)
{
    //zx.insert(QStringList("list"),"string");
    //zx.insert(QStringList("list111"),"string222");
   // qDebug() << objID + "ID /n" << objLinks;
    AbstractObject *obj = new AbstractObject;
//    for (Property p : this -> QList<Property>) //нужен мок-лист.
//    {
//      obj->addProp(); // добавить метод копирования,
//                      //
//    }
        for (QString s : props) //нужен мок-лист.
        {
           // qDebug() << s << "HERE";
          obj->addProp(s); // добавить метод копирования
        }
    obj->setID(objID); // нужно где-то хранить или получать
    obj-> addStrLink(objLinks); // тексто-ссылки на др. объекты.
    this->pool.push_back(obj);

}

void ObjectPool::pushObj(AbstractObject *obj)
{
    this->pool.push_back(obj);
}

AbstractObject *ObjectPool::getPtr(QString s)
{
//    for (int i = 0; i <= this->pool.length(); i++)
//    {
//        if (pool[i]->id == s)
//            return pool[i];

//    }
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
   // return nullptr;
}
