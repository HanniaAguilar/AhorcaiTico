
#include "mainwindow.h"

class ObjectoProp;

MainWindow::MainWindow(QGraphicsScene *escena)
    :QGraphicsView(escena)
    ,m_componente(Q_NULLPTR)
    ,m_svgRenderer(Q_NULLPTR)
{
}

void MainWindow::insertarComponentes(QGraphicsScene* m_escena)
{

    this->setBackgroundBrush(QBrush(Qt::white, Qt::SolidPattern));
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    m_svgRenderer = new QSvgRenderer(QString(":/Resources/assets.svg"), this);

    m_componente = new ObjetoProp("horca");
    m_componente->setElementId("horca");
    m_componente->setSharedRenderer(m_svgRenderer);
    m_escena->addItem(m_componente);

    /*m_componente = new ObjetoProp("cabeza");
    m_componente->setElementId("cabeza");
    m_componente->setSharedRenderer(m_svgRenderer);
    m_escena->addItem(m_componente);*/
}

MainWindow::~MainWindow()
{
    delete  m_componente;
    delete  m_svgRenderer;
}

