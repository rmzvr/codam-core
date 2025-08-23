#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap
() :
	_name("diamondTrap")
{
	this->ClapTrap::setHitPoints(this->FragTrap::getDefaultHitPoints());
	this->ClapTrap::setEnergyPoints(this->ScavTrap::getDefaultEnergyPoints());
	this->ClapTrap::setAttackDamage(this->FragTrap::getDefaultAttackDamage());
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap
(
	std::string name
) :
	ClapTrap(name + "_clap_name"),
	ScavTrap(name + "_clap_name"),
	FragTrap(name + "_clap_name"),
	_name(name)
{
	this->ClapTrap::setHitPoints(this->FragTrap::getDefaultHitPoints());
	this->ClapTrap::setEnergyPoints(this->ScavTrap::getDefaultEnergyPoints());
	this->ClapTrap::setAttackDamage(this->FragTrap::getDefaultAttackDamage());
	std::cout << "DiamondTrap parameterized constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(
	DiamondTrap const &other
) :
	ClapTrap(other),
	ScavTrap(other),
	FragTrap(other)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=
(
	DiamondTrap const &other
)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->setName(other.getName());
		this->ClapTrap::setHitPoints(other.FragTrap::getDefaultHitPoints());
		this->ClapTrap::setEnergyPoints(other.ScavTrap::getDefaultEnergyPoints());
		this->ClapTrap::setAttackDamage(other.FragTrap::getDefaultAttackDamage());
	}
	return (*this);
}

void	DiamondTrap::setName( std::string name )
{
	this->_name = name;
}

std::string	DiamondTrap::getName() const
{
	return (this->_name);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "My name is " << this->getName() << std::endl;
	std::cout << "Mine clap trap name is " << this->ScavTrap::getName() << std::endl;
}

void DiamondTrap::showInfo()
{
	std::cout << "HP:     " << this->getHitPoints() << "\n";
	std::cout << "Energy: " << this->getEnergyPoints() << "\n";
	std::cout << "Attack: " << this->getAttackDamage() << "\n";
	std::cout << "=================\n";
}
