#include "Controlador.h"

Controlador::Controlador(int &argc, char **argv, int flags) //Inicializar los miembros en nulo
    : QApplication(argc, argv, flags) //Crear una aplicación
    , m_escena(Q_NULLPTR)
    , m_vista(Q_NULLPTR)
    , marcador(Q_NULLPTR)
    , diccionario(Q_NULLPTR)
{
}

int Controlador::correr()
{    
    diccionario= new Diccionario();
    diccionario->cargarPalabras(); //Cargar las palabras del diccionario en el vector

    m_escena = new QGraphicsScene(); //Crear la escena
    m_vista = new Vista(m_escena);  //Crear la vista
    m_escena->setSceneRect(m_vista->rect()); //Colocar la escena al tamaño de la vista

    m_vista->insertarComponentes(m_escena,this->diccionario);//Colocar los objetos iniciales en la vista
    m_vista->show(); //Mostrarla

    diccionario->seleccionarPalabrasAzar();//Elegir la palabra para iniciar al juego

    return exec();
}

Controlador::~Controlador() //Elimina la escena y la vista
{
    delete m_escena;
    delete m_vista;
}


