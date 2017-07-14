#include "PartesCuerpo.h"
#include "objetoprop.h"

PartesCuerpo::PartesCuerpo()
    :m_ContError(0)
{
}

PartesCuerpo::PartesCuerpo(QSvgRenderer *svgRenderer, QGraphicsScene *escena)
    :m_ContError(0)
    ,m_escena(escena)
    ,m_svgRenderer(svgRenderer)
{

}


void PartesCuerpo::mostrarPartes()
{

        /// objeto temporal para cargar las partes
        ObjetoProp* temporal;

        if(m_ContError==0){
            temporal= new ObjetoProp("cabeza");
            temporal->setElementId("cabeza");
            temporal->setSharedRenderer(m_svgRenderer);
            temporal->setZValue(1);
            temporal->setPos(200,105);
            m_escena->addItem(temporal);
            v_objetosPartes.push_back(temporal);
        }

        if(m_ContError==1){
            temporal= new ObjetoProp("torso");
            temporal->setElementId("torso");
            temporal->setSharedRenderer(m_svgRenderer);
            temporal->setZValue(1);
            temporal->setPos(238,177);
            m_escena->addItem(temporal);
            v_objetosPartes.push_back(temporal);
        }

        if(m_ContError==2){
            temporal= new ObjetoProp("brazoDer");
            temporal->setElementId("brazoDer");
            temporal->setSharedRenderer(m_svgRenderer);
            temporal->setZValue(1);
            temporal->setPos(210,195);
            m_escena->addItem(temporal);
            v_objetosPartes.push_back(temporal);
        }

        if(m_ContError==3){
            temporal= new ObjetoProp("BrazoIzq");
            temporal->setElementId("BrazoIzq");
            temporal->setSharedRenderer(m_svgRenderer);
            temporal->setZValue(1);
            temporal->setPos(292,180);
            m_escena->addItem(temporal);
            v_objetosPartes.push_back(temporal);
        }

        if(m_ContError==4){
            temporal= new ObjetoProp("pieDer");
            temporal->setElementId("pieDer");
            temporal->setSharedRenderer(m_svgRenderer);
            temporal->setZValue(1);
            temporal->setPos(242,248);
            m_escena->addItem(temporal);
            v_objetosPartes.push_back(temporal);
        }

        if(m_ContError==5){
            temporal= new ObjetoProp("pieIzq");
            temporal->setElementId("pieIzq");
            temporal->setSharedRenderer(m_svgRenderer);
            temporal->setZValue(1);
            temporal->setPos(267,248);
            m_escena->addItem(temporal);
            v_objetosPartes.push_back(temporal);
        }

        if(m_ContError==6){
            temporal= new ObjetoProp("murio");
            temporal->setElementId("murio");
            temporal->setSharedRenderer(m_svgRenderer);
            temporal->setZValue(1);
            temporal->setPos(5,20);
            m_escena->addItem(temporal);
            v_objetosPartes.push_back(temporal);
        }

        if(m_ContError==7){
            quitarCuerpo();
            m_ContError=-1;
            emit nuevaPalabra();
        }

        ++m_ContError;


}


void PartesCuerpo::revisarEvento(bool encontrado)
{
    if(!encontrado){
        mostrarPartes();
    }
}

void PartesCuerpo::quitarCuerpo()
{
    for(int indice=0; indice<v_objetosPartes.size();++indice){
        v_objetosPartes[indice]->setOpacity(0);
    }
}
