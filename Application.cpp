#include "Application.h"
#include <iostream>
#include <windows.h>
#include <thread>

int Application::run()
{
    init();
    return 0;
}


void Application::init()
{
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
    exit(0);
}



void Application::OPC1() {
    system("cls");
    std::cout << "opcion 1" << std::endl;
    system("pause");
    init();
}

void Application::OPC2()
{
    system("cls");
    std::cout << "opcion 2" << std::endl;
    system("pause");
    init();
}

void Application::OPC3()
{
    system("cls");
    std::cout << "opcion 3" << std::endl;
    system("pause");
    init();
}

void Application::OPC4()
{
    system("cls");
    std::cout << "opcion 4" << std::endl;
    system("pause");
    init();
}