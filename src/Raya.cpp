#include "Raya.h"
#include <QColor>
#include <QFont>

Raya::Raya()
{
}

void Raya::cargarRayas(QSvgRenderer *svgRenderer, QGraphicsScene *escena)
{
    /// objeto temporal para cargar las teclas
    m_escena = escena;
    int ejeX=360,ejeY=250;
    ObjetoProp* temporal;
    for(int indice=0;indice < 12; ++indice){
            /// controlar las posiciones de las teclas
            ejeX+=45;

            /// asignando propiedades a las teclas
            temporal= new ObjetoProp("renglon");//ahora recibe un diccionario
            temporal->setSharedRenderer(svgRenderer);
            temporal->setZValue(1);
            m_escena->addItem(temporal);
            temporal->setPos(ejeX,ejeY);
            temporal->setOpacity(0);
            v_rayas.append(temporal);
            std::cout<<indice<<": Element loaded( raya )"<<std::endl;
        }
}

Raya::~Raya()
{

}

void Raya::mostrarRayas(int cantidad)
{
    for (int indice=0 ; indice < cantidad ; ++indice ){
        v_rayas[indice]->setOpacity(1);
    }
}

void Raya::ocultarRayas()
{
    for (int indice=0 ; indice < v_rayas.size() ; ++indice ){
        v_rayas[indice]->setOpacity(0);        
    }
}

void Raya::actualizarRayas(int cantidad)
{
    ocultarRayas();
    mostrarRayas(cantidad);
}

void Raya::eliminarPalabra()
{
    for (int indice=0 ; indice < v_letras.size() ; ++indice ){
        v_letras[indice]->setOpacity(0);
    }
    v_letras.clear();
}

void Raya::mostrarLetra(int pos)
{
    v_letras[pos]->setOpacity(1);
}

void Raya::colocarPalabra(QString palabra)
{
   if(!v_letras.empty())
       eliminarPalabra();

   QGraphicsSimpleTextItem* letra;
   int ejeX=360,ejeY=200;
   for(int i=0;i<palabra.length();++i){
       ejeX+=45;
       letra=new QGraphicsSimpleTextItem(QString(palabra[i]));
       m_escena->addItem(letra);
       letra->setPos(ejeX,ejeY);
       letra->setOpacity(0);
       letra->setScale(4);
       v_letras.append(letra);
   }
}
