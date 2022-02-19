#ifndef CPIEZA_HIJAS_H
#define CPIEZA_HIJAS_H

#include "Header.h"
#include "CPieza.h"

class CPeon: public CPieza {
private:
    bool primerMovimiento;
public:
    CPeon();
    CPeon(int y, int x, char c);
    ~CPeon() override = default;
    bool confirmarMovimiento(int y, int x, CPieza* casilla) override;
};


class CTorre: public CPieza {
public:
    CTorre();
    CTorre(int y, int x, char c);
    ~CTorre() override = default;
    bool confirmarMovimiento(int y, int x, CPieza* casilla) override;
};



class CCaballo: public CPieza {
public:
    CCaballo();
    CCaballo(int y, int x, char c);
    ~CCaballo() override = default;
    bool confirmarMovimiento(int y, int x, CPieza* casilla) override;
};



class CAlfil: public CPieza {
public:
    CAlfil();
    CAlfil(int y, int x, char c);
    ~CAlfil() override = default;
    bool confirmarMovimiento(int y, int x, CPieza* casilla) override;
};



class CReina: public CPieza {
public:
    CReina();
    CReina(int y, int x, char c);
    ~CReina() override = default;
    bool confirmarMovimiento(int y, int x, CPieza* casilla) override;
};



class CRey: public CPieza {
public:
    CRey();
    CRey(int y, int x, char c);
    ~CRey();
    bool confirmarMovimiento(int y, int x, CPieza* casilla) override;
};

#endif