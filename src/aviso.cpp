#include "Aviso.h"

Aviso:: Aviso(QSvgRenderer* svgRenderer, QGraphicsScene *escena) //Inicializar los miembros
    :m_svgRenderer(svgRenderer)
    ,m_escena(escena)
{
}

void Aviso::colocarObjetos()
{
    pierde= new ObjetoProp("murio"); //Crear el objetoprop que corresponde
    pierde->setSharedRenderer(m_svgRenderer); //Buscarlo en el archivo svg
    pierde->setZValue(1);
    pierde->setPos(370,30); //Asignar la posición
    pierde->setOpacity(0); //Ocultar
    m_escena->addItem(pierde); //Agregar a la escena

    gane= new ObjetoProp("gano"); //Crear el objetoprop que corresponde
    gane->setSharedRenderer(m_svgRenderer); //Buscarlo en el archivo svg
    gane->setZValue(1);
    gane->setPos(370,10); //Asignar la posición
    gane->setOpacity(0); //Ocultar
    m_escena->addItem(gane); //Agregar a la escena
}

void Aviso::quitarObjetos()
{
    pierde->setOpacity(0); //Ocultar
    gane->setOpacity(0); //Ocultar
}

void Aviso::mostrarPierde()
{
   pierde->setOpacity(1); //Ocultar
}

void Aviso::mostrarGane()
{
  gane->setOpacity(1); //Ocultar
}

Aviso:: ~Aviso() //Destructor
{
}
