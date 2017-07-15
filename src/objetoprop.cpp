#include "objetoprop.h"

ObjetoProp::ObjetoProp(QString nombre,Diccionario* d)
    :m_nombre(nombre)
    ,diccionario(d)
{
    setElementId(nombre);
}

#include <iostream>
void ObjetoProp::mousePressEvent(QGraphicsSceneMouseEvent *evento)
{
    std::cout<<"TOUCHED("<<this->elementId().toStdString()<<")"<<std::endl;
    if(this->elementId()!="fondo"&&this->elementId()!="cabeza"&&this->elementId()!="torso"
            &&this->elementId()!="brazoDer"&&this->elementId()!="BrazoIzq"&&this->elementId()!="pieIzq"
            &&this->elementId()!="pieDer"&&this->elementId()!="murio")
    {
        this->setOpacity(0.0);
        this->diccionario->buscarCaracter(this->getChar());
    }
    if(this->elementId()=="murio"){
        this->setOpacity(0.0);
    }
    if(this->elementId()=="gano"){
        this->setPos(-10,-10);
    }
}

void ObjetoProp::setChar(QChar caracter)
{
    m_caracter=caracter;
}

QChar ObjetoProp::getChar()
{
    return m_caracter;
}

ObjetoProp::~ObjetoProp()
{

}
