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
    ObjetoProp* temporal;

   protected:
     QVector<QString> v_Partes;
     QVector<ObjetoProp*> v_objetosPartes;

   public:
     PartesCuerpo();
     PartesCuerpo(QSvgRenderer* svgRenderer, QGraphicsScene *escena);   
     void agregarPartes();
     void colocarCuerpo();
     void mostrarPartes();
     void quitarCuerpo();
     void darPos(int cont);

    public slots:
     void revisarEvento(bool encontrado);
     void esconderCuerpo();
     //void dibujarGane();

    signals:
     void perdio();

};

#endif // PARTESCUERPO_H
