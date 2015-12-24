#include "linkfactory.h"
#include "isa.h"
#include "consistsof.h"
#include "forms.h"
#include "partof.h"
#include "quads.h"
#include "logical.h"
#include "rand.h"
#include "debug_link.h"
#include "calc.h"

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
        link->setLinkType("IsA");
        return link;
    };
    patternHash.insert("IsA",f);

    /// --------------------------------

    std::function<Link*() > f1 = []()
    {
        Link* link = new Forms;
        link->setLinkType("forms");
        return link;
    };
    patternHash.insert("forms",f1);


    ///--------------------------------

    std::function<Link*() > f2 = []()
    {
        Link* link = new ConsistsOf;
        link->setLinkType("consistOf");
        return link;
    };
    patternHash.insert("consistOf",f2);

    ///--------------------------------

    std::function<Link*() > f3 = []()
    {
        Link* link = new Quads;
        link->setLinkType("quads");
        return link;
    };
    patternHash.insert("quads",f3);

   ///--------------------------------

    std::function<Link*() > f4 = []()
    {
        Link* link = new PartOf;
        link->setLinkType("partof");
        return link;
    };
    patternHash.insert("partof",f4);

    /// --------------------------------

    std::function<Link*() > f5 = []()
    {
        Link* link = new Logical;
        link->setLinkType("logical");
        return link;
    };
    patternHash.insert("logical",f5);

    /// --------------------------------

    std::function<Link*() > f6 = []()
    {
        Link* link = new Rand;
        link->setLinkType("Rand");
        return link;
    };
    patternHash.insert("Rand",f6);

    /// --------------------------------

    std::function<Link*() > f7 = []()
    {
        Link* link = new debug_link;
        link->setLinkType("debug_link");
        return link;
    };
    patternHash.insert("debug_link",f7);

    /// --------------------------------

    std::function<Link*() > f8 = []()
    {
        Link* link = new Calc;
        link->setLinkType("calc");
        return link;
    };
    patternHash.insert("calc",f8);
}

