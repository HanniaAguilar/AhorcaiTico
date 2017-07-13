#include "Vista.h"

class ObjectoProp;
class PartesCuerpo;

Vista::Vista(QGraphicsScene *escena)
    :QGraphicsView(escena)
    ,m_componente(Q_NULLPTR)
    ,m_svgRenderer(Q_NULLPTR)
    ,m_fondo(Q_NULLPTR)
    ,teclas (Q_NULLPTR)

{
  #if ! defined(Q_OS_ANDROID)
    resize(960, 540);
  #endif
}

void Vista::insertarComponentes(QGraphicsScene* m_escena)
{
    m_svgRenderer = new QSvgRenderer(QString(":/Resources/assets.svg"), this);

    this->dibujeFondo(m_escena);
    this->setBackgroundBrush(QBrush(Qt::white, Qt::SolidPattern));
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    /// Se agrega el teclado
    teclas = new Teclas();
    teclas->agregarTeclado();
    teclas->mostrarTeclado(m_svgRenderer,m_escena);

    cuerpo = new PartesCuerpo();
    cuerpo->mostrarPartes(m_svgRenderer, m_escena);

}

void Vista::dibujeFondo (QGraphicsScene* m_escena){
     m_fondo = new ObjetoProp("fondo");
     m_fondo->setSharedRenderer(m_svgRenderer);
     m_fondo->setPos(45,62);
     m_escena->addItem(m_fondo);
     //this->fitInView(m_fondo,Qt::KeepAspectRatioByExpanding);
     m_fondo->setZValue(-1);
     //m_fondo->setOpacity(1);
}

Vista::~Vista()
{
    delete  m_componente;
//    delete  m_svgRenderer;
}
