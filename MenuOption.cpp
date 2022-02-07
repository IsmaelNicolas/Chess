#include "MenuOption.h"

MenuOption::MenuOption(unsigned int number, const std::string title, Menu_Processing_Function_Ptr fuction)
	: number_option_(number), title_(title), p_processing_function_(fuction)
{

}