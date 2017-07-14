#include "marcador.h"
#include <QColor>
#include <QFont>

Marcador::Marcador(const QString &tipoMarcador, int puntosIniciales, QColor color, QGraphicsItem* parent)
    : QGraphicsTextItem(parent)
    , tipoMarcador(tipoMarcador)
    , puntos(puntosIniciales)
{
    setDefaultTextColor(color);
    setFont(QFont("", 24));
    actualizarMarcador();
}

Marcador::~Marcador()
{
}

void Marcador::incrementePuntos()
{
    puntos+=10;
    actualizarMarcador();
}

void Marcador::actualizarMarcador()
{
    setPlainText( QString("%1: %2").arg(tipoMarcador).arg(puntos) );
}

void Marcador::restablecerMarcador()
{
    puntos=0;
    actualizarMarcador();
}
