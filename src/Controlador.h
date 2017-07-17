#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPoint>
#include <QSequentialAnimationGroup>
#include <QStyleFactory>
#include <QSvgRenderer>
#include <QtMath>
#include <QVector>

#include "Diccionario.h"
#include "Marcador.h"
#include "Teclas.h"
#include "Vista.h"

class Vista;

class Controlador : public QApplication
{
   Q_OBJECT

   protected:
    QGraphicsScene* m_escena;  // administra la escena
    Vista* m_vista; // administra la vista
    Marcador* marcador; // muestra el marcador
    Diccionario* diccionario; // mecanica del juego

   public:    
    Controlador(int &argc, char **argv, int flags = ApplicationFlags); //constructor
    ~Controlador(); // destructor
    int correr(); // metodo de correr el juego
};

#endif // CONTROLADOR_H
