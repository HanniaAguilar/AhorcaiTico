#include "Controlador.h"

Controlador::Controlador(int &argc, char **argv, int flags)
    : QApplication(argc, argv, flags)
    , m_escena(nullptr)
    , m_vista(nullptr)
{
}

#include <iostream>

int Controlador::correr()
{
    //Cargar palabras
    
    //Elegir palabras al azar
    
    //Cargar las imagenes prop a la escena
        
    m_escena = new QGraphicsScene();
    m_vista = new MainWindow(m_escena);
    m_vista->insertarComponentes(m_escena);
    m_vista->show();
    
    //Crear un ciclo para jugar (Quiza se deba crear otro separado de este metodo) 
    return exec();
}

Controlador::~Controlador()
{
    delete m_escena;
    delete m_vista;
}
