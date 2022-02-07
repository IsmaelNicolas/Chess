#include "Application.h"
#include <Windows.h>
#include<iostream>

int main()
{
    HWND console_wnd = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console_wnd, &ConsoleRect);



    MoveWindow(console_wnd,
        ConsoleRect.left,
        ConsoleRect.top,
        900, 600, TRUE);

    return Application::run();
}

  