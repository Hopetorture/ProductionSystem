#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "abstractobject.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    AbstractObject soKrat ;
    AbstractObject *human = new AbstractObject(); //обернуть в QSharedPTR
    human->addProp("smerten");
    soKrat.addProp("philosopher");

    //soKrat.printProp();

    soKrat.addLink(human);
    soKrat.coutProperties();

}

MainWindow::~MainWindow()
{
    delete ui;
}
