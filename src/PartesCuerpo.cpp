#include "PartesCuerpo.h"
#include "objetoprop.h"

PartesCuerpo::PartesCuerpo() //Inicializar los miembros
    : m_ContError(0)
    , m_escena(Q_NULLPTR)
    , m_svgRenderer(Q_NULLPTR)
    , temporal(Q_NULLPTR)
{
}

PartesCuerpo::PartesCuerpo(QSvgRenderer *svgRenderer, QGraphicsScene *escena) //Inicializar con parametros
    : m_ContError(0)
    , m_escena(escena)
    , m_svgRenderer(svgRenderer)
    , temporal(nullptr)
{
}

void PartesCuerpo::agregarPartes() //Cargar los ID de las partes del cuerpo
{
    v_Partes.append("cabeza");
    v_Partes.append("torso");
    v_Partes.append("brazoDer");
    v_Partes.append("BrazoIzq");
    v_Partes.append("pieDer");
    v_Partes.append("pieIzq");   
}

void PartesCuerpo::colocarCuerpo(){ //Colocar el cuerpo en la pantalla con opacidad 0
    for(int indice=0;indice<v_Partes.size();++indice){ //Recibar el vector con las partes del cuerpo
            temporal= new ObjetoProp(v_Partes[indice]); //Crear el objetoprop que corresponde
            temporal->setSharedRenderer(m_svgRenderer); //Buscarlo en el archivo svg
            temporal->setZValue(1);
            darPos(indice); //Asignar la posición
            temporal->setOpacity(0); //Ocultar
            m_escena->addItem(temporal); //Agregar a la escena
            v_objetosPartes.append(temporal); //Agregar al vector de partes
        }
}

void PartesCuerpo::mostrarPartes()
{
    if(m_ContError>=6){ //Si ya agotó los errores se inicia otra vez
        emit perdio(); //Indicar que ha perdido        
        m_ContError=0; //Reiniciar contador de errores
    }
    else{
        v_objetosPartes[m_ContError]->setOpacity(1); //Asignar la parte del cuerpo que continua según los errores
        ++m_ContError; //Aumentar número de errores
    }
}

void PartesCuerpo::revisarEvento(bool encontrado)
{
    if(!encontrado){ //Si la palabra presionada es incorrecta, cometió un error
        mostrarPartes();
    }
}

void PartesCuerpo::quitarCuerpo()
{
    for(int indice=0; indice<v_objetosPartes.size();++indice){
        v_objetosPartes[indice]->setOpacity(0); //Ocultar todas las partes para iniciar de nuevo
    }
    m_ContError=0;
}

void PartesCuerpo::darPos(int cont){
    switch(cont){ //Asignar la posición correcta en la escena
    case 0:
     temporal->setPos(200,105);
        break;
    case 1:
     temporal->setPos(238,177);
        break;
    case 2:
     temporal->setPos(210,195);
        break;
    case 3:
     temporal->setPos(292,180);
        break;
    case 4:
     temporal->setPos(242,248);
        break;
    case 5:
     temporal->setPos(267,248);
        break;
    }
}

PartesCuerpo::~PartesCuerpo()
{

}

void PartesCuerpo::quitarVidas()
{
    std::cout<<m_ContError<<std::endl;
    mostrarPartes();
    mostrarPartes();
    std::cout<<m_ContError<<std::endl;
}

