#ifndef OBJETOPROP_H
#define OBJETOPROP_H

#include <QGraphicsSvgItem>

#include <QGraphicsSvgItem>
#include "Diccionario.h"

class Diccionario;
class Controlador;

class ObjetoProp: public QGraphicsSvgItem
{
    private:
     QString m_nombre;
     QChar m_caracter;
     Diccionario* dic;///agrego para que tambien tenga un puntero a ese dicccionario

    public:
        ObjetoProp(QString m_nombre, Diccionario* d=Q_NULLPTR);//ahora recibe un diccionario
        ~ObjetoProp();
        void mousePressEvent(QGraphicsSceneMouseEvent * evento);
        void esconderObjeto(ObjetoProp* objeto);
        void setChar(QChar caracter);
        QChar getChar();

        ///signals slots
        ///
};

#endif // OBJETOPROP_H
