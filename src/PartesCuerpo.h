#ifndef PARTESCUERPO_H
#define PARTESCUERPO_H

#include "objetoprop.h"
#include <QGraphicsScene>

class PartesCuerpo
{
    protected:
     //QVector<QString> v_partes;

    public:
     //QVector<ObjetoProp*> v_objetosProp;

    public:
     PartesCuerpo();
     //void agregarPartes();
     void mostrarPartes(QSvgRenderer* svgRenderer, QGraphicsScene *escena);
};

#endif // PARTESCUERPO_H
