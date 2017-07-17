#ifndef PARTESCUERPO_H
#define PARTESCUERPO_H

#include <QGraphicsScene>
#include <QObject>
#include <QSvgRenderer>

#include "objetoprop.h"

class ObjetoProp;

class PartesCuerpo : public QObject
{
    Q_OBJECT

    protected:
    int m_ContError; //Contador de equivocaciones y por tanto parte del cuerpo asignada
    QGraphicsScene* m_escena; //Guardar la escena en que se muestran
    QSvgRenderer* m_svgRenderer; //Documento con los svg
    ObjetoProp* temporal; //Objeto prop para crear las partes del cuerpo

   protected:
     QVector<QString> v_Partes; //Nombre de las partes del cuerpo en el svg (id)
     QVector<ObjetoProp*> v_objetosPartes; //Objetos creados con el svg

   public:
     PartesCuerpo(); //Constructor
     ~PartesCuerpo(); //Destructor
     PartesCuerpo(QSvgRenderer* svgRenderer, QGraphicsScene *escena);  //Constructor que indica el svg y la escena
     void agregarPartes(); //Agregar los id de las partes del cuerpo al vector
     void colocarCuerpo(); //Colocar el cuerpo en la escena con opacidad 0
     void mostrarPartes(); //Mostrar la parte del cuerpo dependidiendo del número de errores (opacidad 1)
     void darPos(int cont); //Asignar la posición a la parte del cuerpo en la escena

    signals:
     void perdio(); //Indica que el cuerpo se ha completado

    public slots:
     void revisarEvento(bool encontrado); //Revisar si el evento es false (error:colocar parte) o true (false:ignorar)
     void quitarCuerpo(); //Quitar todo el cuerpo de la escena (opacidad 0)
};

#endif // PARTESCUERPO_H
