#ifndef VISTA_H
#define VISTA_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QSvgRenderer>

#include "Aviso.h"
#include "Controlador.h"
#include "marcador.h"
#include "objetoprop.h"
#include "PartesCuerpo.h"
#include "Raya.h"
#include "Teclas.h"
#include "Pista.h"

class Aviso;
class ObjetoProp;
class Teclas;
class PartesCuerpo;
class Raya;
class Pista;

class Vista:public QGraphicsView
{
    protected:      
      QSvgRenderer* m_svgRenderer; //Archivo svg en Resources
      ObjetoProp* m_fondo; //ObjetoProp ara el fondo
      Teclas* teclas; //Guardar una instancia del teclado
      Marcador* m_marcador; //Guardar una instancia del marcado
      PartesCuerpo* cuerpo; //Guardar una instancia del cuerpo
      Raya* rayas; //Guardar una instancia de las rayas
      Aviso* aviso;// Puntero de aviso
      Pista* pista;//puntero de pista


    public:
        Vista(QGraphicsScene* escena); //Constructor
        ~Vista(); //Destructor
        void insertarComponentes(QGraphicsScene* escena, Diccionario* diccionario); //Insertar los componentes necesarios a la escena
        void dibujeFondo(QGraphicsScene* m_escena); //Dibujar el fondo para la vista
};

#endif // VISTA_H
