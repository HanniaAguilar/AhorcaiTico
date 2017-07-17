#include "marcador.h"

Marcador::Marcador(const QString &tipoMarcador, int puntosIniciales, QColor color, QGraphicsItem* parent)
    : QGraphicsTextItem(parent)
    , tipoMarcador(tipoMarcador) //Dice qué indica el marcador
    , puntos(puntosIniciales)   //Puntos con lo que se inicia el juego
{
    setDefaultTextColor(color); //Dar formato al marcador para colocarlo en escena
    setFont(QFont("", 24));
    actualizarMarcador(); //Colocar el marcador en los puntos iniciales
}

void Marcador::incrementePuntos()
{
    puntos+=10; //Aumentar puntaje
    actualizarMarcador(); //Actualizar en la pantalla
}

void Marcador::actualizarMarcador()
{
    setPlainText( QString("%1: %2").arg(tipoMarcador).arg(puntos) ); //Actualizar en la pantalla
}

void Marcador::restablecerMarcador()
{
    puntos=0; //Iniciar el puntaje en 0
    actualizarMarcador(); //Actualizar en la pantalla
}

Marcador::~Marcador()
{

}
