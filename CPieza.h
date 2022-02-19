#ifndef CPIEZA_H
#define CPIEZA_H

#include "Header.h"

class CPieza {
protected:
    int posX;
    int posY;
    char color;
    string icono;
public:
    CPieza();
    CPieza(int y, int x, char c);
    virtual ~CPieza() = default;
    void setPosX(int x);
    void setPosY(int y);
    int getPosX() const;
    int getPosY() const;
    char getColor() const;
    string getIcono();
    virtual bool confirmarMovimiento(int y, int x, CPieza* casilla) = 0;
};

#endif