#include "Menu.h"
#include"Application.h"
#include <thread>
#include <math.h>

#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "user32.lib")

void setcursor(bool visible, DWORD size) // set bool visible = 0 - invisible, bool visible = 1 - visible
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    if (size == 0)
    {
        size = 20;	// default cursor size Changing to numbers from 1 to 20, decreases cursor width
    }
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console, &lpCursor);
}

Menu::Menu(std::vector<MenuOption> options) : menu_option_(options)
{
    console_ = GetStdHandle(STD_OUTPUT_HANDLE);
    setcursor(0, 10);
}

bool isKeyDown(int vkey) {
    return GetKeyState(vkey) < 0;
}

void Menu::navigation()
{
    if (menu_option_.empty()) {
        return;
    }

    display(1);
    size_t i{ 1 };

    while (1)
    {
        if (GetAsyncKeyState(VK_END)) { break; }
        
        usarMouse(&i);

        if (_kbhit())
        {
            Sleep(50);
            if (isKeyDown(VK_DOWN)) {
                i = (i < menu_option_.size() ) ? i+=1 : i= menu_option_.size();
                display(i);
            }
            else if (isKeyDown(VK_UP)) 
            {
                i = (i > 1) ? i -= 1 : i =1;
                display(i);

            }
            else if (isKeyDown(VK_RETURN)) {
                system("cls");
                menu_option_.at(i - 1).get_fuction()();
                display(i);
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

void Menu::usarMouse(size_t* i) {

           
    if (GetCursorPos(&cursor_pos))
    {
        if (console_wnd && ScreenToClient(console_wnd, &cursor_pos))
        {
            std::wstring t = std::to_wstring(cursor_pos.x) + L"-" + std::to_wstring(cursor_pos.y);
            SetConsoleTitle(t.c_str());


            /*auto f = [](int x) {return (int)(-1.6667*pow(x,4) + 13.3335 * pow(x,3) - 33.3336 * pow(x,2) + 51.6668 * x + 210); };

            if ((cursor_pos.x>=360 && cursor_pos.x <= 570) && (cursor_pos.y >= f(i) && cursor_pos.y <= f(i+1))) {
                display(i);
                std::cout << i<<std::endl;
            }*/

            if ((cursor_pos.x >= 360 && cursor_pos.x <= 570) && (cursor_pos.y >= 210 && cursor_pos.y <= 240))
            {
                *i = 1;
                display(*i);
            }
            if ((cursor_pos.x >= 360 && cursor_pos.x <= 570) && (cursor_pos.y >= 240 && cursor_pos.y <= 260))
            {
                *i = 2;
                display(*i);
            }
            if ((cursor_pos.x >= 360 && cursor_pos.x <= 570) && (cursor_pos.y >= 260 && cursor_pos.y <= 290))
            {
                *i = 3;
                display(*i);
            }
            if ((cursor_pos.x >= 360 && cursor_pos.x <= 570) && (cursor_pos.y >= 290 && cursor_pos.y <= 310))
            {
                *i = 4;
                display(*i);
            }

        }
    }

}