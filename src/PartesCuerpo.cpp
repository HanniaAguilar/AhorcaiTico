#include "PartesCuerpo.h"
#include "objetoprop.h"

PartesCuerpo::PartesCuerpo()
    : m_ContError(0)
    , temporal(nullptr)
{
}

PartesCuerpo::PartesCuerpo(QSvgRenderer *svgRenderer, QGraphicsScene *escena)
    :m_ContError(0)
    ,m_escena(escena)
    ,m_svgRenderer(svgRenderer)
{
}

void PartesCuerpo::agregarPartes()
{
    v_Partes.append("cabeza");
    v_Partes.append("torso");
    v_Partes.append("brazoDer");
    v_Partes.append("BrazoIzq");
    v_Partes.append("pieDer");
    v_Partes.append("pieIzq");
    v_Partes.append("murio");
    //v_Partes.append("gano");
}

void PartesCuerpo::colocarCuerpo(){
    for(int indice=0;indice<v_Partes.size();++indice){
            temporal= new ObjetoProp(v_Partes[indice]);
            temporal->setSharedRenderer(m_svgRenderer);
            temporal->setZValue(1);
            darPos(indice);
            temporal->setOpacity(0);
            m_escena->addItem(temporal);
            v_objetosPartes.append(temporal);
        }
}

void PartesCuerpo::mostrarPartes()
{
    if(m_ContError==7){
        quitarCuerpo();
        m_ContError=0;
        emit perdio();
    }
    else{
        v_objetosPartes[m_ContError]->setOpacity(1);
        ++m_ContError;
    }
}

void PartesCuerpo::revisarEvento(bool encontrado)
{
    if(!encontrado){        
        mostrarPartes();
    }
}
/*void PartesCuerpo::dibujarGane()
{
    v_objetosPartes[7]->setOpacity(1);
}*/

void PartesCuerpo::quitarCuerpo()
{
    for(int indice=0; indice<v_objetosPartes.size();++indice){
        v_objetosPartes[indice]->setOpacity(0);
    }
}

void PartesCuerpo::darPos(int cont){
    switch(cont){
    case 0:
     temporal->setPos(200,105);
        break;
    case 1:
     temporal->setPos(238,177);
        break;
    case 2:
     temporal->setPos(210,195);
        break;
    case 3:
     temporal->setPos(292,180);
        break;
    case 4:
     temporal->setPos(242,248);
        break;
    case 5:
     temporal->setPos(267,248);
        break;
    case 6:
     temporal->setPos(5,20);
        break;
    /*case 7:
     temporal->setPos(0,0);
        break;*/
    }
}

void PartesCuerpo::esconderCuerpo()
{
    quitarCuerpo();
}
