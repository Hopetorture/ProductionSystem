#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include "xmlparser.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_birthdays_button_clicked();

    void on_pifagor_button_clicked();

    void on_pushButton_clicked();//cleanup

private:
    Ui::MainWindow *ui;
    XMLParser bb;
};

#endif // MAINWINDOW_H
