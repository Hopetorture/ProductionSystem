#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "abstractobject.h"
#include "xmlparser.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    AbstractObject soKrat ;
//    AbstractObject *human = new AbstractObject(); //обернуть в QSharedPTR
//    human->addProp("smerten");
//    soKrat.addProp("philosopher");

//    //soKrat.printProp();

//    soKrat.addLink(human);
//    soKrat.coutProperties();

    //XMLParser *prs = new XMLParser(QCoreApplication::applicationDirPath() + "XML.xml");
    //prs->Parse();
    XMLParser bb;
    bb.setPath(QCoreApplication::applicationDirPath() + "/XML.xml");
    bb.Parse();
    //bb.Parse(QString(QCoreApplication::applicationDirPath() + "/XML.xml"));
   //qDebug() << QCoreApplication::applicationDirPath() + "/XML.xml";
  // qDebug() << QCoreApplication::applicationDirPath() ;
    ObjectPool::instance().init();    

// /* qDebug() << */ ObjectPool::instance().pool[0]->dbg();
    qDebug() <<  ObjectPool::instance().pool[0]->id;
    /* qDebug() << */ ObjectPool::instance().pool[0]->coutProperties();

 // qDebug() << ObjectPool::instance().pool[0]->id; //pool[0] = sky



}

MainWindow::~MainWindow()
{
    delete ui;
}
