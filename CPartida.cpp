#include "CPartida.h"
using namespace nlohmann;
using ordered_json = nlohmann::ordered_json;

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
    std::cout << endl << "INICIO DE LA PARTIDA" << endl;
    do {
        tablero.imprimirTabla();
        std::cout << endl << "Turno de las piezas" << ' ' << (turno?"blancas":"negras") << '.';
        std::cout << endl << "Opciones: ";
        std::cout << endl << " - 1: Mover una pieza";
        std::cout << endl << " - 2: Backup y salir";
        std::cout << endl << " - 0: Rendirse";
        std::cout << endl << endl << "Inserte un numero:" << ' ';
        cin >> opcion;
        switch(opcion) {
            case 0:
                //std::cout << endl << "Las piezas" << ' ' << (turno?"blancas":"negras") << ' ' << "se han rendido.";
                //turno = !turno;
                //anunciarGanador();
                break;
            case 1:
                ejecutarMovimiento();
                break;
            case 2:   
                hacerBackup();
                break;
            default:
                std::cout << endl << "Opcion NO VALIDA: Solo puede insertar 0 y 1.";
                break;
        }
    } while(opcion != 0 && opcion !=2 );
    //std::cout << endl << endl << "FIN DE LA PARTIDA" << endl;

}

void CPartida::hacerBackup() {


    string filename = "./backups/"+nombreFile();
    json partidaPiezas;
    string key;
    int j = 10;
    for (size_t i = 0; i < tablero.numPiezas; i++,j++)
    {
        partidaPiezas[std::to_string(j)]["posX"] = tablero.listaPiezas[i]->getPosX();
        partidaPiezas[std::to_string(j)]["posY"] = tablero.listaPiezas[i]->getPosY();
        partidaPiezas[std::to_string(j)]["color"] = tablero.listaPiezas[i]->getColor();
        partidaPiezas[std::to_string(j)]["icono"] = tablero.listaPiezas[i]->getIcono();
    }

    std::ofstream file(filename+"_1" + ".json");
    file << std::setw(4) << partidaPiezas << std::endl;
    file.close();

    json partidaPosicion =
    {
          {"opcion", opcion},
          {"posOrigen", posOrigen},
          {"posDestino", posDestino},
          {"turno", turno},
          {"tamX", tablero.tamX},
          {"tamY", tablero.tamY},
          {"numPiezas", tablero.numPiezas}
    };
    
    std::ofstream file2(filename + "_2" + ".json");

    file2 << std::setw(4) << partidaPosicion << std::endl;
    file2.close();


}

void CPartida::cargarBackupFile(string filename)
{
    string s = filename + "_2.json";
    std::ifstream i(s);
    json j;
    i >> j;

    this->tablero.numPiezas = j["numPiezas"].get<unsigned int>();
    this->opcion = j["opcion"].get<int>();
    this->posDestino = j["posDestino"].get<string>();
    this->posOrigen = j["posOrigen"].get<string>();
    this->tablero.tamX = j["tamX"].get<unsigned int>();
    this->tablero.tamY = j["tamY"].get<unsigned int>();
    this->turno = j["turno"].get<bool>();

    

    i.close();
    this->tablero.cargarPiezas(filename);
    system("cls");
    system("pause");
    this->ejecutarPartida();
}

string CPartida::nombreFile()
{
    auto end = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    string s = string(std::ctime(&end_time));
    std::replace(s.begin(), s.end(), ':', '-');
    s.pop_back();

    return s;
}

