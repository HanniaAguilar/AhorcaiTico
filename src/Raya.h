#ifndef RAYA_H
#define RAYA_H

#include <QColor>
#include <QFont>
#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include <QObject>
#include <QPropertyAnimation>
#include <QSvgRenderer>
#include <QVector>

#include "Diccionario.h"
#include "objetoprop.h"

class Raya  : public QObject
{
  Q_OBJECT

  protected:
    QGraphicsScene* m_escena; //Guarda la escena
    QVector<ObjetoProp*> v_rayas; //Vector con las rayas
    QVector<QGraphicsSimpleTextItem*>v_letras; //Vector con las letras de la palabra a adivinar
    Diccionario* m_diccionario; //Puntero al diccionario

  public:
    Raya(Diccionario* diccionario); //Constructor
    ~Raya(); //Destructor
    void cargarRayas(QSvgRenderer *svgRenderer, QGraphicsScene *escena); //Dibuja las rayas con opacidad 0
    void eliminarPalabra(); //Elimina las letras de la palabra anterior para colocar otra nueva

   public slots:
    void actualizarRayas(int cantidad); //Oculta y muestra las nueva cantidad de rayas
    void colocarPalabra(QString palabra); //Coloca la nueva palabra en la escena con opacidad 0
    void mostrarLetra(int pos); //Muestra la letra en la posición si es adivinada
    void mostrarPalabra(); // si pierde muestra la palabra
};

#endif // RAYA_H
