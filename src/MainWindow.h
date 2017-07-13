#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QSvgRenderer>
#include "objetoprop.h"
#include "teclas.h"


class Controlador;

class MainWindow:public QGraphicsView
{

    protected:
      ObjetoProp* m_componente;
      QSvgRenderer* m_svgRenderer;
      ObjetoProp* m_fondo;
      Teclas* teclas;

    public:
        MainWindow(QGraphicsScene* escena);
        ~MainWindow();
        void insertarComponentes(QGraphicsScene* escena);
        void dibujeFondo(QGraphicsScene* m_escena);
};

#endif // MAINWINDOW_H
