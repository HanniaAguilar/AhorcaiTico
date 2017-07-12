#include "ObjetoProp.h"

ObjetoProp::ObjetoProp(QString nombre)
    :nombre(nombre)
{
}


ObjetoProp::~ObjetoProp()
{
}

void ObjetoProp::mousePressEvent(QGraphicsSceneMouseEvent *evento)
{
    if(this->elementId()=="horca")
       {
        //std::cout<<"TOUCHED("<<this->elementId().toStdString()<<")"<<std::endl;
       }
}

