#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <QApplication>
#include "Vista.h"
#include "mecanicajuego.h"
#include "teclas.h"
#include <QSvgRenderer>
#include <QtMath>
#include <QApplication>
#include <QGraphicsScene>
#include <QStyleFactory>
#include <QSequentialAnimationGroup>
#include <QPoint>
#include <QVector>
#include <Random>

class QGraphicsScene;
class QSvgRenderer;
class QGraphicsView;
class Marcador;


class Controlador : public QApplication
{
    Q_OBJECT
   protected:
    /// administra la escena
    QGraphicsScene* m_escena;
    /// administra la vista
    Vista* m_vista;
    /// muestra el marcador
    Marcador* marcador;
    /// para utilizar archivos svg
    QSvgRenderer* svgRenderer = nullptr;
    /// mecanica del juego
    MecanicaJuego* mecanicaJuego;
    /// teclado
    Teclas* teclas;
    QSvgRenderer* m_svgRenderer;


   public:
    ///controlador
    Controlador(int &argc, char **argv, int flags = ApplicationFlags);
    /// destructor
    ~Controlador();
    /// metodo de correr el juego
    int correr();

};

#endif // CONTROLADOR_H
