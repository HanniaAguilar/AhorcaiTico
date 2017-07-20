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

  protected:
    int m_caracteresEncontrados; //Número de carácteres adivinados en la palabra actual
    QString m_palabra;  //Palabra para adivinar actualmente
    QString m_palabraSinAcento; //Palabra sin acentos para adivinar
    QString m_definicion; //Definición de la palabra actual
    QVector<QString> v_palabras; //Vector con todas las palabras del diccionario
    QVector<QString> v_definiciones; //Vector con las definiciones
    QVector<QString> v_palabrasSinAcento; //Vector con todas las palabras sin acentos
    bool reaccione; //Para saber si se debe reaccionar en las teclas

  public:
    Diccionario(); //Constructor
    ~Diccionario();
    bool cargarPalabras(); //Llenar el vector con las palabras del diccionario
    bool buscarCaracter(QChar caracter); //Buscar un caracter en la palabra a adivinar
    QString getDefinicion() const; //Obtener la definición de la palabra actual
    bool getReaccionar() const; //Obtener el bool reaccione
    void setReaccionar(bool valor);//Asignar el bool reaccione

  signals:    
    void clickLetra(bool encontrado); //Reporta un click en alguna letra
    void nuevoCaracterEncontrado(); //Reporta que se ha adivinado un caracter en la palabra
    void escribePalabra(QString palabra); //Reporta que se debe escribir una nueva palabra con opacidad 0
    void dibujeRayas(int cantidad); //Reporta que se debe dibujar la cantidad de rayas segun la palabra
    void palabraEcontrada(); //Reporta que se ha adivinado una palabra
    void escribaLetra(int pos); //Indica que se debe escribir la letra adivina, recibe un parametro que indica la posicion
    void reiniciarJuego();//Colocar o quitar los objetos de la escena para colocar otra palabra
    void quiteVidas(); //Quitar vidas en caso de tocar la pista
    void mostrarAyuda(QString pista); //Mostrar la definición si se pide ayuda o pista
    void muestreInstrucciones(); //Mostrar las instrucciones del juego si se solicita

  public slots:
    void bloquearTeclado(); //Bloquear el teclado porque perdió o ganó
    void seleccionarPalabrasAzar(); //Escoge una palabra al azar
    void verificarGane(); //Verificar si la cantidad de caracteres adivinas corresponde al largo de la palabra
};

#endif // DICCIONARIO_H
