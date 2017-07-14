#ifndef PARTESCUERPO_H
#define PARTESCUERPO_H

#include "objetoprop.h"
#include <QGraphicsScene>
#include <QSvgRenderer>
#include <QObject>

class PartesCuerpo : public QObject
{
    Q_OBJECT
    protected:
    int m_ContError;
    QGraphicsScene* m_escena;
    QSvgRenderer* m_svgRenderer;

     //QVector<QString> v_partes;

    //public:
     //QVector<ObjetoProp*> v_objetosPartes;

    public:
     PartesCuerpo();
     PartesCuerpo(QSvgRenderer* svgRenderer, QGraphicsScene *escena);
     //void agregarPartes();
     void mostrarPartes();
     //void cargarPartes(QSvgRenderer *svgRenderer, QGraphicsScene *escena);
     //void fijarPosiciones();
    public slots:
     void revisarEvento(bool encontrado);
};

#endif // PARTESCUERPO_H
