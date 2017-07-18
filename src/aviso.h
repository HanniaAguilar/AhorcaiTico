#ifndef AVISO_H
#define AVISO_H

#include <QGraphicsScene>
#include <QObject>
#include <QSvgRenderer>

#include "objetoprop.h"

class ObjetoProp;

class Aviso : public QObject
{
    Q_OBJECT

    protected:
    QSvgRenderer* m_svgRenderer; //Documento con los svg
    QGraphicsScene* m_escena; //Guardar la escena en que se muestran
    ObjetoProp* gane; //Objeto prop para crear el gane
    ObjetoProp* pierde; //Objeto prop para crear el pierde

   protected:

   public:
     Aviso(QSvgRenderer* svgRenderer, QGraphicsScene *escena);  //Constructor que indica el svg y la escena
     ~Aviso(); //Destructor
     void colocarObjetos(); //Crear y colocar objetos de pierde y gane con svg

    signals:

    public slots:
     void quitarObjetos(); //Colocar los objetos en opacidad 0
     void mostrarPierde(); //Mostrar objeto de pierde
     void mostrarGane(); //Mostrar objeto de gane
};

#endif // AVISO_H
