#include "objetoprop.h"

ObjetoProp::ObjetoProp(QString m_nombre,Diccionario* dic)
    :diccionario(dic)
{
    setElementId(m_nombre); //Asignar el ID del elemento
}

#include <iostream>
void ObjetoProp::mousePressEvent(QGraphicsSceneMouseEvent *evento)
{
   /*Eliminar este cout*/
   std::cout<<"TOUCHED("<<this->elementId().toStdString()<<")"<<std::endl;

   //Reacción de las teclas al tocarlas
    if(this->elementId()!="fondo"&&this->elementId()!="cabeza"&&this->elementId()!="torso"
            &&this->elementId()!="brazoDer"&&this->elementId()!="BrazoIzq"&&this->elementId()!="pieIzq"
            &&this->elementId()!="pieDer"&&this->elementId()!="murio"&&this->elementId()!="gano"
            &&this->elementId()!="renglon"&&this->elementId()!="Ayuda"&&this->diccionario->reaccione==true)
    {
        this->setOpacity(0.0); //Desaparecen
        this->diccionario->buscarCaracter(this->getChar()); //Se busca esa letra en la palabra a adivinar
    }

    if(this->elementId()=="murio"){
        this->setOpacity(0.0); //Cuando toca el de perder se inicia con una nueva palabra
        this->diccionario->seleccionarPalabrasAzar();
        this->diccionario->reaccione=true;
        emit this->diccionario->reiniciarJuego();
    }
    if(this->elementId()=="gano"){
        this->setOpacity(0.0); //Cuando toca el de ganar se inicia con una nueva palabra
        this->diccionario->seleccionarPalabrasAzar();
        this->diccionario->reaccione=true;
        emit this->diccionario->reiniciarJuego();
    }
    if(this->elementId()=="Ayuda"){
        this->setOpacity(0.0); //Cuando toca el de ganar se inicia con una nueva palabra
        //this->diccionario->reaccione=true;
        emit this->diccionario->quiteVidas();
        emit this->diccionario->mostrarAyuda(diccionario->getDefinicion());
        /*Aun no funciona arreglar*/
    }
}

void ObjetoProp::setChar(QChar caracter)
{
    m_caracter=caracter; //Se asigna un caracter a las teclas
}

QChar ObjetoProp::getChar()
{
    return m_caracter; //Se indica el caracter al que corresponden las teclas
}

ObjetoProp::~ObjetoProp()
{

}
