#include "mecanicajuego.h"



MecanicaJuego::MecanicaJuego()
{

}
bool MecanicaJuego::cargarPalabras()
{
    v_palabras.push_back("casa");
    v_palabras.push_back("carro");
    v_palabras.push_back("sapo");
    v_palabras.push_back("cabina");
    v_palabras.push_back("juego");
    v_palabras.push_back("patinar");
    v_palabras.push_back("hablar");
    v_palabras.push_back("mariposa");
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
    for(int index=0;index<m_palabra.length();++index){
        if(caracter==m_palabra[index]){
            std::cout<<"mostrar caracter:"<<index<<std::endl;//llamar metodo que muestra los caracteres deseados
        }

    }
}

void MecanicaJuego::lanzarPalabra() const
{
    std::cout<<m_palabra<<std::endl;
}
