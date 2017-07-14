#include "Vista.h"
#include "Raya.h"

class ObjectoProp;
class PartesCuerpo;

Vista::Vista(QGraphicsScene *escena)
    :QGraphicsView(escena)
    ,m_svgRenderer(Q_NULLPTR)
    ,m_fondo(Q_NULLPTR)
    ,teclas (Q_NULLPTR)

{
  #if ! defined(Q_OS_ANDROID)
    resize(960, 540);
  #endif
}

void Vista::insertarComponentes(QGraphicsScene* m_escena,Diccionario* diccionario)//ahora recibe un diccionario
{
    m_svgRenderer = new QSvgRenderer(QString(":/Resources/assets.svg"), this);

    this->dibujeFondo(m_escena);
    this->setBackgroundBrush(QBrush(Qt::white, Qt::SolidPattern));
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    /// Se agrega el teclado
    teclas = new Teclas(diccionario);
    teclas->agregarTeclado();
    teclas->mostrarTeclado(m_svgRenderer,m_escena);

    m_marcador = new Marcador("Puntos",0,Qt::black);
    m_marcador->setPos(700,0);
    m_escena->addItem(m_marcador);

    rayas= new Raya("x",Qt::black);
    rayas->setPos(0,0);
    m_escena->addItem(rayas);
    rayas->mostrarRayas(m_svgRenderer,m_escena,9);

    cuerpo = new PartesCuerpo(m_svgRenderer, m_escena);
    cuerpo->mostrarPartes();
    QObject::connect(diccionario,SIGNAL(nuevoEvento(bool)),cuerpo,SLOT(revisarEvento(bool)));
}

void Vista::dibujeFondo (QGraphicsScene* m_escena){
     m_fondo = new ObjetoProp("fondo");
     m_fondo->setSharedRenderer(m_svgRenderer);
     m_fondo->setPos(45,62);
     m_escena->addItem(m_fondo);
     m_fondo->setZValue(-1);
}

Vista::~Vista()
{
}
