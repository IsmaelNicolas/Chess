#pragma once
#include "MenuOption.h"
#include "Menu.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
class Application
{
private:

	static void init();

	static void exit_program();
	
	

public:

	static void OPC1();
	static void OPC2();
	static void OPC3();
	static void OPC4();
	static int run();
	
};

