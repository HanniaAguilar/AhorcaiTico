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
    pierde->setOpacity(0); //Ocultar pierde
    gane->setOpacity(0); //Ocultar gane
    def->setOpacity(0); //Ocultar definición
    palabraMostrada=false;
}

void Aviso::mostrarPierde()
{
   pierde->setOpacity(1); //Mostrar pierde
   if(!palabraMostrada) //Mostrar la definición si no se pidió una pista anteriormente
       this->mostrarDefinicion();
}

void Aviso::mostrarGane()
{
  gane->setOpacity(1); //Mostrar gane
  if(!palabraMostrada) //Mostrar la definición si no se pidió una pista anteriormente
       this->mostrarDefinicion();
}

void Aviso::mostrarDefinicion() //Mostrar la definición en escena cuando se pide una pista, gana o pierde.
{
   //Crear el objeto con la definición en el diccionario
    def=new QGraphicsSimpleTextItem("Def: "+QString(this->m_diccionario->getDefinicion()));
    m_escena->addItem(def); //Agregarla a la escena
    def->setScale(1.5); //Tamaño de la letra
    def->setPos(405,235); //Colocar posición
    palabraMostrada=true; //Ya ha sido cargada a la escena
}

Aviso:: ~Aviso() //Destructor
{
}
