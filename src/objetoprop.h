#ifndef OBJETOPROP_H
#define OBJETOPROP_H

#include <QGraphicsSvgItem>

class MecanicaJuego;
class Controlador;

class ObjetoProp: public QGraphicsSvgItem
{
    private:
     QString m_nombre;
     QChar m_caracter;

    public:
        ObjetoProp(QString m_nombre);
        ~ObjetoProp();
        void mousePressEvent(QGraphicsSceneMouseEvent * evento);
        void esconderObjeto(ObjetoProp* objeto);
        void setChar(QChar caracter);
        QChar getChar();

        ///signals slots
        ///
};

#endif // OBJETOPROP_H
