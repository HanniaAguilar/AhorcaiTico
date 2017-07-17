#ifndef MARCADOR_H
#define MARCADOR_H

#include <QColor>
#include <QFont>
#include <QGraphicsTextItem>
#include <QObject>

class Marcador : public QGraphicsTextItem
{
   Q_OBJECT

   protected:    
    QString tipoMarcador;  // marcador de puntos del jugador
    int puntos; // Cantidad de puntos ganados

   public:    
    Marcador(const QString& tipoMarcador, int puntosIniciales, QColor color, QGraphicsItem *parent = nullptr); // constructor
    ~Marcador(); // Destructor
    inline int getPuntos() { return puntos;}  // Método para conocer los puntos
    void actualizarMarcador(); //Actualiza el marcador en la escena
    void restablecerMarcador(); //Reiniciar el marcador

   public slots:
    void incrementePuntos(); //Aumentar los puntos por caracteres adivinados
};

#endif // MARCADOR_H
