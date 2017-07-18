#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include <iostream>
#include <string>

#include <QFile>
#include <QMessageBox>
#include <QObject>
#include <QString>
#include <QTextStream>
#include <QVector>
#include <ctime>

class Diccionario : public QObject
{
  Q_OBJECT

  private:
    QString m_palabra;  //Palabra para adivinar actualmente
    QString m_palabraSinAcento; //Palabra sin acentos para adivinar
    QVector<QString> v_palabras; //Vector con todas las palabras del diccionario
    QVector<QString> v_palabrasSinAcento; //Vector con todas las palabras sin acentos
    int m_caracteresEncontrados; //Número de carácteres adivinados en la palabra actual

  public:
    Diccionario(); //Constructor
    bool cargarPalabras(); //Llenar el vector con las palabras del diccionario
    bool buscarCaracter(QChar caracter); //Buscar un caracter en la palabra a adivinar

  signals:
    void clickLetra(bool encontrado); //Reporta un click en alguna letra
    void nuevoCaracterEncontrado(); //Reporta que se ha adivinado un caracter en la palabra
    void escribePalabra(QString palabra); //Reporta que se debe escribir una nueva palabra con opacidad 0
    void dibujeRayas(int cantidad); //Reporta que se debe dibujar la cantidad de rayas segun la palabra
    void palabraEcontrada(); //Reporta que se ha adivinado una palabra
    void escribaLetra(int pos); //Indica que se debe escribir la letra adivina, recibe un parametro que indica la posicion

  public slots:    
    void seleccionarPalabrasAzar(); //Escoge una palabra al azar
    void verificarGane(); //Verificar si la cantidad de caracteres adivinas corresponde al largo de la palabra
};

#endif // DICCIONARIO_H
