#include "CPartida.h"

CPartida::CPartida(): turno(true), opcion(0) {}

void CPartida::anunciarGanador() const {
    cout << endl << "GANADOR: Piezas" << ' ' << (turno?"blancas":"negras");
}

void CPartida::ejecutarMovimiento() {
    cout << endl << "Movimiento";
    cout << endl << "Origen: ";
    cin >> posOrigen;
    cout << "Destino: ";
    cin >> posDestino;
    if(tablero.posicionValida(posOrigen) and tablero.posicionValida(posDestino)){
        if (tablero.moverPieza(posOrigen[1] - '1', posOrigen[0] - 'A', posDestino[1] - '1', posDestino[0] - 'A', turno)) {
            turno = !turno;
        }
    }
    else {cout << endl << "Los valores introducidos no son validos.";}
}

void CPartida::ejecutarPartida() {
    cout << endl << "INICIO DE LA PARTIDA" << endl;
    do {
        tablero.imprimirTabla();
        cout << endl << "Turno de las piezas" << ' ' << (turno?"blancas":"negras") << '.';
        cout << endl << "Opciones: ";
        cout << endl << " - 1: Mover una pieza";
        cout << endl << " - 0: Rendirse";
        cout << endl << endl << "Inserte un numero:" << ' ';        
        cin >> opcion;
        switch(opcion) {
            case 0:
                cout << endl << "Las piezas" << ' ' << (turno?"blancas":"negras") << ' ' << "se han rendido.";
                turno = !turno;
                anunciarGanador();
                break;
            case 1:
                ejecutarMovimiento();
                break;
            default:
                cout << endl << "Opcion NO VALIDA: Solo puede insertar 0 y 1.";
                break;
        }
    } while(opcion != 0);
    cout << endl << endl << "FIN DE LA PARTIDA" << endl;

}