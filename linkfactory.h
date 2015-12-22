#ifndef LINKFACTORY_H
#define LINKFACTORY_H

#include "link.h"

#include <QHash>
#include <QString>

class LinkFactory
{
public:
    LinkFactory();
    ~LinkFactory(){}
    Link* getLink(QString s);
private:
    QHash <QString,std::function<Link*()> > patternHash;
    void init();

};

#endif // LINKFACTORY_H
