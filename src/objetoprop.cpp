#include "objetoprop.h"

ObjetoProp::ObjetoProp(QString m_nombre,Diccionario* dic)
    :diccionario(dic)
{
    setElementId(m_nombre); //Asignar el ID del elemento
}

#include <iostream>
void ObjetoProp::mousePressEvent(QGraphicsSceneMouseEvent *evento)
{
    // para evitar el warning de no usado por el compilador
    (void)evento;
    Q_UNUSED(evento);

   //Reacción de las teclas al tocarlas
    if(this->elementId()!="fondo"&&this->elementId()!="cabeza"&&this->elementId()!="torso"
            &&this->elementId()!="brazoDer"&&this->elementId()!="BrazoIzq"&&this->elementId()!="pieIzq"
            &&this->elementId()!="pieDer"&&this->elementId()!="murio"&&this->elementId()!="gano"
            &&this->elementId()!="renglon"&&this->elementId()!="ayuda"&&this->elementId()!="instruccion"
            &&(this->diccionario->getReaccionar())==true)
    {
        this->setOpacity(0.0); //Desaparecen
        this->diccionario->buscarCaracter(this->getChar()); //Se busca esa letra en la palabra a adivinar
    }

    if(this->elementId()=="murio"){        
        this->diccionario->seleccionarPalabrasAzar(); //Una nueva palabra
        this->diccionario->setReaccionar(true); //Bloquear el teclado
        emit this->diccionario->reiniciarJuego(); //Iniciar otra palabra
    }
    if(this->elementId()=="gano"){        
        this->diccionario->seleccionarPalabrasAzar(); //Una nueva palabra
        this->diccionario->setReaccionar(true); //Bloquear el teclado
        emit this->diccionario->reiniciarJuego(); //Iniciar otra palabra
    }
    if(this->elementId()=="ayuda"){
        emit this->diccionario->mostrarAyuda(diccionario->getDefinicion()); //Mostrar ayuda
        emit this->diccionario->quiteVidas(); //Quitar dos vidas (Colocar dos partes del cuerpo)
    }
    if(this->elementId()=="instruccion"){
        emit this->diccionario->muestreInstrucciones();        
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
