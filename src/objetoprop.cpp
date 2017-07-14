#include "objetoprop.h"

ObjetoProp::ObjetoProp(QString nombre,Diccionario* d)//ahora recibe un diccionario
    :m_nombre(nombre)
    ,diccionario(d)//ahora recibe un diccionario
{
    setElementId(nombre);
}


ObjetoProp::~ObjetoProp()
{
}

#include <iostream>
void ObjetoProp::mousePressEvent(QGraphicsSceneMouseEvent *evento)
{
    /*if(this->elementId()=="letraQ")
    {
       std::cout<<"TOUCHED("<<this->elementId().toStdString()<<")"<<std::endl;
    }
    if(this->elementId()=="letraw")
    {
       std::cout<<"TOUCHED("<<this->elementId().toStdString()<<")"<<std::endl;
    }
    if(this->elementId()=="letraE")
    {
       std::cout<<"TOUCHED("<<this->elementId().toStdString()<<")"<<std::endl;
    }
    if(this->elementId()=="letraR")
    {
       std::cout<<"TOUCHED("<<this->elementId().toStdString()<<")"<<std::endl;
    }
    if(this->elementId()=="letraT")
    {
       std::cout<<"TOUCHED("<<this->elementId().toStdString()<<")"<<std::endl;
    }
    if(this->elementId()=="letraY")
    {
       std::cout<<"TOUCHED("<<this->elementId().toStdString()<<")"<<std::endl;
    }
    if(this->elementId()=="letraU")
    {
       std::cout<<"TOUCHED("<<this->elementId().toStdString()<<")"<<std::endl;
    }
    if(this->elementId()=="letraI")
    {
       std::cout<<"TOUCHED("<<this->elementId().toStdString()<<")"<<std::endl;
    }
    if(this->elementId()=="letraO")
    {
       std::cout<<"TOUCHED("<<this->elementId().toStdString()<<")"<<std::endl;
    }
    if(this->elementId()=="letraP")
    {
       std::cout<<"TOUCHED("<<this->elementId().toStdString()<<")"<<std::endl;
    }
    if(this->elementId()=="letraA")
    {
       std::cout<<"TOUCHED("<<this->elementId().toStdString()<<")"<<std::endl;
    }
    if(this->elementId()=="letraS")
    {
       std::cout<<"TOUCHED("<<this->elementId().toStdString()<<")"<<std::endl;
    }
    if(this->elementId()=="letraD")
    {
       std::cout<<"TOUCHED("<<this->elementId().toStdString()<<")"<<std::endl;
    }
    if(this->elementId()=="letraF")
    {
       std::cout<<"TOUCHED("<<this->elementId().toStdString()<<")"<<std::endl;
    }
    if(this->elementId()=="letraG")
    {
       std::cout<<"TOUCHED("<<this->elementId().toStdString()<<")"<<std::endl;
    }
    if(this->elementId()=="letraH")
    {
       std::cout<<"TOUCHED("<<this->elementId().toStdString()<<")"<<std::endl;
    }
    if(this->elementId()=="letraJ")
    {
       std::cout<<"TOUCHED("<<this->elementId().toStdString()<<")"<<std::endl;
    }
    if(this->elementId()=="letraK")
    {
       std::cout<<"TOUCHED("<<this->elementId().toStdString()<<")"<<std::endl;
    }
    if(this->elementId()=="letraL")
    {
       std::cout<<"TOUCHED("<<this->elementId().toStdString()<<")"<<std::endl;
    }
    if(this->elementId()=="letraEnye")
    {
       std::cout<<"TOUCHED("<<this->elementId().toStdString()<<")"<<std::endl;
    }
    if(this->elementId()=="letraZ")
    {
       std::cout<<"TOUCHED("<<this->elementId().toStdString()<<")"<<std::endl;
    }
    if(this->elementId()=="letraX")
    {
       std::cout<<"TOUCHED("<<this->elementId().toStdString()<<")"<<std::endl;
    }
    if(this->elementId()=="letraC")
    {
       std::cout<<"TOUCHED("<<this->elementId().toStdString()<<")"<<std::endl;
    }
    if(this->elementId()=="letraV")
    {
       std::cout<<"TOUCHED("<<this->elementId().toStdString()<<")"<<std::endl;
    }
    if(this->elementId()=="letraB")
    {
       std::cout<<"TOUCHED("<<this->elementId().toStdString()<<")"<<std::endl;
    }
    if(this->elementId()=="letraN")
    {
       std::cout<<"TOUCHED("<<this->elementId().toStdString()<<")"<<std::endl;
    }
    if(this->elementId()=="letraM")
    {
       std::cout<<"TOUCHED("<<this->elementId().toStdString()<<")"<<std::endl;
    }*/
    //std::cout<<this->getChar()<<std::endl;
    //this->setPos(-100,-100);
    std::cout<<"TOUCHED("<<this->elementId().toStdString()<<")"<<std::endl;
    if(this->elementId()!="fondo"&&this->elementId()!="cabeza"&&this->elementId()!="torso"
            &&this->elementId()!="brazoDer"&&this->elementId()!="BrazoIzq"&&this->elementId()!="pieIzq"
            &&this->elementId()!="pieDer")
    {
        this->setOpacity(0.0);
        this->diccionario->buscarCaracter(this->getChar());
    }


    //aqui es donde es de utilidad el puntero, porque puedo hacer esto:



}

void ObjetoProp::setChar(QChar caracter)
{
    m_caracter=caracter;
}

QChar ObjetoProp::getChar()
{
    return m_caracter;
}
