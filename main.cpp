#include "Application.h"
#include <Windows.h>
#include<iostream>
#include "Marquee1.h"
#include <thread>

int main()
{
	
	/*
		Actualizar fuente de consola
	*/
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.nFont = 0;
	cfi.dwFontSize.Y = 24;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy(cfi.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	/*
		Actualizar size de consola
	*/
	HWND console_wnd = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console_wnd, &ConsoleRect);
	MoveWindow(console_wnd,ConsoleRect.left,ConsoleRect.top,900, 600, TRUE);


	/*
	Marquee mark1(" THEOOOOOOOOOOOOOOOOOOO ");
	mark1.transicion();
	
	*/


	return Application::run();
}

