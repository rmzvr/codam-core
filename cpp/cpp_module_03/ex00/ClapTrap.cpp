#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	std::cout
			<< "ClapTrap "
			<< this->_name
			<< " attacks "
			<< target
			<< ", causing "
			<< this->_attackDamage
			<< " points of damage!"
			<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout
			<< "ClapTrap "
			<< this->_name
			<< " was attacked"
			<< ", causing lost "
			<< amount
			<< " points of hit points!"
			<< std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
}
