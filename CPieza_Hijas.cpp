#include "CPieza_Hijas.h"


// ---- Peon ----------------------------------

CPeon::CPeon():CPieza(), primerMovimiento(true) {icono[0] = 'P';}

CPeon::CPeon(int y, int x, char c): CPieza(y, x, c), primerMovimiento(true) {icono[0]='P';}

bool CPeon::confirmarMovimiento(int y, int x, CPieza* casilla) {
    cout << endl;
    if((posY==y) and (posX==x)){
        cout << "Movimiento NO VALIDO: La posicion de destino no puede ser igual a la posicion de la pieza." << endl;
        return false;
    }
    if(primerMovimiento) {
        if((posX == x) && (posY - y)==(color == 'B'? -2: 2) && casilla == nullptr) {
            cout << "Movimiento VALIDO." << endl;
            primerMovimiento = false;
            return true;
        }
    }
    if(((posY-y)!=(color == 'B'? -1: 1)) || abs(posX-x)>1) {
        cout << "Movimiento NO VALIDO: El peon no puede moverse a esa posicion." << endl;
        return false;
    }
    if(abs(posX-x)) {
        if(casilla == nullptr) {
            cout << endl << "Movimiento NO VALIDO: La casilla debe tener una pieza" << ' ' << (color=='B'?"negra":"blanca");
            return false;
        }
        if (casilla->getColor() == color) {
            cout << endl << "Movimiento NO VALIDO: La casilla debe tener una pieza" << ' ' << (color=='B'?"negra":"blanca");
            return false;
        }
    } else if(casilla != nullptr){
        cout << "Movimiento NO VALIDO: La casilla tiene que estar vacia" << endl;
        return false;
    }
    cout << "Movimiento VALIDO." << endl;
    primerMovimiento = false;
    return true;
}







// ---- Torre ---------------------------------

CTorre::CTorre():CPieza() {icono[0] = 'T';}

CTorre::CTorre(int y, int x, char c): CPieza(y, x, c) {icono[0]='T';}

bool CTorre::confirmarMovimiento(int y, int x, CPieza* casilla) {
    cout << endl;
    if((posY==y) and (posX==x)){
        cout << "Movimiento NO VALIDO: La posicion de destino no puede ser igual a la posicion de la pieza." << endl;
        return false;
    }
    if((posY==y)==(posX==x)){
        cout << "Movimiento NO VALIDO: La torre no puede avanzar a esa posicion."  << endl;
        return false;
    }
    if(casilla!=nullptr){
        if(casilla->getColor()==color){
            cout << "Movimiento NO VALIDO: Una pieza del mismo color ocupa la posicion." << endl;
            return false;
        }
    }
    cout << "Movimiento VALIDO." << endl;
    return true;
}







// ---- Caballo -----------------------------------

CCaballo::CCaballo():CPieza() {icono[0] = 'C';}

CCaballo::CCaballo(int y, int x, char c): CPieza(y, x, c) {icono[0]='C';}

bool CCaballo::confirmarMovimiento(int y, int x, CPieza* casilla) {
    cout << endl;
    if((posY==y) and (posX==x)) {
        cout << "Movimiento NO VALIDO: La posicion de destino no puede ser igual a la posicion de la pieza." << endl;
        return false;
    }
    if(((posX-x)*(posX-x)+(posY-y)*(posY-y))!=5) {
        cout << "Movimiento NO VALIDO: El caballo no puede avanzar a esa posicion." << endl;
        return false;
    }
    if(casilla!=nullptr) {
        if(casilla->getColor()==color) {
            cout << "Movimiento NO VALIDO: Una pieza del mismo color ocupa la posicion." << endl;
            return false;
        }
    }
    cout << "Movimiento VALIDO." << endl;
    return true;
}







// ---- Alfil ---------------------------------

CAlfil::CAlfil():CPieza() {icono[0] = 'A';}

CAlfil::CAlfil(int y, int x, char c): CPieza(y, x, c) {icono[0]='A';}

bool CAlfil::confirmarMovimiento(int y, int x, CPieza* casilla) {
    cout << endl;
    if((posY==y) and (posX==x)){
        cout << "Movimiento NO VALIDO: La posicion de destino no puede ser igual a la posicion de la pieza." << endl;
        return false;
    }
    if(abs(posX-x)!=abs(posY-y)){
        cout << "Movimiento NO VALIDO: El alfil no puede avanzar a esa posicion." << endl;
        return false;
    }
    if(casilla!=nullptr){
        if(casilla->getColor()==color){
            cout << "Movimiento NO VALIDO: Una pieza del mismo color ocupa la posicion." << endl;
            return false;
        }
    }
    cout << "Movimiento VALIDO." << endl;
    return true;
}







// ---- Reina ---------------------------------

CReina::CReina():CPieza() {icono[0] = 'Q';}

CReina::CReina(int y, int x, char c): CPieza(y, x, c) {icono[0]='Q';}

bool CReina::confirmarMovimiento(int y, int x, CPieza* casilla) {
    cout << endl;
    if((posY==y) and (posX==x)){
        cout << "Movimiento NO VALIDO: La posicion de destino no puede ser igual a la posicion de la pieza." << endl;
        return false;
    }
    if((abs(posX-x)!=abs(posY-y)) && ((posY==y)==(posX==x))){
        cout << "Movimiento NO VALIDO: La reina no puede avanzar a esa posicion." << endl;
        return false;
    }
    if(casilla!=nullptr){
        if(casilla->getColor()==color){
            cout << "Movimiento NO VALIDO: Una pieza del mismo color ocupa la posicion." << endl;
            return false;
        }
    }
    cout << "Movimiento VALIDO." << endl;
    return true;
}







// ---- Rey -----------------------------------

CRey::CRey():CPieza() {icono[0] = 'K';}

CRey::CRey(int y, int x, char c): CPieza(y, x, c) {icono[0]='K';}

CRey::~CRey() {
    cout << endl << "Rey" << ' ' << (color=='B'?"blanco":"negro") << ' ' << "eliminado.";
    cout << endl << "Oprima 0 para terminar la partida.";
}

bool CRey::confirmarMovimiento(int y, int x, CPieza* casilla) {
    cout << endl;
    if((posY==y) and (posX==x)){
        cout << "Movimiento NO VALIDO: La posicion de destino no puede ser igual a la posicion de la pieza." << endl;
        return false;
    }
    if(abs(posX-x)>1 || abs(posY-y)>1){
        cout << "Movimiento NO VALIDO: El rey no puede avanzar a esa posicion." << endl;
        return false;
    }
    if(casilla!=nullptr){
        if(casilla->getColor()==color){
            cout << "Movimiento NO VALIDO: Una pieza del mismo color ocupa la posicion." << endl;
            return false;
        }
    }
    cout << "Movimiento VALIDO." << endl;
    return true;
}