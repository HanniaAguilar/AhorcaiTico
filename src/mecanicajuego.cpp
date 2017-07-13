#include "mecanicajuego.h"
#include <string>
#include <fstream>
#include <iostream>

MecanicaJuego::MecanicaJuego()
{

}
bool MecanicaJuego::cargarPalabras()
{
    std::string palabra;
    std::ifstream diccionario (":/Resources/Diccionario.txt");
     if (!diccionario.is_open()){         
         return false;
     }
     else
     {
       while ( getline (diccionario,palabra) )
       {
            v_palabras.push_back(palabra);
       }
       diccionario.close();
       return true;
     }
}

bool MecanicaJuego::seleccionarPalabrasAzar()
{
    size_t indiceAzar = rand() % v_palabras.size();
    m_palabra = v_palabras[indiceAzar];//definir string palabra en el .h
    //aqui llamar metodo para dibujar las rayas
    return true;
}

bool MecanicaJuego::buscarCaracter(char caracter)
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

void MecanicaJuego::lanzarPalabra() const
{
    std::cout<<m_palabra<<std::endl;
}
