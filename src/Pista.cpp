#include "Pista.h"
#include <iostream>

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
    o_pista= new ObjetoProp("pista",m_diccionario);
    o_pista->setSharedRenderer(m_renderer);
    o_pista->setZValue(1);
    o_pista->setPos(550,35);
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
    ayuda->setWindowTitle("PISTA");
    ayuda->setFixedSize(200,200);
    ayuda->setVisible(true);
}

void Pista::mostrarInstrucciones()
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
    instruccion->setText(instrucciones);
    instruccion->setWindowTitle("INSTRUCCIONES");
    instruccion->setVisible(true);

}

