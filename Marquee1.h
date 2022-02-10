#pragma once
#include <iostream>
#include <string.h>
#include <windows.h>
#include <thread>
#include <conio.h>
#include "Application.h"

int index = 0;
namespace Marquee
{

    class Marquee
    {
    public:

        //Marquee(string);

        static void cursorHide();

        static void printToCoordinates(int x, int y, std::string format, ...);

        static COORD GetConsoleCursorPosition(HANDLE hConsoleOutput);

        static void marquee(std::string);

        static void transicion(std::string);

        static void finalizar();


    private:
        
    };

    //Marquee::Marquee(string marquee)
    //{
    //	this->marquesina = marquee;
    //}

    void Marquee::cursorHide()
    {
        HANDLE hwnd;
        hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO info;

        info.bVisible = 0;
        info.dwSize = 1;

        SetConsoleCursorInfo(hwnd, &info);
    }

    void Marquee::printToCoordinates(int x, int y, std::string format, ...)
    {
        const char* c = format.c_str();
        va_list args;
        va_start(args, format);
        printf("\033[%d;%dH", x, y);
        vprintf(c, args);
        va_end(args);
        fflush(stdout);
    }

    COORD Marquee::GetConsoleCursorPosition(HANDLE hConsoleOutput)
    {
        CONSOLE_SCREEN_BUFFER_INFO cbsi;
        if (GetConsoleScreenBufferInfo(hConsoleOutput, &cbsi))
        {
            return cbsi.dwCursorPosition;
        }
        else
        {
            COORD invalid = { 0, 0 };
            return invalid;
        }
    }

    void Marquee::marquee(std::string mensaje)
    {
        std::string logo = mensaje;
        int velocidad = 600;
        Sleep(600);
        cursorHide();
        int stringSize = logo.length();
        std::string msg;
        bool ciclo = true;
        for (index; ciclo == true; index++)
        {
            msg = "\t\t\t\t" + logo.substr(index % stringSize) + logo.substr(0, index % stringSize);
            printToCoordinates(0, 0, msg);
            Sleep(velocidad);
            if (GetAsyncKeyState(VK_ESCAPE)) {
                Sleep(50);
                ciclo = false;
                break;
                
            }
        }
    }

    void Marquee::transicion(std::string mensaje)
    {
        //Application ap;
        //std::thread t2(&ap.run);
        COORD cord;
        cord = GetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE));
        marquee(mensaje);
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
        //system("pause");
        //t2.join();
        cord.Y++;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
    }

    inline void Marquee::finalizar()
    {
        std::terminate();
    }

};


