#pragma once
#include "MenuOption.h"
#include "Menu.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Header.h"
#include "CPartida.h"
#include "json.hpp"
#include <thread>
#include <windows.h>
#include <algorithm> 
using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::cin;

class Application
{
private:


	static void exit_program();
	
public:
	static void init();
	Application() {};
	static void nuevoJuego();
	static void estop();
	static void cargarBackup();
	static int run();
	static void loginRegisterApp();
	static void logearse();
	static void registrarse();
	std::vector <string> listarDirectorio(char* dir);
};

