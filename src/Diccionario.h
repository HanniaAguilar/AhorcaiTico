#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include <iostream>
#include <string>
#include <QVector>
#include <QString>

// TODO: renombrar a Diccionario
class Diccionario
{
    private:
    QString m_palabra;
    QVector<QString> v_palabras;
    public:

    Diccionario();
    bool cargarPalabras();
    bool seleccionarPalabrasAzar();
    bool buscarCaracter(QChar caracter);
    QString lanzarPalabra() const;


};
#endif // DICCIONARIO_H
