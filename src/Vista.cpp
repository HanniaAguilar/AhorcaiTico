#include "Raya.h"
#include "Vista.h"

#include <QMessageBox>

class ObjectoProp;
class PartesCuerpo;
class Aviso;

Vista::Vista(QGraphicsScene *escena) //Inicializar componentes
    :QGraphicsView(escena)
    ,m_svgRenderer(Q_NULLPTR)
    ,m_fondo(Q_NULLPTR)
    ,teclas (Q_NULLPTR)
    ,m_marcador(Q_NULLPTR)
    ,cuerpo(Q_NULLPTR)
    ,rayas(Q_NULLPTR)
    ,aviso(Q_NULLPTR)
{
  #if ! defined(Q_OS_ANDROID)
    resize(960, 540); //Redimensionar la vista
  #endif
}

void Vista::insertarComponentes(QGraphicsScene* m_escena,Diccionario* diccionario)
{
    m_svgRenderer = new QSvgRenderer(QString(":/Resources/assets.svg"), this); //Cargar el svg

    this->dibujeFondo(m_escena); //Dibujar el fondo
    //Configurar la vista, color y posiciones
    this->setBackgroundBrush(QBrush(Qt::white, Qt::SolidPattern));
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Se agrega el teclado
    teclas = new Teclas(diccionario);
    teclas->agregarTeclado(); //Cargar teclas del svg
    teclas->cargarTeclado(m_svgRenderer,m_escena); //Mostrar en la escena

    //Se agrega el marcador
    m_marcador = new Marcador("Puntos",0,Qt::black);  //Color y título
    m_marcador->setPos(680,50);
    m_escena->addItem(m_marcador); //Se coloca en la escena en la posición correspondiente

    //Se agregan las rayas
    rayas= new Raya(diccionario);
    rayas->cargarRayas(m_svgRenderer,m_escena);  //Cargarlas del svg y colocar en opacidad 0

    //Se agrega el cuerpo
    cuerpo = new PartesCuerpo(m_svgRenderer, m_escena);
    cuerpo->agregarPartes(); //Se cargan las partes del svg
    cuerpo->colocarCuerpo(); //Se colocan en la escena con opacidad 0

    //Avisos de gane o pierda
    aviso=new Aviso(m_svgRenderer, m_escena,diccionario);
    aviso->colocarObjetos();

    //Pistas (Mostrar definiciones)
    pista=new Pista(m_svgRenderer, m_escena,diccionario);
    pista->cargar(); //Obtener el icono
    pista->mostrarPista(); //Mostrar icono

    //Se conectan eventos

    //Revisar si la palabra presionada es correcta
    QObject::connect(diccionario,SIGNAL(clickLetra(bool)),cuerpo,SLOT(revisarEvento(bool)));
    //Verificar si ha encontrado todas las letras de la palabra
    QObject::connect(diccionario,SIGNAL(nuevoCaracterEncontrado()),diccionario,SLOT(verificarGane()));
    //Mostrar la letra descubierta
    QObject::connect(diccionario,SIGNAL(escribaLetra(int)),rayas,SLOT(mostrarLetra(int)));
    //Si se encuentra la palabra, colocar otra nueva palabra
    QObject::connect(diccionario,SIGNAL(escribePalabra(QString)),rayas,SLOT(colocarPalabra(QString)));
    //Indicar el gane
    QObject::connect(diccionario,SIGNAL(palabraEcontrada()),m_marcador,SLOT(incrementePuntos()));
    //Mostrar el icono de gano
    QObject::connect(diccionario,SIGNAL(palabraEcontrada()),aviso,SLOT(mostrarGane()));
    //Si gana, reinicia de nuevo si lo desea
    QObject::connect(diccionario,SIGNAL(reiniciarJuego()),cuerpo,SLOT(quitarCuerpo()));
    //Colocar todas las teclas de nuevo
    QObject::connect(diccionario,SIGNAL(reiniciarJuego()),teclas,SLOT(restablecerTeclado()));
    //Quitar pista y objetos de gane o pierda
    QObject::connect(diccionario,SIGNAL(reiniciarJuego()),aviso,SLOT(quitarObjetos()));
    //Colocar nueva cantidad de rayas
    QObject::connect(diccionario,SIGNAL(dibujeRayas(int)),rayas,SLOT(actualizarRayas(int)));
    //Si pierde, reinicia de nuevo si lo desea
    QObject::connect(cuerpo,SIGNAL(perdio()),diccionario,SLOT(bloquearTeclado()));
    //Mostar la palabra que se debía descubrir
    QObject::connect(cuerpo,SIGNAL(perdio()),rayas,SLOT(mostrarPalabra()));
    //Mostrar icono de pierde
    QObject::connect(cuerpo,SIGNAL(perdio()),aviso,SLOT(mostrarPierde()));
    //Colocar todas lasteclas de nuevo
    QObject::connect(cuerpo,SIGNAL(perdio()),teclas,SLOT(restablecerTeclado()));    
    //Esconder el icono de la pista si pierde
    QObject::connect(cuerpo,SIGNAL(perdio()),pista,SLOT(ocultarPista()));
    //Esconder el icono de la pista si gana
    QObject::connect(diccionario,SIGNAL(palabraEcontrada()),pista,SLOT(ocultarPista()));
    //Mostra la definición cuando gana
    QObject::connect(diccionario,SIGNAL(reiniciarJuego()),pista,SLOT(mostrarPista()));
    //Colocar partes en el cuerpo si pide ayuda
    QObject::connect(diccionario,SIGNAL(quiteVidas()),cuerpo,SLOT(quitarVidas()));
    //Mostrar la ayuda (pista) solicitada, en una ventana
    QObject::connect(diccionario,SIGNAL(mostrarAyuda(QString)),pista,SLOT(mostrarAyuda(QString)));
    //Mostrar la definición en la escena cuando pide ayuda
    QObject::connect(diccionario,SIGNAL(mostrarAyuda(QString)),aviso,SLOT(mostrarDefinicion()));
    //conexion de la instruccion
    QObject::connect(diccionario,SIGNAL(muestreInstrucciones()),pista,SLOT(mostrarInstrucciones()));
}

void Vista::dibujeFondo (QGraphicsScene* m_escena){
     m_fondo = new ObjetoProp("fondo"); //Buscar fondo en el svg
     m_fondo->setSharedRenderer(m_svgRenderer);
     m_fondo->setPos(45,35); //Asignar posición
     m_escena->addItem(m_fondo); //Agregar a la escena
     m_fondo->setZValue(-1);
}

Vista::~Vista()
{

}
