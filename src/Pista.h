#ifndef PISTA_H
#define PISTA_H

#include <QGraphicsScene>
#include <QObject>
#include <QSvgRenderer>
#include <QMessageBox>

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
    Diccionario* m_diccionario;

   public:
    Pista(QSvgRenderer *svgRenderer, QGraphicsScene *escena, Diccionario *m_diccionario);
    ~Pista();
    void cargar();


   signals:

   public slots:
    void ocultarPista();//oculta la pista
    void mostrarPista();
    void mostrarAyuda(QString pista);
    void mostrarInstrucciones();
};

#endif // PISTA_H
