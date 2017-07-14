#ifndef RAYA_H
#define RAYA_H

#include <QGraphicsTextItem>
#include <QVector>
#include "objetoprop.h"
#include <QGraphicsScene>
#include <QPropertyAnimation>
#include <QSvgRenderer>

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
    void mostrarRayas(QSvgRenderer *svgRenderer, QGraphicsScene *escena, int cantidad);
    void actualizarCaracter(QChar caracter);

};

#endif // RAYA_H
