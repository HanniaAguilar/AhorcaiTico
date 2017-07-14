#include "Diccionario.h"

#include <QString>
#include <QFile>
#include <fstream>
#include <iostream>
#include <QMessageBox>
#include <QTextStream>

Diccionario::Diccionario()
{
}

bool Diccionario::cargarPalabras()
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

bool Diccionario::seleccionarPalabrasAzar()
{
    size_t indiceAzar = rand() % v_palabras.size();
    m_palabra = v_palabras[indiceAzar];//definir string palabra en el .h
    //aqui llamar metodo para dibujar las rayas
    return true;
}

bool Diccionario::buscarCaracter(QChar caracter)
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

QString Diccionario::lanzarPalabra() const
{
    return m_palabra;
}
