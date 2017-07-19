#include "Pista.h"

Pista::Pista(QSvgRenderer* svgRenderer, QGraphicsScene *escena, Diccionario* diccionario)
    :m_renderer(svgRenderer)
    ,m_escena(escena)
    ,diccionario(diccionario)
    ,m_contadorError(0)
{
}

Pista::~Pista()
{
}

//carga la imagen
void Pista::cargar()
{
    o_pista= new ObjetoProp("Ayuda");
    o_pista->setSharedRenderer(m_renderer);
    o_pista->setZValue(1);
    o_pista->setPos(410,20);
    o_pista->setOpacity(0);
    m_escena->addItem(o_pista);
}

//muestra el icono de la pista
void Pista::mostrarPista()
{
    o_pista->setOpacity(1);
}

// oculta la imagen de la pista
void Pista::ocultarPista()
{
    o_pista->setOpacity(0);
    m_contadorError=0;
}

// se verifica que aun tenga vidas para poder solicitar la pista
/*void Pista::puedeTocar()
{
    if(m_contadorError>=6)
        ocultarPista();
}

#include <iostream>
void Pista::aumenteContError(bool encontrada)
{
    std::cout<<m_contadorError<<std::endl;
    if(!encontrada){
        ++m_contadorError;
        std::cout<<m_contadorError<<std::endl;
    }

    puedeTocar();
}*/
