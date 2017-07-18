#include "Raya.h"
#include "Vista.h"

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
    m_marcador->setPos(710,20);
    m_escena->addItem(m_marcador); //Se coloca en la escena en la posición correspondiente

    //Se agregan las rayas
    rayas= new Raya();
    rayas->cargarRayas(m_svgRenderer,m_escena);  //Cargarlas del svg y colocar en opacidad 0

    //Se agrega el cuerpo
    cuerpo = new PartesCuerpo(m_svgRenderer, m_escena);
    cuerpo->agregarPartes(); //Se cargan las partes del svg
    cuerpo->colocarCuerpo(); //Se colocan en la escena con opacidad 0

    aviso=new Aviso(m_svgRenderer, m_escena);
    aviso->colocarObjetos();

    // se conectan eventos de ambas clases
    //Revisar si la palabra presionada es correcta
    QObject::connect(diccionario,SIGNAL(clickLetra(bool)),cuerpo,SLOT(revisarEvento(bool)));
    //Verificar si ha encontrado todas las letras de la palabra
    QObject::connect(diccionario,SIGNAL(nuevoCaracterEncontrado()),diccionario,SLOT(verificarGane()));
    //Si se encuentra una nueva palabra, aumentar puntaje
    QObject::connect(diccionario,SIGNAL(palabraEcontrada()),m_marcador,SLOT(incrementePuntos()));
    //Si encuentra la palabra, borrar el cuerpo para reinicar
    QObject::connect(diccionario,SIGNAL(palabraEcontrada()),aviso,SLOT(mostrarGane()));
    QObject::connect(diccionario,SIGNAL(palabraEcontrada()),cuerpo,SLOT( quitarCuerpo()));
    //Si encuentra la palabra, colocar todo el teclado para reiniciar
    QObject::connect(diccionario,SIGNAL(palabraEcontrada()),teclas,SLOT(restablecerTeclado()));
    //Si se encuentra la palabra, colocar otra nueva palabra
    QObject::connect(diccionario,SIGNAL(escribePalabra(QString)),rayas,SLOT(colocarPalabra(QString)));
    //Escribir la letra en la escena si ha sido acertada
    QObject::connect(diccionario,SIGNAL(escribaLetra(int)),rayas,SLOT(mostrarLetra(int)));
    //Dibujar las rayas para la nueva palabra
    QObject::connect(diccionario,SIGNAL(dibujeRayas(int)),rayas,SLOT(actualizarRayas(int)));
    //Si pierde, iniciar un nuevo juego
    QObject::connect(cuerpo,SIGNAL(perdio()),diccionario,SLOT(seleccionarPalabrasAzar()));
    //Si pierde, mostar teclado para el nuevo juego
    QObject::connect(cuerpo,SIGNAL(perdio()),teclas,SLOT(restablecerTeclado()));
    //QObject::connect(diccionario,SIGNAL(palabraEcontrada()),cuerpo,SLOT(dibujarGane()));
    // si perdio se muestra la palabra
    QObject::connect(cuerpo,SIGNAL(perdio()),rayas,SLOT(mostrarPalabra()));
    QObject::connect(cuerpo,SIGNAL(perdio()),aviso,SLOT(mostrarPierde()));
}

void Vista::dibujeFondo (QGraphicsScene* m_escena){
     m_fondo = new ObjetoProp("fondo"); //Buscar fondo en el svg
     m_fondo->setSharedRenderer(m_svgRenderer);
     m_fondo->setPos(45,5); //Asignar posición
     m_escena->addItem(m_fondo); //Agregar a la escena
     m_fondo->setZValue(-1);
}

Vista::~Vista()
{
}
