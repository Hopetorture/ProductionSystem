#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "abstractobject.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    AbstractObject soKrat ;
    soKrat.addProp("philosopher");
    soKrat.printProp();
}

MainWindow::~MainWindow()
{
    delete ui;
}
