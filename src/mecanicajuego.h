#ifndef MECANICAJUEGO_H
#define MECANICAJUEGO_H


#include <iostream>
#include <string>
#include <vector>

class MecanicaJuego
{
    private:
    std::string m_palabra;
    std::vector<std::string> v_palabras;
    public:

    MecanicaJuego();
    bool cargarPalabras();
    bool seleccionarPalabrasAzar();
    bool buscarCaracter(char caracter);
    void lanzarPalabra() const;


};
#endif // MECANICAJUEGO_H
