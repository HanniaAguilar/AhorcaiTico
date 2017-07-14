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
#include "Diccionario.h"

class Teclas
{
   protected:
    QVector<QString> v_teclado;
    Diccionario* teclasDic;///agrego para que tambien tenga un puntero a ese dicccionario

   public:
    QVector<ObjetoProp*> v_objetosProp;

   public:
    Teclas(Diccionario* d);//ahora recibe un diccionario
    void agregarTeclado();
    void mostrarTeclado(QSvgRenderer* svgRenderer, QGraphicsScene *escena);
};
#endif // TECLAS_H
