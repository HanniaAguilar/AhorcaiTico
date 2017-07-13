#include <iostream>
#include "MecanicaJuego.h"
#include "Controlador.h"

int main(int argc, char *argv[])
{
    Controlador ahorcaiTico(argc, argv);
    return ahorcaiTico.correr();
}
