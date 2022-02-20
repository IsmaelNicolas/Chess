#ifndef CPIEZA_H
#define CPIEZA_H

#include "Header.h"
#include "json.hpp"
using ordered_json = nlohmann::ordered_json;
class CPieza {
protected:
public:
    int posX;
    int posY;
    char color;
    std::string icono;
    CPieza();
    CPieza(int y, int x, char c);
    virtual ~CPieza() = default;
    void setPosX(int x);
    void setPosY(int y);
    int getPosX() const;
    int getPosY() const;
    char getColor() const;
    std::string getIcono();
    virtual bool confirmarMovimiento(int y, int x, CPieza* casilla) = 0;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(CPieza, posX, posY, color,icono)
};

#endif