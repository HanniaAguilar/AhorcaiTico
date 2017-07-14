#ifndef PARTESCUERPO_H
#define PARTESCUERPO_H

#include "objetoprop.h"
#include <QGraphicsScene>

class PartesCuerpo
{
    protected:
    int m_ContError;
     //QVector<QString> v_partes;

    //public:
     //QVector<ObjetoProp*> v_objetosPartes;

    public:
     PartesCuerpo();
     //void agregarPartes();
     void mostrarPartes(QSvgRenderer* svgRenderer, QGraphicsScene *escena);
     //void cargarPartes(QSvgRenderer *svgRenderer, QGraphicsScene *escena);
     //void fijarPosiciones();
};

#endif // PARTESCUERPO_H
