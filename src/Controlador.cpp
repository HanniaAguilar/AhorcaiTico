#include "Controlador.h"

Controlador::Controlador(int &argc, char **argv, int flags)
    : QApplication(argc, argv, flags)
    , m_escena(nullptr)
    , m_vista(nullptr)
    , marcador(nullptr)
{
}

int Controlador::correr()
{
    //Cargar palabras
    diccionario= new Diccionario();
    diccionario->cargarPalabras();

    m_escena = new QGraphicsScene();
    m_vista = new Vista(m_escena);
    m_escena->setSceneRect( m_vista->rect() );
    m_vista->insertarComponentes(m_escena);
    m_vista->show();

    diccionario->seleccionarPalabrasAzar();
    diccionario->lanzarPalabra();
    return exec();
}

Controlador::~Controlador()
{
    delete m_escena;
    delete m_vista;
}
