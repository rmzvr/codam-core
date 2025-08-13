#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << this->_name << " born." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " died." << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
