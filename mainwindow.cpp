#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "abstractobject.h"
#include "xmlparser.h"
#include "calc.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_birthdays_button_clicked()
{

    Calc::tries = 0;
    Calc::success = false;
    Calc::successCount = 0;
    Calc::percent = 0;

    bb.setPath(QCoreApplication::applicationDirPath() + "/XML_2_d.xml");
    ObjectPool::instance().clean();
    bb.Parse();
    ObjectPool::instance().init();

    int count;
    if (ui->cycles->text().isEmpty())
    {
       count = ui->spinBox->value();
    }
    else
    {
       count = ui->cycles->text().toInt();
    }

    for (; count > 0; count--)
    {
        Calc::success = false;
        Calc::tries++;
            for (AbstractObject *obj : ObjectPool::instance().pool)
            {
                obj->singleInvoke("Rand");
            }

            for (AbstractObject *obj : ObjectPool::instance().pool)
            {

                if (Calc::success == false)
                {
                  obj->singleInvoke("calc");
                }


            }
                Calc::success = false;
    }

    qDebug() << "TOTAL HITS!" << Calc::percent * 100 << "% ," << Calc::successCount << "out of  " << Calc::tries;
}

void MainWindow::on_pifagor_button_clicked()
{
      bb.setPath(QCoreApplication::applicationDirPath() + "/XML.xml");
      ObjectPool::instance().clean();
      bb.Parse();
      ObjectPool::instance().init();
      ObjectPool::instance().pool[0]->massInvoke(true);
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "                                                                           ";
    qDebug() << "                                                                           ";
    qDebug() << "                                                                           ";
    qDebug() << "                                                                           ";
    qDebug() << "                                                                           ";
}
