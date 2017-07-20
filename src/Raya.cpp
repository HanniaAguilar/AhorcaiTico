#include "Raya.h"

Raya::Raya(Diccionario* diccionario)
    :m_diccionario(diccionario)
{
}

void Raya::cargarRayas(QSvgRenderer *svgRenderer, QGraphicsScene *escena)
{    
    m_escena = escena; //Escena en la cual se cargan las rayas
    int ejeX=360,ejeY=250; //Posiciones de la rayas
    ObjetoProp* temporal; // objeto temporal para cargar las teclas
    for(int indice=0;indice < 12; ++indice){ //Número de rayas a dibujar en la escena
            ejeX+=45; // controlar las posiciones de las teclas
            temporal= new ObjetoProp("renglon");  //buscar en el svg
            temporal->setSharedRenderer(svgRenderer);
            temporal->setZValue(1);            
            temporal->setPos(ejeX,ejeY); //Asiganr la posición
            temporal->setOpacity(0); //Ocultar
            m_escena->addItem(temporal); //Agregar a la escena
            v_rayas.append(temporal); //Agregar en los objetoProp
            /*Eliminar este cout*/
            std::cout<<indice<<": Element loaded( raya )"<<std::endl;
        }
}

Raya::~Raya()
{

}

void Raya::actualizarRayas(int cantidad)
{
    for (int indice=0 ; indice < v_rayas.size() ; ++indice ){ //Colocar todos en 0
        v_rayas[indice]->setOpacity(0);
    }
    for (int indice=0 ; indice < cantidad ; ++indice ){ //Asignar la rayas para la nueva palabra
        v_rayas[indice]->setOpacity(1);
    }
}

void Raya::eliminarPalabra()
{
    for (int indice=0 ; indice < v_letras.size() ; ++indice ){ //Eliminar las letras de la palabra anterior
        v_letras[indice]->setOpacity(0);
    }
    v_letras.clear(); //Limpiar el vector con la palabra anterior  
}

void Raya::mostrarLetra(int pos)
{
    v_letras[pos]->setOpacity(1); //Mostrar la letra acertada en la posición correspondiente
}

void Raya::colocarPalabra(QString palabra)
{
   if(!v_letras.empty()) //Limpiar el vector con la palabra sino lo está.
       eliminarPalabra();

   QGraphicsSimpleTextItem* letra; //Crear el objeto de texto para letras
   int ejeX=360,ejeY=180; //Asignar posición a los caracteres en la escena
   for(int i=0;i<palabra.length();++i){ //Escribir toda la palabra
       ejeX+=45; //Controlar la posición de cada una
       letra=new QGraphicsSimpleTextItem(QString(palabra[i]));
       m_escena->addItem(letra); //Agregarla a la escena
       letra->setPos(ejeX,ejeY); //Asignar posición
       letra->setOpacity(0); //Con opacidad 0
       letra->setScale(4); //Aumentar el tamaño
       v_letras.append(letra); //Agregar al vector con los objetos de cada caracter.
   }
}

void Raya::mostrarPalabra()
{
    for(int indice=0 ; indice<v_letras.length() ; ++indice)
    {
        v_letras[indice]->setOpacity(1);
    }
}
