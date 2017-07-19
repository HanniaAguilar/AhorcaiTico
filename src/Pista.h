#ifndef PISTA_H
#define PISTA_H

#include <QGraphicsScene>
#include <QObject>
#include <QSvgRenderer>

#include "Diccionario.h"
#include "objetoprop.h"


class ObjetoProp;

class Pista : public QObject
{
    Q_OBJECT

   protected:
    QSvgRenderer* m_renderer;
    QGraphicsScene* m_escena;
    ObjetoProp* o_pista;
    Diccionario* diccionario;
    int m_contadorError;

   public:
    Pista(QSvgRenderer *svgRenderer, QGraphicsScene *escena, Diccionario *diccionario);
    ~Pista();
    void cargar();
    void mostrar();


   signals:
    void mostrarAyuda();

   public slots:
    /*void puedeTocar();
    void aumenteContError(bool encontrada);*/
    void ocultarPista();
    void mostrarPista();
};

#endif // PISTA_H
