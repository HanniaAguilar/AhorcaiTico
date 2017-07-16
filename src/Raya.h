#ifndef RAYA_H
#define RAYA_H

#include <QGraphicsSimpleTextItem>
//#include <QGraphicsTextItem>
#include <QVector>
#include "objetoprop.h"
#include <QGraphicsScene>
#include <QPropertyAnimation>
#include <QSvgRenderer>
#include <QObject>

class Raya  : public QObject
{
    Q_OBJECT
  protected:
    QGraphicsScene* m_escena;
    QVector<ObjetoProp*> v_rayas;
    QVector<QGraphicsSimpleTextItem*>v_letras;

  public:
    Raya();
    ~Raya();
    void dibujeRayas(int cantidad);
    void cargarRayas(QSvgRenderer *svgRenderer, QGraphicsScene *escena);
    void mostrarRayas(int cantidad);
    void ocultarRayas();
    void eliminarPalabra();

   public slots:
    void actualizarRayas(int cantidad);
    void colocarPalabra(QString palabra);
    void mostrarLetra(int pos);
};

#endif // RAYA_H
