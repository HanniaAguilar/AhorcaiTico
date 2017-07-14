#ifndef VISTA_H
#define VISTA_H

#include "Vista.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QSvgRenderer>
#include "objetoprop.h"
#include "Teclas.h"
#include "marcador.h"
#include "PartesCuerpo.h"
#include "Raya.h"

class Controlador;

class Vista:public QGraphicsView
{
    protected:      
      QSvgRenderer* m_svgRenderer;
      ObjetoProp* m_fondo;
      Teclas* teclas;
      Marcador* m_marcador;
      PartesCuerpo* cuerpo;
      Raya* rayas;

    public:
        Vista(QGraphicsScene* escena);
        ~Vista();
        void insertarComponentes(QGraphicsScene* escena, Diccionario* diccionario);
        void dibujeFondo(QGraphicsScene* m_escena);
};

#endif // VISTA_H
