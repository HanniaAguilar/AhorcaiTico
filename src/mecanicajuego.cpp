#include "mecanicajuego.h"

#include <QString>
#include <QFile>
#include <fstream>
#include <iostream>
#include <QMessageBox>
#include <QTextStream>

MecanicaJuego::MecanicaJuego()
{

}
bool MecanicaJuego::cargarPalabras()
{
    QFile diccionario (":/Resources/Diccionario.txt");
    if(!diccionario.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", diccionario.errorString());
    }
    QTextStream in(&diccionario);

    while(!in.atEnd()) {
        QString linea = in.readLine();
        v_palabras.append(linea);
    }

    diccionario.close();

     return true;
}

bool MecanicaJuego::seleccionarPalabrasAzar()
{
    /*size_t indiceAzar = rand() % v_palabras.size();
    m_palabra = v_palabras[indiceAzar];//definir string palabra en el .h*/
    //aqui llamar metodo para dibujar las rayas
    return true;
}

bool MecanicaJuego::buscarCaracter(QChar caracter)
{
    bool caracterEncontrado=false;
    for(int index=0;index<m_palabra.length();++index){
        if(caracter==m_palabra[index]){
            std::cout<<"mostrar caracter:"<<index<<std::endl;//llamar metodo que muestra los caracteres deseados
            caracterEncontrado=true;
        }

    }
    return caracterEncontrado;
}

QString MecanicaJuego::lanzarPalabra() const
{
    return m_palabra;
}
