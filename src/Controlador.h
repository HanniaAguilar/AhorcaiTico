#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "MainWindow.h"
#include <QSvgRenderer>
#include <QtMath>
#include <QApplication>
#include <QGraphicsScene>
#include <QStyleFactory>
#include <QSequentialAnimationGroup>
#include <QPoint>
#include <QVector>
#include <Random>
//#include <Chrono>


class QGraphicsScene;


class Controlador : public QApplication
{
    Q_OBJECT

    protected:

    QGraphicsScene* m_escena;
    MainWindow* m_vista;


    public:

    Controlador(int &argc, char **argv, int flags = ApplicationFlags);
    ~Controlador();
    int correr();
    
    private slots:

};

#endif // CONTROLADOR_H
