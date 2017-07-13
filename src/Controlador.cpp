#include "Controlador.h"




Controlador::Controlador(int &argc, char **argv, int flags)
    : QApplication(argc, argv, flags)
    , m_escena(nullptr)
    , m_vista(nullptr)
    , marcador(nullptr)
{
}

#include <iostream>

int Controlador::correr()
{
    //Cargar palabras
    mecanicaJuego= new MecanicaJuego();
    mecanicaJuego->cargarPalabras();

    //Elegir palabras al azar

    //Cargar las imagenes prop a la escena

    m_escena = new QGraphicsScene();
    m_vista = new Vista(m_escena);
    m_vista->insertarComponentes(m_escena);
    m_vista->show();

    /// Se agrega el teclado
    m_svgRenderer = new QSvgRenderer(QString(":/Resources/assets.svg"), this);
    teclas = new Teclas();
    teclas->agregarTeclado();
    teclas->mostrarTeclado(m_svgRenderer,m_escena);

    mecanicaJuego->seleccionarPalabrasAzar();
    mecanicaJuego->lanzarPalabra();
    return exec();
}

Controlador::~Controlador()
{
    delete m_escena;
    delete m_vista;
}
