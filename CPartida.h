#ifndef CPARTIDA_H
#define CPARTIDA_H

#include "Header.h"
#include "CTabla.h"
#include <iostream>
#include <fstream>
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

    static void readBinary(std::string& fileName, CPartida& someoneElse);
    void writeBinary(std::ofstream& outputFile, CPartida& someone, std::string& fileName);
    void cargarBackup();
};

#endif
