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

    QFile diccionarioSinAcento (":/Resources/Diccionario_sin_acentos.txt");
    if(!diccionarioSinAcento.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", diccionarioSinAcento.errorString());
    }
    QTextStream inF(&diccionarioSinAcento);

    while(!inF.atEnd()) {
        QString linea = inF.readLine();
        v_palabrasSinAcento.append(linea);
    }

    diccionarioSinAcento.close();

     return true;
}

#include <iostream>

bool Diccionario::seleccionarPalabrasAzar()
{
    size_t indiceAzar = rand() % v_palabras.size();
    m_palabra = v_palabras[indiceAzar];//definir string palabra en el .h
    m_palabraSinAcento = v_palabrasSinAcento[indiceAzar];
    std::cout<<m_palabra.toStdString()<<std::endl;
    emit dibujeRayas(m_palabra.length());
    return true;
}

bool Diccionario::buscarCaracter(QChar caracter)
{
    bool caracterEncontrado=false;
    for(int index=0;index<m_palabraSinAcento.length();++index){
        if(caracter.toUpper()==m_palabraSinAcento[index].toUpper()){
            std::cout<<"mostrar caracter:"<<index<<std::endl;//llamar metodo que muestra los caracteres deseados
            ++m_caracteresEncontrados;
            emit nuevoCaracterEncontrado();
            caracterEncontrado=true;
        }
    }
    /// emite evento de cambio se busca un caracter
    emit nuevoEvento(caracterEncontrado);
}

QString Diccionario::lanzarPalabra() const
{
    std::cout<<m_palabraSinAcento.length()<<std::endl;
    return m_palabraSinAcento;
}

int Diccionario::tamanoPalabra() const
{
    return m_palabraSinAcento.length();
}

void Diccionario::crearNuevaPalabra()
{
    seleccionarPalabrasAzar();
}

void Diccionario::verificarGane()
{

    if(m_caracteresEncontrados==m_palabraSinAcento.length()){
        m_caracteresEncontrados=0;
        seleccionarPalabrasAzar();
        std::cout<<"gano"<<std::endl;
        emit palabraEcontrada();
    }
}
