#include "Application.h"
#include "Marquee1.h"
<<<<<<< HEAD
#include <Windows.h>
=======
#include "login/Include.h"
>>>>>>> 53729ad15689531e97ecbdd0f3ad22f407db2e19


int Application::run()
{
    loginRegisterApp();
    return 0;
}

void Application::loginRegisterApp()
{
    std::vector<MenuOption> menu_item
    {
        {1, "Login", logearse},
        {2, "Register", registrarse},
        {3, "SALIR", exit_program}
    };

    Menu menu{ menu_item };
    menu.navigation();
}

void Application::logearse()
{
    system("pause");
    system("cls");
    Login log;
    if (log.login() == 1) {
        init();
    }
    else {
        cout << "Usuario Incorrecto" << endl;
        Sleep(600);
    }
    loginRegisterApp();
}

void Application::registrarse()
{
    system("pause");
    system("cls");
    Login log;
    if (log.sigin() == 1) {
    }
    else {
        cout << "Usuario Incorrecto" << endl;
        Sleep(600);
    }
    loginRegisterApp();
}

void Application::init()
{
<<<<<<< HEAD
    
    std::thread t1(Marquee::Marquee::transicion, " ESPE ");
    std::vector<MenuOption> menu_item
    {
        {1, "Jugar", OPC1},
        {2, "Configuraciones", OPC3},
=======
    std::thread t1(Marquee::Marquee::transicion, " Hello There ");
    std::vector<MenuOption> menu_item
    {
        {1, "Partida Nueva", nuevoJuego},
        {2, "Cargar Backup", cargarBackup},
>>>>>>> 53729ad15689531e97ecbdd0f3ad22f407db2e19
        {3, "SALIR", exit_program}
    };

    Menu menu{ menu_item };
    menu.navigation();
    
}


void Application::exit_program()
{
<<<<<<< HEAD
    std::cout << "\x1B[2J\x1B[H";
=======
    
    system("cls");
>>>>>>> 53729ad15689531e97ecbdd0f3ad22f407db2e19
    std::cout << "\n\nHasta la proxima\n\n";
    Sleep(800);
    exit(0);
}

<<<<<<< HEAD
void Application::OPC1() 
{
    estop();
    //system("cls");
    std::cout << "Opc1"<<std::endl;
    system("pause");
=======
void Application::nuevoJuego() {
    estop();
    system("pause");
    system("cls");
>>>>>>> 53729ad15689531e97ecbdd0f3ad22f407db2e19
    
    CPartida prueba;
    prueba.ejecutarPartida();

    init();
}

void Application::cargarBackup()
{
    estop();
    system("pause");
    system("cls");
    CPartida back;
    back.cargarBackup();
    back.ejecutarPartida();
    init();
}

void Application::estop()
{
/*PRESIONA TECLA ALT PARA DETENER MARQUESINA*/
    INPUT ip;

    // Set up a generic keyboard event.
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0; // hardware scan code for key
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    // Press the "A" key
    ip.ki.wVk = 0x1B; // virtual-key code for the "a" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "A" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
}

<<<<<<< HEAD
void Application::OPC2()
{
    estop();
    std::cout << "\x1B[2J\x1B[H";
    std::cout << "\n\n\topcion 2" << std::endl;
    system("pause");
    init();
}

void Application::OPC3()
{
    estop();
    std::vector<MenuOption> menu_item
    {
        {1, "Crear Backup", OPC4},
        {2, "Restaurar Backup", OPC2},
        {3, "SALIR", exit_program}
    };

    Menu menu{ menu_item };
    menu.navigation();
}

void Application::OPC4()
{
    estop();
    system("cls");
    std::cout << "opcion 4" << std::endl;
    system("pause");
    init();
}
=======

>>>>>>> 53729ad15689531e97ecbdd0f3ad22f407db2e19
