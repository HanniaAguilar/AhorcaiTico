#ifndef MARCADOR_H
#define MARCADOR_H

#include <QGraphicsTextItem>

class Marcador : public QGraphicsTextItem
{
   Q_OBJECT

   protected:
    /// marcador de puntos del jugador
    QString tipoMarcador;
    /// Cantidad de puntos ganados
    int puntos;

   public:
    /// constructor
    Marcador(const QString& tipoMarcador, int puntosIniciales, QColor color, QGraphicsItem *parent = nullptr);
    /// destructor
    ~Marcador();
    /// metodo get de Puntos
    inline int getPuntos() { return puntos;}
    /// incrementar puntos
    void incrementePuntos();
    /// resetear el marcador
    void restablecerMarcador();

   protected:
   void actualizarMarcador();
};

#endif // MARCADOR_H
