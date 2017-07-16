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
#include <QObject>

class Teclas : public QObject
{
    Q_OBJECT
   protected:
    QVector<QString> v_teclado;
    Diccionario* teclasDiccionario;///agrego para que tambien tenga un puntero a ese dicccionario

   public:
    QVector<ObjetoProp*> v_objetosProp;

   public:
    Teclas(Diccionario* diccionario);
    void agregarTeclado();
    void cargarTeclado(QSvgRenderer* svgRenderer, QGraphicsScene *escena);
    void mostrarTeclado();

   public slots:
    void restablecerTeclado();

};
#endif // TECLAS_H
