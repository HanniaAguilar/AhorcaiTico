#include "PartesCuerpo.h"
#include "objetoprop.h"

PartesCuerpo::PartesCuerpo()
{

}

void PartesCuerpo::agregarPartes()
{
    v_partes.append("cabeza");
    v_partes.append("torso");
    v_partes.append("brazoDer");
    v_partes.append("BrazoIzq");
    v_partes.append("PieDer");
    v_partes.append("PieIzq");
}



void PartesCuerpo::mostrarPartes(QSvgRenderer *svgRenderer, QGraphicsScene *escena)
{
        /// objeto temporal para cargar las partes
        ObjetoProp* temporal;

        temporal= new ObjetoProp("cabeza");
        temporal->setElementId("cabeza");
        temporal->setSharedRenderer(svgRenderer);
        temporal->setZValue(1);
       // temporal->setScale(3);
        temporal->setPos(200,105);
        escena->addItem(temporal);

        temporal= new ObjetoProp("torso");
        temporal->setElementId("torso");
        temporal->setSharedRenderer(svgRenderer);
        temporal->setZValue(1);
        //temporal->setScale(3);
        temporal->setPos(230,180);
        escena->addItem(temporal);

        temporal= new ObjetoProp("brazoDer");
        temporal->setElementId("brazoDer");
        temporal->setSharedRenderer(svgRenderer);
        temporal->setZValue(1);
        //temporal->setScale(3);
        temporal->setPos(208,195);
        escena->addItem(temporal);

        temporal= new ObjetoProp("BrazoIzq");
        temporal->setElementId("BrazoIzq");
        temporal->setSharedRenderer(svgRenderer);
        temporal->setZValue(1);
        //temporal->setScale(3);
        temporal->setPos(273,180);
        escena->addItem(temporal);

        temporal= new ObjetoProp("pieDer");
        temporal->setElementId("pieDer");
        temporal->setSharedRenderer(svgRenderer);
        temporal->setZValue(1);
        //temporal->setScale(3);
        temporal->setPos(233,236);
        escena->addItem(temporal);

        temporal= new ObjetoProp("pieIzq");
        temporal->setElementId("pieIzq");
        temporal->setSharedRenderer(svgRenderer);
        temporal->setZValue(1);
        //temporal->setScale(3);
        temporal->setPos(256,235);
        escena->addItem(temporal);
}

#include <iostream>
void PartesCuerpo::cargarPartes(QSvgRenderer *svgRenderer, QGraphicsScene *escena){
    /// objeto temporal para cargar las teclas
    ObjetoProp* temporal;

    /// ciclo que recorre el vector con los ID de cada objeto
    /// Y crea un ObjetoProp a partir de ellos.
    for(int indice=0;indice < v_partes.size();++indice){
            /// asignando propiedades a las teclas
            temporal= new ObjetoProp(v_partes[indice]);
            temporal->setElementId(v_partes[indice]);
            temporal->setSharedRenderer(svgRenderer);
            temporal->setZValue(1);
            temporal->setScale(3);
            v_objetosPartes.append(temporal);
            std::cout<<indice<<": Element loaded("<<v_partes[indice].toStdString()<<")"<<std::endl;
        }
}

void PartesCuerpo::fijarPosiciones()
{
    v_objetosPartes[0]->setPos(200,122);
    v_objetosPartes[1]->setPos(230,180);
    v_objetosPartes[2]->setPos(208,195);
    v_objetosPartes[3]->setPos(273,180);
    v_objetosPartes[4]->setPos(233,236);
    v_objetosPartes[5]->setPos(256,235);
}
