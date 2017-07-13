#include "Teclas.h"


Teclas::Teclas()
{

}

void Teclas::agregarTeclado()
{
    v_teclado.append("letraQ");
    v_teclado.append("letraw");
    v_teclado.append("letraE");
    v_teclado.append("letraR");
    v_teclado.append("letraT");
    v_teclado.append("letraY");
    v_teclado.append("letraU");
    v_teclado.append("letraI");
    v_teclado.append("letraO");
    v_teclado.append("letraP");
    v_teclado.append("letraA");
    v_teclado.append("letraS");
    v_teclado.append("letraD");
    v_teclado.append("letraF");
    v_teclado.append("letraG");
    v_teclado.append("letraH");
    v_teclado.append("letraJ");
    v_teclado.append("letraK");
    v_teclado.append("letraL");
    v_teclado.append("letraenye");
    v_teclado.append("letraZ");
    v_teclado.append("letraX");
    v_teclado.append("letraC");
    v_teclado.append("letraV");
    v_teclado.append("letraB");
    v_teclado.append("letraN");
    v_teclado.append("letraM");
}

#include <iostream>

void Teclas::mostrarTeclado(QSvgRenderer *svgRenderer, QGraphicsScene *escena)
{
    /// objeto temporal para cargar las teclas
    ObjetoProp* temporal;


    /// manejar posiciones
    int ejeX=90,ejeY=50;

    /// ciclo que recorre el vector con los ID de cada objeto
    /// Y crea un ObjetoProp a partir de ellos.
    for(int indice=0;indice < v_teclado.size();++indice){
        /// controlar las posiciones de las teclas
        if(ejeX<=800){
            ejeX+=45;
        }else{
           if(ejeX==810)
                ejeX=405+1;
           else
                ejeX=405+65;
            ejeY+=50;
        }

        /// asignando propiedades a las teclas
        ///
        temporal= new ObjetoProp(v_teclado[indice]);
        temporal->setElementId(v_teclado[indice]);
        temporal->setSharedRenderer(svgRenderer);
        temporal->setZValue(1);
        temporal->setScale(5);
        temporal->setPos(ejeX,ejeY);
        escena->addItem(temporal);
        v_objetosProp.append(temporal);
        std::cout<<indice<<": Element loaded("<<v_teclado[indice].toStdString()<<")"<<std::endl;
    }

}
