#include "Pista.h"

Pista::Pista(QSvgRenderer* svgRenderer, QGraphicsScene *escena, Diccionario* diccionario)
    :m_renderer(svgRenderer)
    ,m_escena(escena)
    ,m_diccionario(diccionario)
{
}

Pista::~Pista()
{
}

//carga la imagen
void Pista::cargar()
{
    o_pista= new ObjetoProp("Ayuda",m_diccionario);
    o_pista->setSharedRenderer(m_renderer);
    o_pista->setZValue(1);
    o_pista->setPos(410,20);
    o_pista->setOpacity(0);
    m_escena->addItem(o_pista);
}

//muestra el icono de la pista
void Pista::mostrarPista()
{
    o_pista->setOpacity(1);
}

// oculta la imagen de la pista
void Pista::ocultarPista()
{
    o_pista->setOpacity(0);
}

void Pista::mostrarAyuda(QString pista)
{
    QMessageBox* ayuda= new QMessageBox();
    ayuda->setText(pista);
    ayuda->setWindowTitle("Ayuda");
    ayuda->setFixedSize(200,200);
    ayuda->setVisible(true);
}

