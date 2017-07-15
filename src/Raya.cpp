#include "Raya.h"
#include <QColor>
#include <QFont>

Raya::Raya(QString caracter, QColor color, QGraphicsItem *parent)
    :QGraphicsTextItem(parent)
    ,m_caracter(caracter)
{
    setDefaultTextColor(color);
    setFont(QFont("", 12));
}


void Raya::cargarRayas(QSvgRenderer *svgRenderer, QGraphicsScene *escena)
{
    /// objeto temporal para cargar las teclas
    int ejeX=360,ejeY=250;
    ObjetoProp* temporal;
    for(int indice=0;indice < 12; ++indice){
            /// controlar las posiciones de las teclas
            ejeX+=45;

            /// asignando propiedades a las teclas
            temporal= new ObjetoProp("renglon");//ahora recibe un diccionario
            temporal->setSharedRenderer(svgRenderer);
            temporal->setZValue(1);
            escena->addItem(temporal);
            temporal->setPos(ejeX,ejeY);
            temporal->setOpacity(0);
            v_rayas.append(temporal);
            std::cout<<indice<<": Element loaded( raya )"<<std::endl;
        }
}

void Raya::actualizarCaracter(QChar caracter)
{
    setPlainText( QString("%1").arg(caracter));
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
