#ifndef OBJECTPOOL_H
#define OBJECTPOOL_H

#include <QPair>
#include <QHash>

#include "abstractobject.h"

/*
 * пул всех объектов, синглтон майерса
*/

class ObjectPool
{
public:
   ~ObjectPool(){}

    static ObjectPool &instance()
    {
        static ObjectPool config;
        return config;
    }
   // pushObj(QString s,QStringList qsl);  // можно запушить две пары.
    //pushObj(QPair<QString,QStringList> obj,QPair<QString,QStringList> prop);  // можно запушить две пары.
   void pushObj(QString objID, QStringList objLinks, QStringList props, QStringList type);
   void pushObj(AbstractObject* obj);
   AbstractObject* getPtr(QString s);

   void init()
   {
//       for (AbstractObject *obj : pool)
//       {
//           obj->init();
//       }
      // qDebug() << pool.length();
       for (int i = 0; i < pool.length(); i++)
       {
            pool[i]->init();
       }
       //pool[0]->init();
//      qDebug() << pool[1]->id;
//      qDebug() << pool[2]->id;
//      qDebug() << pool[3]->id;
   }
   QList<AbstractObject*> pool;
private:

  //  QList<AbstractObject*> pool;
   // QHash<QStringList,QString> zx;
    ObjectPool() {}
    ObjectPool(const ObjectPool&) {}
    ObjectPool &operator=(const ObjectPool&) {return *this;}
    //QPair<QString,int> a;


};

#endif // OBJECTPOOL_H
