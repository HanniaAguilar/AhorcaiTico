#include "Diccionario.h"

#include <QString>
#include <QFile>
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

#include <iostream>

bool Diccionario::seleccionarPalabrasAzar()
{
    size_t indiceAzar = rand() % v_palabras.size();
    m_palabra = v_palabras[indiceAzar];//definir string palabra en el .h
    std::cout<<m_palabra.toStdString()<<std::endl;    
    return true;
}

bool Diccionario::buscarCaracter(QChar caracter)
{
    bool caracterEncontrado=false;
    for(int index=0;index<m_palabra.length();++index){
        if(caracter.toUpper()==m_palabra[index].toUpper()){
            std::cout<<"mostrar caracter:"<<index<<std::endl;//llamar metodo que muestra los caracteres deseados
            caracterEncontrado=true;
        }
    }
    emit nuevoEvento(caracterEncontrado);
}

QString Diccionario::lanzarPalabra() const
{
    return m_palabra;
}

int Diccionario::tamanoPalabra() const
{
    return m_palabra.length();
}

void Diccionario::crearNuevaPalabra()
{
    seleccionarPalabrasAzar();
}
