#include "Diccionario.h"

Diccionario::Diccionario() //Inicializar los miembros
    :m_caracteresEncontrados(0)
    ,m_palabra("")
    ,m_palabraSinAcento("")    
    ,m_definicion("")
    ,reaccione(true)
{
}

bool Diccionario::cargarPalabras()
{
    QFile diccionario (":/Resources/Diccionario.txt"); //Agregar el archivo del diccionario
    if(!diccionario.open(QIODevice::ReadOnly))
        QMessageBox::information(0, "error", diccionario.errorString()); //Reportar error si no se encuentra

    QTextStream in(&diccionario);
    while(!in.atEnd()) //Leer el diccionario completo
    {
        QString linea = in.readLine(); //Leer las líneas
        v_palabras.append(linea); //Agregar la primer palabra al vector de palabras
    }

    diccionario.close(); //Cerrar el archivo

    QFile pistas (":/Resources/Pistas.txt"); //Agregar el archivo de las definicioens
    if(!pistas.open(QIODevice::ReadOnly))
        QMessageBox::information(0, "error", pistas.errorString()); //Reportar error si no se encuentra

    QTextStream inP(&pistas);
    while(!inP.atEnd()) //Leer las definiciones completas
    {
        QString linea = inP.readLine(); //Leer las líneas
        v_definiciones.append(linea); //Agregar la primer definición al vector
    }

    pistas.close(); //Cerrar el archivo

    QFile diccionarioSinAcento (":/Resources/Diccionario_sin_acentos.txt");
    if(!diccionarioSinAcento.open(QIODevice::ReadOnly))
        QMessageBox::information(0, "error", diccionarioSinAcento.errorString());    

    QTextStream inF(&diccionarioSinAcento);    
    while(!inF.atEnd()) //Leer el diccionario completo
    {
        QString linea = inF.readLine(); //Leer las líneas
        v_palabrasSinAcento.append(linea); //Agregar la primer palabra al vecto de palabras sin Acento
    }

    diccionarioSinAcento.close(); //Cerrar el archivo

     return true;
}

//#include <iostream>

void Diccionario::seleccionarPalabrasAzar()
{
    srand(time(NULL)); //Cambiar la semilla de números random
    size_t indiceAzar = rand() % v_palabras.size(); //Generar un número al azar entre la cantidad de palabras
    m_palabra = v_palabras[indiceAzar]; //Leer la palabra en el número generado
    m_definicion=v_definiciones[indiceAzar];    
    m_palabraSinAcento = v_palabrasSinAcento[indiceAzar]; //Leer la palabra sin acentos en el número generado
    emit escribePalabra(m_palabraSinAcento);//Indicar que se debe escribir una palabra nueva
    emit dibujeRayas(m_palabraSinAcento.length()); //Dibujar las rayas correspondientes en la escena
    m_caracteresEncontrados=0;
}

bool Diccionario::buscarCaracter(QChar caracter)
{
    bool caracterEncontrado=false;
    for(int index=0;index<m_palabraSinAcento.length();++index){ //Recorrer la palabra en busca de ese caracter
        if(caracter.toUpper()==m_palabraSinAcento[index].toUpper()){
            //Ignore las mayúsculas y minúsculas y verificar si es igual al que se busca
            caracterEncontrado=true; //Sí acertó el caracter
            ++m_caracteresEncontrados; //Aumentar los caracteres encontrados
            emit escribaLetra(index); //Señal para indicar acierto y mostra la letra en la posición correspondiente
            emit nuevoCaracterEncontrado(); //Señal para verificar si la palabra está completa ahora
        }
    }    
    emit clickLetra(caracterEncontrado);//Se indica que se presionó una letra, si no es correcta se dibuja el cuerpo
    return caracterEncontrado;
}

void Diccionario::verificarGane()
{    
    if(m_caracteresEncontrados==m_palabraSinAcento.length()){//Si se encontraron todas las letras, ya ganó
        emit palabraEcontrada(); //Indicar que se ha ganado        
        m_caracteresEncontrados=0; //Iniciar la otra palabra
        reaccione=false;
    }
}

void Diccionario::bloquearTeclado() //No puede reaccionar a las teclas
{
     reaccione=false;
}

bool Diccionario::getReaccionar()const //Obtener booleana reaccione
{
    return reaccione;
}

void Diccionario::setReaccionar(bool valor) //Asignar booleana reaccione
{
    reaccione=valor;
}

QString Diccionario::getDefinicion()const //Obtener definición de la palabra
{
 return m_definicion;
}

Diccionario::~Diccionario()
{

}
