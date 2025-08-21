#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("scavTrap", 100, 50, 20), _isInGateKeeperMode(false)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name, 100, 50, 20), _isInGateKeeperMode(false)
{
	std::cout << "ScavTrap parameterized constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = other;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &other)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->setName(other.getName());
		this->setHitPoints(other.getHitPoints());
		this->setEnergyPoints(other.getEnergyPoints());
		this->setAttackDamage(other.getAttackDamage());
	}
	return (*this);
}

void	ScavTrap::guardGate()
{
	if (this->_isInGateKeeperMode == true)
	{
		std::cout << "Gate keeper mode deactivated" << std::endl;
		this->_isInGateKeeperMode = false;
	}
	else
	{
		std::cout << "Gate keeper mode activated" << std::endl;
		this->_isInGateKeeperMode = true;
	}
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->getHitPoints() == 0)
	{
		std::cout
				<< "ScavTrap " << this->getName()
				<< " destroyed!"
				<< std::endl;
		return;
	}
	if (this->getEnergyPoints() == 0)
	{
		std::cout
				<< "ScavTrap " << this->getName()
				<< " don't have enough energy to attack!"
				<< std::endl;
		return;
	}
	std::cout
			<< "ScavTrap " << this->getName()
			<< " attacks " << target
			<< ", causing " << this->getAttackDamage()
			<< " points of damage!"
			<< std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}