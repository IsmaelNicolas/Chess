#include "Application.h"
#include "Marquee1.h"

int Application::run()
{
    init();

    return 0;
}

void Application::init()
{
    std::thread t1(Marquee::Marquee::transicion, "Imprimete carajo");
    std::cout << "opcion 1" << std::endl;
    std::vector<MenuOption> menu_item
    {
        {1, "Jugar", OPC1},
        {2, "Configuraciones", OPC2},
        {3, "OPCION 3", OPC3},
        {4, "SALIR", exit_program}
    };

    Menu menu{ menu_item };
    menu.navigation();
    
}

void Application::exit_program()
{
    system("cls");
    std::cout << "\n\nHasta la proxima\n\n";
    Sleep(500);
    exit(0);
}

void Application::OPC1() {
    estop();
    system("cls");

    
    CPartida prueba;
    prueba.ejecutarPartida();
    
    

    //init();
    //std::string a;
    //std::cin >> a;
    //std::cout << a;
    //system("pause");
    init();
}

/*PRESIONA TECLA ALT PARA DETENER MARQUESINA*/
void Application::estop()
{
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

void Application::OPC2()
{
    system("cls");
    std::cout << "\n\n\topcion 2" << std::endl;
    //char aa;
    //std::cin.ignore();

    //std::cin >> aa;
    //std::cout << aa;
    system("pause");
    init();
}

void Application::OPC3()
{
    std::vector<MenuOption> menu_item
    {
        {1, "Opcion 4", OPC4},
        {2, "SALIR", exit_program}
    };

    Menu menu{ menu_item };
    menu.navigation();
}

void Application::OPC4()
{
    system("cls");
    std::cout << "opcion 4" << std::endl;
    system("pause");
    init();
}