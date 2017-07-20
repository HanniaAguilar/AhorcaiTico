#include "Aviso.h"

Aviso:: Aviso(QSvgRenderer* svgRenderer, QGraphicsScene *escena, Diccionario* diccionario) //Inicializar los miembros
    :m_svgRenderer(svgRenderer)
    ,m_escena(escena)\
    ,m_diccionario(diccionario)
    ,palabraMostrada(false)
{
}

void Aviso::colocarObjetos()
{
    pierde= new ObjetoProp("murio", m_diccionario); //Crear el objetoprop que corresponde
    pierde->setSharedRenderer(m_svgRenderer); //Buscarlo en el archivo svg
    pierde->setZValue(1);
    pierde->setPos(20,40); //Asignar la posición
    pierde->setOpacity(0); //Ocultar
    m_escena->addItem(pierde); //Agregar a la escena

    gane= new ObjetoProp("gano",m_diccionario); //Crear el objetoprop que corresponde
    gane->setSharedRenderer(m_svgRenderer); //Buscarlo en el archivo svg
    gane->setZValue(1);
    gane->setPos(20,10); //Asignar la posición
    gane->setOpacity(0); //Ocultar
    m_escena->addItem(gane); //Agregar a la escena    
}

void Aviso::quitarObjetos()
{
    pierde->setOpacity(0); //Ocultar
    gane->setOpacity(0); //Ocultar
    def->setOpacity(0);
    palabraMostrada=false;
}

void Aviso::mostrarPierde()
{
   pierde->setOpacity(1);
   if(!palabraMostrada)
       this->mostrarDefinicion();
}

void Aviso::mostrarGane()
{
  gane->setOpacity(1);
  if(!palabraMostrada)
       this->mostrarDefinicion();
}

void Aviso::mostrarDefinicion()
{
    def=new QGraphicsSimpleTextItem("Def: "+QString(this->m_diccionario->m_definicion));
    m_escena->addItem(def); //Agregarla a la escena
    def->setScale(2);
    def->setPos(400,150);
    palabraMostrada=true;
}

void Aviso::cargarDefinicion()
{
   /* def=new QGraphicsSimpleTextItem("Def: "+QString(this->m_diccionario->m_definicion));
    m_escena->addItem(def); //Agregarla a la escena
    def->setScale(2);
    def->setOpacity(0);
    def->setPos(400,150);*/
}

Aviso:: ~Aviso() //Destructor
{
}
