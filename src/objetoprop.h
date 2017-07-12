#ifndef OBJETOPROP_H
#define OBJETOPROP_H

#include <QGraphicsSvgItem>


class Controlador;

class ObjetoProp: public QGraphicsSvgItem
{
    private:
     QString nombre;

    public:
        ObjetoProp(QString nombre);
        ~ObjetoProp();
        void mousePressEvent(QGraphicsSceneMouseEvent * evento);
};
#endif // OBJETOPROP_H
