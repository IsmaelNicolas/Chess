#include "CPieza.h"

CPieza::CPieza(): posX{0}, posY{0}, color{'B'}, icono{"pB"} {}

CPieza::CPieza(int y, int x, char c): posY{y}, posX{x}, color(c) {
    icono = "p";
    icono.push_back(color);
}

void CPieza::setPosX(int x) {posX = x;}

void CPieza::setPosY(int y) {posY = y;}

int CPieza::getPosX() const {return posX;}

int CPieza::getPosY() const {return posY;}

char CPieza::getColor() const {return color;}

string CPieza::getIcono() {return icono;}
