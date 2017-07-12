#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QSvgRenderer>
#include "objetoprop.h"


class Controlador;

class MainWindow:public QGraphicsView
{

    protected:
      ObjetoProp* m_componente;
      QSvgRenderer* m_svgRenderer;

    public:
        MainWindow(QGraphicsScene* escena);
        ~MainWindow();
        void insertarComponentes(QGraphicsScene* escena);
};

#endif // MAINWINDOW_H
