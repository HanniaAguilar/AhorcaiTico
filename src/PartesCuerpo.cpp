#include "PartesCuerpo.h"
#include "objetoprop.h"

PartesCuerpo::PartesCuerpo()
    :m_ContError(0)
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

void PartesCuerpo::mostrarPartes(QSvgRenderer *svgRenderer, QGraphicsScene *escena)
{

        /// objeto temporal para cargar las partes
        ObjetoProp* temporal;

        if(m_ContError==0){
            temporal= new ObjetoProp("cabeza");
            temporal->setElementId("cabeza");
            temporal->setSharedRenderer(svgRenderer);
            temporal->setZValue(1);
            temporal->setPos(200,105);
            escena->addItem(temporal);
        }

        if(m_ContError==1){
            temporal= new ObjetoProp("torso");
            temporal->setElementId("torso");
            temporal->setSharedRenderer(svgRenderer);
            temporal->setZValue(1);
            temporal->setPos(238,177);
            escena->addItem(temporal);
        }

        if(m_ContError==2){
            temporal= new ObjetoProp("brazoDer");
            temporal->setElementId("brazoDer");
            temporal->setSharedRenderer(svgRenderer);
            temporal->setZValue(1);
            temporal->setPos(210,195);
            escena->addItem(temporal);
        }

        if(m_ContError==3){
            temporal= new ObjetoProp("BrazoIzq");
            temporal->setElementId("BrazoIzq");
            temporal->setSharedRenderer(svgRenderer);
            temporal->setZValue(1);
            temporal->setPos(292,180);
            escena->addItem(temporal);
        }

        if(m_ContError==4){
            temporal= new ObjetoProp("pieDer");
            temporal->setElementId("pieDer");
            temporal->setSharedRenderer(svgRenderer);
            temporal->setZValue(1);
            temporal->setPos(242,248);
            escena->addItem(temporal);
        }

        if(m_ContError==5){
            temporal= new ObjetoProp("pieIzq");
            temporal->setElementId("pieIzq");
            temporal->setSharedRenderer(svgRenderer);
            temporal->setZValue(1);
            temporal->setPos(267,248);
            escena->addItem(temporal);
        }

        ++m_ContError;
}

/*#include <iostream>
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
    v_objetosPartes[0]->setPos(200,105);
    v_objetosPartes[1]->setPos(238,177);
    v_objetosPartes[2]->setPos(210,195);
    v_objetosPartes[3]->setPos(292,180);
    v_objetosPartes[4]->setPos(242,248);
    v_objetosPartes[5]->setPos(267,248);
}
*/
