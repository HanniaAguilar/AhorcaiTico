#ifndef TECLAS_H
#define TECLAS_H

#include "objetoprop.h"
#include <QGraphicsScene>
#include <QPropertyAnimation>
#include <QSvgRenderer>
#include <QVector>
#include <QString>
#include <algorithm>
#include <random>
#include <chrono>

class Teclas
{
   protected:
    QVector<QString> v_teclado;

   public:
    QVector<ObjetoProp*> v_objetosProp;

   public:
    Teclas();
    void agregarTeclado();
    void mostrarTeclado(QSvgRenderer* svgRenderer, QGraphicsScene *escena);
};

#endif // TECLAS_H
