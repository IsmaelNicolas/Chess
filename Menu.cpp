#include "Menu.h"
#include"Application.h"

#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "user32.lib")


Menu::Menu(std::vector<MenuOption> options) : menu_option_(options)
{
    console_ = GetStdHandle(STD_OUTPUT_HANDLE);
}

bool isKeyDown(int vkey) {
    return GetKeyState(vkey) < 0;
}

void Menu::navigation()
{
    if (menu_option_.empty()) {
        return;
    }
        //Si todo sale bien no hay que cambiar la posicion de la esquina de la primera caja
    const int ESQUINA = 216;
    const int ANCHO = 23;
    
    for (size_t i = 0,j; i < menu_option_.size(); i++,j++)
    {
        if (i == 0) {
            cajitas.push_back(ESQUINA);
            cajitas.push_back(ESQUINA + ANCHO);
            j = 1;
        }
        else {
            cajitas.push_back(cajitas.at(j-1) + 1);
            cajitas.push_back(cajitas.at(j) +  ANCHO);
            j++;
        }
    }


    display(1);
    size_t i{ 1 };

    while (1)
    {
        if (GetAsyncKeyState(VK_END)) { break; }

        if (usarMouse(&i)) return;

        if (_kbhit())
        {
            Sleep(50);
            if (isKeyDown(VK_DOWN)) {
                i = (i < menu_option_.size()) ? i += 1 : i = menu_option_.size();
                display(i);
            }
            else if (isKeyDown(VK_UP))
            {
                i = (i > 1) ? i -= 1 : i = 1;
                display(i);
            }
            else if (isKeyDown(VK_RETURN)) {
                system("cls");
                menu_option_.at(i - 1).get_fuction()();
                break;
            }
            else if (isKeyDown(VK_END))
            {
                exit(0);
            }
        }
    }
}

void Menu::display(size_t option)
{

    system("cls");
    unsigned int i = 0;
    SetConsoleCursorPosition(console_, { 32,7 });
    std::cout << "Chess Game" << std::endl;
    while (i < menu_option_.size())
    {

        if (option == (i + 1))
        {
            SetConsoleCursorPosition(console_, { 32,short(i + 9) });
            SetConsoleTextAttribute(console_, BACKGROUND_GREEN);
            std::cout << "[" << menu_option_[i].get_number_option_() << "] " << menu_option_[i].get_title_() << std::endl;
            SetConsoleTextAttribute(console_, 15);
        }
        else
        {
            SetConsoleCursorPosition(console_, { 32,short(i + 9) });
            std::cout << "[" << menu_option_[i].get_number_option_() << "] " << menu_option_[i].get_title_() << std::endl;
        }
        i++;
    }
}

bool Menu::usarMouse(size_t* i) {

           
    if (GetCursorPos(&cursor_pos))
    {
        if (console_wnd && ScreenToClient(console_wnd, &cursor_pos))
        {
            std::wstring t = std::to_wstring(cursor_pos.x) + L"-" + std::to_wstring(cursor_pos.y);
            SetConsoleTitle(t.c_str());

            for (size_t i = 0; i < cajitas.size(); i+=2)
            {
                if (cursor_pos.y >= cajitas.at(i) && cursor_pos.y <= cajitas.at(i + 1)) {
                    Sleep(500);
                    display((i/2)+1);
                    if (GetAsyncKeyState(VK_RBUTTON)) {
                        menu_option_.at(((i / 2) + 1)-1).get_fuction()();
                        return true;
                    }
                }
            }
            return false;
        }
    }

}

