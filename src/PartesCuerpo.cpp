#include "partescuerpo.h"
#include "objetoprop.h"

PartesCuerpo::PartesCuerpo()
{

}

/*void PartesCuerpo::agregarPartes()
{
    v_partes.append("cabeza");
    v_partes.append("torso");
    v_partes.append("brazoDer");
    v_partes.append("BrazoIzq");
    v_partes.append("PieDer");
    v_partes.append("PieIzq");

}*/

#include <iostream>

void PartesCuerpo::mostrarPartes(QSvgRenderer *svgRenderer, QGraphicsScene *escena)
{
        /// objeto temporal para cargar las partes
        ObjetoProp* temporal;

        temporal= new ObjetoProp("cabeza");
        temporal->setElementId("cabeza");
        temporal->setSharedRenderer(svgRenderer);
        temporal->setZValue(1);
        temporal->setScale(3);
        temporal->setPos(200,122);
        escena->addItem(temporal);

        temporal= new ObjetoProp("torso");
        temporal->setElementId("torso");
        temporal->setSharedRenderer(svgRenderer);
        temporal->setZValue(1);
        temporal->setScale(3);
        temporal->setPos(230,180);
        escena->addItem(temporal);

        temporal= new ObjetoProp("brazoDer");
        temporal->setElementId("brazoDer");
        temporal->setSharedRenderer(svgRenderer);
        temporal->setZValue(1);
        temporal->setScale(3);
        temporal->setPos(208,195);
        escena->addItem(temporal);

        temporal= new ObjetoProp("BrazoIzq");
        temporal->setElementId("BrazoIzq");
        temporal->setSharedRenderer(svgRenderer);
        temporal->setZValue(1);
        temporal->setScale(3);
        temporal->setPos(273,180);
        escena->addItem(temporal);

        temporal= new ObjetoProp("pieDer");
        temporal->setElementId("pieDer");
        temporal->setSharedRenderer(svgRenderer);
        temporal->setZValue(1);
        temporal->setScale(3);
        temporal->setPos(233,236);
        escena->addItem(temporal);

        temporal= new ObjetoProp("pieIzq");
        temporal->setElementId("pieIzq");
        temporal->setSharedRenderer(svgRenderer);
        temporal->setZValue(1);
        temporal->setScale(3);
        temporal->setPos(256,235);
        escena->addItem(temporal);
}
