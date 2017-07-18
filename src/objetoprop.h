#ifndef OBJETOPROP_H
#define OBJETOPROP_H

#include <QGraphicsSvgItem>

#include "Controlador.h"
#include "Diccionario.h"

class ObjetoProp: public QGraphicsSvgItem
{
    private:     
     QChar m_caracter; //Char asignados a cada letra     
     Diccionario* diccionario; //Diccionario del juego

    public:
        ObjetoProp(QString m_nombre, Diccionario* dic=Q_NULLPTR); //Constructor
        ~ObjetoProp(); //Destructor
        void mousePressEvent(QGraphicsSceneMouseEvent * evento); //Evento de click en algun objeto prop
        void setChar(QChar caracter); //Asigna un caracter a los objetos prop de teclas
        QChar getChar(); //Indica a cual caracter corresponde la letra
};

#endif // OBJETOPROP_H
