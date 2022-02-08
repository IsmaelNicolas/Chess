#pragma once
#include <string>
#include <Windows.h>
#include <vector>
#include "MenuOption.h"
#include <conio.h>
#include <iostream>



constexpr auto KEY_UP = 72;
constexpr auto KEY_DOWN = 80;
constexpr auto KEY_ENTER = 13;
constexpr auto KEY_ESCAPE = 27;


class Menu
{
public:

    Menu() = default;

    Menu(std::vector<MenuOption>);
    
    void navigation();
    
    void display(size_t);

    bool usarMouse(size_t*);


private:
    std::vector<MenuOption> menu_option_;
    HANDLE console_;
    HWND console_wnd = GetConsoleWindow();
    POINT cursor_pos;
    std::vector<int> cajitas;
};




