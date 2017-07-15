#ifndef MARCADOR_H
#define MARCADOR_H

#include <QGraphicsTextItem>
#include <QObject>

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
    /// actualiza puntos
    void actualizarMarcador();
    /// resetear el marcador
    void restablecerMarcador();

   public slots:
    void incrementePuntos();
};

#endif // MARCADOR_H
