#include "CTabla.h"

CTabla::CTabla() : tamX{ X }, tamY{ Y }, numPiezas{ 32 }{
    // Crear el array dinamico de punteros a CPieza
    //puntero a CPieza permite trabajar diferentes clases hijas como si fueran las mismas 
    //polimorfismo -> CPieza* ->Variable polimorfica
    listaPiezas = new CPieza * [numPiezas];

    // Insertar las torres en la lista
    listaPiezas[0] = new CTorre(0, 0, 'B');
    listaPiezas[1] = new CTorre(0, 7, 'B');
    listaPiezas[2] = new CTorre(7, 0, 'N');
    listaPiezas[3] = new CTorre(7, 7, 'N');

    // Insertar los caballos en la lista
    listaPiezas[4] = new CCaballo(0, 1, 'B');
    listaPiezas[5] = new CCaballo(0, 6, 'B');
    listaPiezas[6] = new CCaballo(7, 1, 'N');
    listaPiezas[7] = new CCaballo(7, 6, 'N');

    // Insertar los alfiles en la lista
    listaPiezas[8] = new CAlfil(0, 2, 'B');
    listaPiezas[9] = new CAlfil(0, 5, 'B');
    listaPiezas[10] = new CAlfil(7, 2, 'N');
    listaPiezas[11] = new CAlfil(7, 5, 'N');

    // Insertar las reinas en la lista
    listaPiezas[12] = new CReina(0, 3, 'B');
    listaPiezas[13] = new CReina(7, 3, 'N');

    // Insertar los reyes en la lista
    listaPiezas[14] = new CRey(0, 4, 'B');
    listaPiezas[15] = new CRey(7, 4, 'N');

    // Insertar los peones en la lista
    for (int i = 0; i < tamX; i++) {
        listaPiezas[16 + 2 * i] = new CPeon(1, i, 'B');
        listaPiezas[17 + 2 * i] = new CPeon(6, i, 'N');
    }
}

CTabla::~CTabla() {
    for(int i=0; i<numPiezas; i++) {
        delete listaPiezas[i];
        listaPiezas[i] = nullptr;
    }
    delete[] listaPiezas;
}

void CTabla::imprimirTabla() {
    // Crear matriz NO DINAMICA de strings y llenarlos con strings vacios
    string tabla[8][8];
    for(int i=0; i<tamY; i++) {for(int j=0; j<tamX; j++) {tabla[i][j] = "";}}

    // Insertar los iconos de las piezas en la matriz
    for(int i=0; i<numPiezas; i++) {
        tabla[listaPiezas[i]->getPosY()][listaPiezas[i]->getPosX()] = listaPiezas[i]->getIcono();
    }

    // Imprimir la matriz
    // - Linea separadora más linea de casillas
    for(int i=int(tamY)-1; i>=0; i--){
        // Parte separadora
        cout << endl << string(2,' ');
        for(int j=0; j<tamX; j++){
            cout << std::setfill('-') << std::setw(5) << std::left << '+';
        }
        cout << '+' << endl;

        // Parte de las casillas
        cout << std::setfill(' ') << std::setw(2) << std::left << i+1;
        for(int j=0; j<tamX; j++){
            cout << std::setfill(' ') << std::setw(2) << std::left << '|';
            cout << std::setfill(' ') << std::setw(3) << std::left << tabla[i][j];
        }
        cout << '|';
    }

    // - Ultima linea separadora.
    cout << endl << string(2,' ');
    for(int i=0; i<tamX; i++){
        cout << std::setfill('-') << std::setw(5) << std::left << '+';
    }
    cout << '+';
    //  - Linea de letras
    cout <<  endl;
    cout << string(2,' ');
    for(int i=0; i<tamX; i++){
        cout << std::setfill(' ') << std::setw(5) << std::left << char('A'+i);
    }
    cout << ' ' << endl;
}

bool CTabla::posicionValida (string pos) const {
    if(pos.size()!=2) {return false;}
    if(not(pos[1]>='1' and pos[1]<'1'+tamY)) {return false;}
    if(not(pos[0]>='A' and pos[0]<'A'+tamX)) {return false;}
    return true;
}


CPieza* CTabla::buscarPieza(int y, int x){
    for(int i=0; i<numPiezas; i++){
        if (listaPiezas[i]->getPosY() == y and listaPiezas[i]->getPosX() == x)
        {return listaPiezas[i];}
    }
    return nullptr;
}

void CTabla::eliminarPieza(int y, int x){
    CPieza* eliminado = buscarPieza(y,x);
    if(eliminado != nullptr){
        CPieza** temp = new CPieza* [numPiezas-1];
        int cont = 0;
        for(int i=0; i<numPiezas; i++){
            if (eliminado->getPosX() != listaPiezas[i]->getPosX() || eliminado->getPosY() != listaPiezas[i]->getPosY()) {
                temp[cont] = listaPiezas[i];
                cont ++;
            }
        }
        delete[] listaPiezas;
        listaPiezas = temp;
        numPiezas --;
        delete eliminado;
    }
}

bool CTabla::moverPieza(int y1, int x1, int y2, int x2, bool turno) {
    CPieza* casillaInicio = buscarPieza(y1,x1);
    CPieza* casillaFinal = buscarPieza(y2,x2);
    if(casillaInicio == nullptr) {
        cout << endl << "Movimiento NO VALIDO: No hay una pieza en la posicion de inicio.";
        return false;
    }
    if(casillaInicio->getColor() != (turno?'B':'N')) {
        cout << endl << "Movimiento NO VALIDO: Solo se pueden elegir piezas";
        cout << ' ' << (turno?"blancas":"negras");
        return false;
    }
    if(not(casillaInicio->confirmarMovimiento(y2,x2,casillaFinal))) {
        return false;
    }
    if(casillaFinal != nullptr) {eliminarPieza(y2,x2);}
    casillaInicio->setPosY(y2);
    casillaInicio->setPosX(x2);
    return true;
}


