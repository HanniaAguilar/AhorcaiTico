#ifndef TECLAS_H
#define TECLAS_H

#include <QGraphicsScene>
#include <QObject>
#include <QPropertyAnimation>
#include <QString>
#include <QSvgRenderer>
#include <QVector>

#include "Diccionario.h"
#include "objetoprop.h"

class ObjetoProp;

class Teclas : public QObject
{
   Q_OBJECT

   protected:
    QVector<QString> v_teclado; //Vector con los nombres de las teclas en el svg
    Diccionario* teclasDiccionario ; //Diccionario con las palabras

   public:
    QVector<ObjetoProp*> v_objetosProp; //ObjetosProp de las teclas

   public:
    Teclas(Diccionario* diccionario); //Constructor
    ~Teclas(); //Destructor
    void agregarTeclado(); //Agregar los id en el vector del teclado
    void cargarTeclado(QSvgRenderer* svgRenderer, QGraphicsScene *escena); //Carga el teclado a la escena

   public slots:
    void restablecerTeclado();//Muestra el teclado completo, volver todos a opacidad 1

};
#endif // TECLAS_H
