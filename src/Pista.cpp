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
    o_pista= new ObjetoProp("pista",m_diccionario);
    o_pista->setSharedRenderer(m_renderer);
    o_pista->setZValue(1);
    o_pista->setPos(550,35);
    o_pista->setOpacity(0); //Ocultar
    m_escena->addItem(o_pista); //Agregar a la escena
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
    const QString instrucciones="***********************************************************************\n"
                             "*                                                                     *\n"
                             "*   Jugar AhorcaiTico es muy fácil, lo que tienes que hacer          *\n"
                             "*   es adivinar una palabra secreta, que es un costarriqueñismo       *\n"
                             "*   si no tiene idea de cuál palabra es, tiene una ayuda, sin         *\n"
                             "*   sin embargo no es GRATIS, esto le costará dos partes del cuerpo   *\n"
                             "*   asi que usela con inteligencia, puedes ser un heroe y salvar al   *\n"
                             "*   muñeco, aunque puedes ser un villano y condenarlo a una horca     *\n"
                             "*   con solo 7 errores. Ten cuidado, Suerte\n                         *\n"
                             "*                                                                     *\n"
                             "***********************************************************************\n";
    QMessageBox* instruccion= new QMessageBox();
    instruccion->setText(instrucciones); //Texto que se muestrs
    instruccion->setWindowTitle("INSTRUCCIONES"); //Título de la ventana
    instruccion->setVisible(true); //Mostrar
}

Pista::~Pista()
{
}

