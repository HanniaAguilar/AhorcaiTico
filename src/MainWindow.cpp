/*#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}*/

#include "mainwindow.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTime>
#include <QTimer>

MainWindow::MainWindow(int &argc, char **argv, int flags)
    : QApplication (argc, argv, flags)
    , escena(nullptr)
    , vista(nullptr)
{
}

MainWindow::~MainWindow()
{
    delete escena;
    delete vista;
}

int MainWindow::run()
{
    escena = new QGraphicsScene();
    vista = new QGraphicsView(escena);
    vista->show();
   return exec();
}
