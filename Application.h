#pragma once
#include "MenuOption.h"
#include "Menu.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>

#include "Header.h"
#include "CPartida.h"

#include <thread>
class Application
{
private:

	static void init();

	static void exit_program();
	
	

public:

	Application() {};
	static void nuevoJuego();
	static void estop();
	static void cargarBackup();
	static int run();
	static void loginRegisterApp();
	static void logearse();
	static void registrarse();
	
};

