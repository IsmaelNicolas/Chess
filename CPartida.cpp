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
    std::cout << endl << "INICIO DE LA PARTIDA" << endl;
    std::string fileName = "partida.dat"; 
    std::ofstream outputFile;
    CPartida part{};
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
                std::cout << endl << "Las piezas" << ' ' << (turno?"blancas":"negras") << ' ' << "se han rendido.";
                turno = !turno;
                anunciarGanador();
                break;
            case 1:
                ejecutarMovimiento();
                break;
            case 2:   
                writeBinary(outputFile, *this, fileName);
                break;
            default:
                std::cout << endl << "Opcion NO VALIDA: Solo puede insertar 0 y 1.";
                break;
        }
    } while(opcion != 0 && opcion != 2);
    std::cout << endl << endl << "FIN DE LA PARTIDA" << endl;



}

void CPartida::readBinary(std::string& fileName, CPartida& someoneElse)
{

    //std::ofstream outputFile;
    //outputFile.open(fileName, std::ios::out| std::ios::binary);


    std::ifstream inputFile;
    inputFile.open(fileName.c_str(),std::ios::binary| std::ios::in);

    if (!inputFile.eof())
    {
        inputFile.read(reinterpret_cast<char*>(&someoneElse), sizeof(CPartida));
        //inputFile.read((char*)&someoneElse, sizeof(CPartida));
        //inputFile.close();
    }
    else
    {
        std::cout << "No existe backup " + fileName;
    }
    inputFile.close();
    //outputFile.close();
}


void CPartida::writeBinary(std::ofstream& outputFile, CPartida& someone, std::string& fileName)
{
    outputFile.open(fileName.c_str(), std::ios::out | std::ios::binary);
    if (outputFile.is_open())
    {
        outputFile.write(reinterpret_cast<char*>(&someone), sizeof(CPartida));
        //outputFile.close();
    }
    else
    {
        std::cout << "No existe file " + fileName + "\n";
    }
    outputFile.close();
}

void CPartida::cargarBackup()
{
    
    std::cout << "\n\n\tMenu de Backups" << std::endl;
    std::string fileName = "partida.dat";
    readBinary(fileName, *this);
    

}
