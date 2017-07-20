#ifndef PISTA_H
#define PISTA_H

#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include <QObject>
#include <QSvgRenderer>
#include <QMessageBox>

#include "Diccionario.h"
#include "objetoprop.h"


class ObjetoProp;

class Pista : public QObject
{
    Q_OBJECT

   protected:
    QSvgRenderer* m_renderer; //Archivo con los objetos para la escena
    QGraphicsScene* m_escena; //Escena
    ObjetoProp* o_pista; //Objeto de la pista en la escena
    ObjetoProp* o_reglas; //Objeto de la pista en la escena
    Diccionario* m_diccionario; //Puntero a diccionario para conocer la definición (pista)

   public:
    Pista(QSvgRenderer *svgRenderer, QGraphicsScene *escena, Diccionario *m_diccionario); //Constructor
    ~Pista(); //Destructor
    void cargar(); //Obtener el objeto del svg

   public slots:
    void ocultarPista(); //Oculta la pista
    void mostrarPista(); //Muestra la pista en escena
    void mostrarAyuda(QString pista); //Muestra la pista en otra ventana
    void mostrarInstrucciones(); //Permite ver las instrucciones del juego
};

#endif // PISTA_H
