#include "Pista.h"
#include <iostream>

Pista::Pista(QSvgRenderer* svgRenderer, QGraphicsScene *escena, Diccionario* diccionario) //Inicializar miembros
    :m_renderer(svgRenderer)
    ,m_escena(escena)
    ,m_diccionario(diccionario)
{
}

void Pista::cargar() //Cargar la imagen
{
    o_pista= new ObjetoProp("ayuda",m_diccionario);
    o_pista->setSharedRenderer(m_renderer);
    o_pista->setZValue(1);
    o_pista->setPos(550,35);
    o_pista->setOpacity(0); //Ocultar
    m_escena->addItem(o_pista); //Agregar a la escena


    o_reglas= new ObjetoProp("instruccion",m_diccionario);
    o_reglas->setSharedRenderer(m_renderer);
    o_reglas->setZValue(1);
    o_reglas->setPos(20,20);
    o_reglas->setOpacity(1);
    m_escena->addItem(o_reglas);
}

void Pista::mostrarPista() //Muestra el icono de la pista
{
    o_pista->setOpacity(1);
}

void Pista::ocultarPista() //Oculta el icono de la pista
{
    o_pista->setOpacity(0);   
}

void Pista::mostrarAyuda(QString pista) //Mostrar otra ventana con ayuda
{
    QMessageBox* ayuda= new QMessageBox();
    ayuda->setText(pista); //Texto que se coloca, definición.
    ayuda->setWindowTitle("PISTA"); //Título de la ventana
    ayuda->setFixedSize(200,200); //Tamaño
    ayuda->setVisible(true); //Mostra ventana
}

void Pista::mostrarInstrucciones() //Instrucciones del juego
{
    const QString instrucciones="**********************************************************************\n"
                                "Jugar AhorcaiTico es muy fácil, lo que tienes que hacer es adivinar"
                                " una palabra secreta, que es un costarriqueñismo si no tiene idea de"
                                " cuál palabra es, tiene una ayuda (Pista en la caja al lado del puntaje),"
                                " sin embargo no es GRATIS, esto le costará dos partes del cuerpo asi que"
                                " utilisela con inteligencia.\n\n"
                                "Puedes ser un héroe y salvar al muñeco, aunque puedes ser un villano"
                                " y condenarlo a una horca con solo 7 errores.\n\n"
                                "Ten cuidado, Suerte.\n\n"
                                "**********************************************************************\n";
    QMessageBox* instruccion= new QMessageBox();
    instruccion->setText(instrucciones);
    instruccion->setWindowTitle("INSTRUCCIONES");
    instruccion->setMinimumSize(400,400);
    instruccion->setVisible(true);
}

Pista::~Pista()
{
}

