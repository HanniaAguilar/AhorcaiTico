#ifndef MECANICAJUEGO_H
#define MECANICAJUEGO_H


#include <iostream>
#include <string>
#include <QVector>
#include <QString>


// TODO: renombrar a Diccionario
class MecanicaJuego
{
    private:
    QString m_palabra;
    QVector<QString> v_palabras;
    public:

    MecanicaJuego();
    bool cargarPalabras();
    bool seleccionarPalabrasAzar();
    bool buscarCaracter(QChar caracter);
    QString lanzarPalabra() const;


};
#endif // MECANICAJUEGO_H
