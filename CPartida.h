#ifndef CPARTIDA_H
#define CPARTIDA_H

#include "Application.h"
#include "Header.h"
#include "CTabla.h"
#include <iostream>
#include <fstream>
class CPartida {
    int opcion;
    string posOrigen;
    string posDestino;
    bool turno;  // true: Piezas blancas, false: Piezas negras
public:
    CTabla tablero;
    CPartida();
    ~CPartida() = default;
    void anunciarGanador() const;
    void ejecutarMovimiento();
    void ejecutarPartida();
    void hacerBackup();
    void cargarBackupFile(string);

    string nombreFile();

};

#endif
