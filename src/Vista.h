#ifndef VISTA_H
#define VISTA_H

#include "vista.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QSvgRenderer>
#include "objetoprop.h"
#include "teclas.h"


class Controlador;

class Vista:public QGraphicsView
{

    protected:
      ObjetoProp* m_componente;
      QSvgRenderer* m_svgRenderer;
      ObjetoProp* m_fondo;
      Teclas* teclas;

    public:
        Vista(QGraphicsScene* escena);
        ~Vista();
        void insertarComponentes(QGraphicsScene* escena);
        void dibujeFondo(QGraphicsScene* m_escena);
};

#endif // VISTA_H
