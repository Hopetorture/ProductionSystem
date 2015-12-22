#include "linkfactory.h"
#include "isa.h"
#include "consistsof.h"
#include "forms.h"
#include "partof.h"
#include "quads.h"
#include "logical.h"

LinkFactory::LinkFactory()
{
 init();
}

Link *LinkFactory::getLink(QString s)
{
   std::function<Link*() > f = patternHash.value(s,nullptr);
   if ( f == nullptr)
   {
       qWarning() << "wrong hash key!!!";
   }
   return f();
}


void LinkFactory::init()
{
    std::function<Link*() > f = []()
    {
        Link* link = new IsA;
        return link;
    };
    patternHash.insert("IsA",f);

    /// --------------------------------quads  forms consistOf partof

    std::function<Link*() > f1 = []()
    {
        Link* link = new Forms;
        return link;
    };
    patternHash.insert("forms",f1);

    ///--------------------------------

    std::function<Link*() > f2 = []()
    {
        Link* link = new ConsistsOf;
        return link;
    };
    patternHash.insert("consistOf",f2);

    ///--------------------------------

    std::function<Link*() > f3 = []()
    {
        Link* link = new Quads;
        return link;
    };
    patternHash.insert("quads",f3);

   ///--------------------------------

    std::function<Link*() > f4 = []()
    {
        Link* link = new PartOf;
        return link;
    };
    patternHash.insert("partof",f4);

    /// --------------------------------logical

    std::function<Link*() > f5 = []()
    {
        Link* link = new Logical;
        return link;
    };
    patternHash.insert("logical",f5);

}

