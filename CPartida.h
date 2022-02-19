#ifndef CPARTIDA_H
#define CPARTIDA_H

#include "Header.h"
#include "CTabla.h"

class CPartida {
    CTabla tablero;
    int opcion;
    string posOrigen;
    string posDestino;
    bool turno;  // true: Piezas blancas, false: Piezas negras
public:
    CPartida();
    ~CPartida() = default;
    void anunciarGanador() const;
    void ejecutarMovimiento();
    void ejecutarPartida();
};

#endif
