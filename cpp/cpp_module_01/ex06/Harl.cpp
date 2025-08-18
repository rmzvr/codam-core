#include "Harl.hpp"

Harl::Harl
()
{}

Harl::~Harl
()
{}

void	Harl::_debug
()
{
	std::cout << "\033[32mDEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\033[0m" << std::endl;
}

void	Harl::_info
()
{
	std::cout << "\033[34mINFO: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\033[0m" << std::endl;
}

void	Harl::_warning
()
{
	std::cout << "\033[33mWARNING: I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\033[0m" << std::endl;
}

void	Harl::_error
()
{
	std::cout << "\033[31mERROR: This is unacceptable! I want to speak to the manager now.\033[0m" << std::endl;
}

void	Harl::complain
(std::string level)
{
	int			level_index = -1;
	std::string	levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR"};

	for (size_t i = 0; i < sizeof(levels) / sizeof(levels)[0]; i++)
	{
		if (levels[i] == level)
			level_index = i;
	}
	switch (level_index)
	{
		case DEBUG:
			this->_debug();
			// fallthrough
		case (INFO):
			this->_info();
			// fallthrough
		case WARNING:
			this->_warning();
			// fallthrough
		case ERROR:
			this->_error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}