#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "abstractobject.h"
#include "xmlparser.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    XMLParser bb;
    bb.setPath(QCoreApplication::applicationDirPath() + "/XML.xml");
    bb.Parse();   
    ObjectPool::instance().init();
    qDebug() <<  ObjectPool::instance().pool[0]->id;
    ObjectPool::instance().pool[0]->massInvoke(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}
