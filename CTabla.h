#ifndef CTABLA_H
#define CTABLA_H

#include "Header.h"
#include "CPieza.h"
#include "CPieza_Hijas.h"
#include <iostream>
#include <fstream>

const unsigned int X = 8;
const unsigned int Y = 8;

class CTabla {
private:
public:
    unsigned int tamX;
    unsigned int tamY;
    unsigned int numPiezas;
    CPieza** listaPiezas;
    CTabla();
    ~CTabla();
    void imprimirTabla();
    bool posicionValida(string pos) const;
    CPieza* buscarPieza(int y, int x);
    void eliminarPieza(int y, int x);
    bool moverPieza(int y1, int x1, int y2, int x2, bool turno);
    void cargarPiezas(string);
    
};

#endif