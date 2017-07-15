#ifndef RAYA_H
#define RAYA_H

#include <QGraphicsTextItem>
#include <QVector>
#include "objetoprop.h"
#include <QGraphicsScene>
#include <QPropertyAnimation>
#include <QSvgRenderer>
#include <QObject>

class Raya  : public QGraphicsTextItem
{
    Q_OBJECT
  protected:
    QString m_caracter;
    QVector<ObjetoProp*> v_rayas;

  public:
    Raya(QString caracter, QColor color, QGraphicsItem *parent=nullptr);
    ~Raya();
    void dibujeRayas(int cantidad);
    void cargarRayas(QSvgRenderer *svgRenderer, QGraphicsScene *escena);
    void mostrarRayas(int cantidad);
    void ocultarRayas();
    void actualizarCaracter(QChar caracter);

   public slots:
    void actualizarRayas(int cantidad);

};

#endif // RAYA_H
