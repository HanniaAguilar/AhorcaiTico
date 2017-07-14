#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include <iostream>
#include <string>
#include <QVector>
#include <QString>
#include <QObject>

// TODO: renombrar a Diccionario
class Diccionario : public QObject
{
    Q_OBJECT
  private:
    QString m_palabra;
    QVector<QString> v_palabras;

  public:
    Diccionario();
    bool cargarPalabras();
    bool seleccionarPalabrasAzar();
    bool buscarCaracter(QChar caracter);
    QString lanzarPalabra() const;
    int tamanoPalabra() const;

  signals:
    void nuevoEvento(bool encontrado);


};
#endif // DICCIONARIO_H
