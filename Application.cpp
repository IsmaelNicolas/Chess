#include "Application.h"
#include "Marquee1.h"
#include "login/Include.h"


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
    std::thread t1(Marquee::Marquee::transicion, " Hello There ");
    std::vector<MenuOption> menu_item
    {
        {1, "Partida Nueva", nuevoJuego},
        {2, "Cargar Backup", cargarBackup},
        {3, "SALIR", exit_program}
    };

    Menu menu{ menu_item };
    menu.navigation();
    
}

void Application::exit_program()
{
    
    system("cls");
    std::cout << "\n\nHasta la proxima\n\n";
    Sleep(800);
    exit(0);
}

void Application::nuevoJuego() {
    estop();
    system("pause");
    system("cls");
    
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


