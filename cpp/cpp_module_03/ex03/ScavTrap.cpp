#include "ScavTrap.hpp"

const unsigned int	ScavTrap::_defaultHitPoints = 100;
const unsigned int	ScavTrap::_defaultEnergyPoints = 50;
const unsigned int	ScavTrap::_defaultAttackDamage = 20;

const unsigned int&	ScavTrap::getDefaultHitPoints()
{
	return ScavTrap::_defaultHitPoints;
}

const unsigned int&	ScavTrap::getDefaultEnergyPoints()
{
	return ScavTrap::_defaultEnergyPoints;
}

const unsigned int&	ScavTrap::getDefaultAttackDamage()
{
	return ScavTrap::_defaultAttackDamage;
}

ScavTrap::ScavTrap() : ClapTrap("scavTrap"), _isInGateKeeperMode(false)
{
	this->setHitPoints(this->getDefaultHitPoints());
	this->setEnergyPoints(this->getDefaultEnergyPoints());
	this->setAttackDamage(this->getDefaultAttackDamage());
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name), _isInGateKeeperMode(false)
{
	this->setHitPoints(this->getDefaultHitPoints());
	this->setEnergyPoints(this->getDefaultEnergyPoints());
	this->setAttackDamage(this->getDefaultAttackDamage());
	std::cout << "ScavTrap parameterized constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
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
		std::cout << this->getName() << "'s gate keeper mode deactivated" << std::endl;
		this->_isInGateKeeperMode = false;
	}
	else
	{
		std::cout << this->getName() << "'s gate keeper mode activated" << std::endl;
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
