#include "ClapTrap.hpp"

const unsigned int	ClapTrap::_defaultHitPoints = 10;
const unsigned int	ClapTrap::_defaultEnergyPoints = 10;
const unsigned int	ClapTrap::_defaultAttackDamage = 0;

const unsigned int&	ClapTrap::getDefaultHitPoints()
{
	return ClapTrap::_defaultHitPoints;
}

const unsigned int&	ClapTrap::getDefaultEnergyPoints()
{
	return ClapTrap::_defaultEnergyPoints;
}

const unsigned int&	ClapTrap::getDefaultAttackDamage()
{
	return ClapTrap::_defaultAttackDamage;
}

ClapTrap::ClapTrap
() : 
	_name("clapTrap"),
	_hitPoints(this->getDefaultHitPoints()),
	_energyPoints(this->getDefaultEnergyPoints()),
	_attackDamage(this->getDefaultAttackDamage())
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap
(
	std::string name
) : 
	_name(name),
	_hitPoints(this->getDefaultHitPoints()),
	_energyPoints(this->getDefaultEnergyPoints()),
	_attackDamage(this->getDefaultAttackDamage())
{
	std::cout << "ClapTrap parameterized constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(ClapTrap const &other)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (this->getHitPoints() == 0)
	{
		std::cout
				<< "ClapTrap " << this->getName()
				<< " destroyed!"
				<< std::endl;
		return;
	}
	if (this->getEnergyPoints() == 0)
	{
		std::cout
				<< "ClapTrap " << this->getName()
				<< " don't have enough energy to attack!"
				<< std::endl;
		return;
	}
	std::cout
			<< "ClapTrap " << this->getName()
			<< " attacks " << target
			<< ", causing " << this->getAttackDamage()
			<< " points of damage!"
			<< std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getHitPoints() == 0)
	{
		std::cout
				<< "ClapTrap " << this->getName()
				<< " destroyed!"
				<< std::endl;
		return;
	}
	std::cout
			<< "ClapTrap " << this->getName()
			<< " took " << amount
			<< " damage and lost health points!"
			<< std::endl;
	if (this->getHitPoints() < amount)
	{
		this->setHitPoints(0);
	}
	else
	{
		this->setHitPoints(this->getHitPoints() - amount);
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getHitPoints() == 0)
	{
		std::cout
				<< "ClapTrap " << this->getName()
				<< " destroyed!"
				<< std::endl;
		return;
	}
	if (this->getEnergyPoints() == 0)
	{
		std::cout
				<< "ClapTrap " << this->getName()
				<< " don't have enough energy for being repaired!"
				<< std::endl;
		return;
	}
	std::cout
			<< "ClapTrap " << this->getName()
			<< " repaired itself, restoring "
			<< amount << " health points!"
			<< std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void	ClapTrap::setName( std::string name )
{
	this->_name = name;
}

void	ClapTrap::setHitPoints( unsigned int hitPoints )
{
	this->_hitPoints = hitPoints;
}

void	ClapTrap::setEnergyPoints( unsigned int energyPoints )
{
	this->_energyPoints = energyPoints;

}

void	ClapTrap::setAttackDamage( unsigned int attackDamage )
{
	this->_attackDamage = attackDamage;
}

std::string	ClapTrap::getName() const
{
	return (this->_name);
}

unsigned int	ClapTrap::getHitPoints() const
{
	return (this->_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints() const
{
	return (this->_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage() const
{
	return (this->_attackDamage);
}

void ClapTrap::showInfo()
{
	std::cout << "\n=== " << this->getName() << " ===\n";
	std::cout << "HP:     " << this->getHitPoints() << "\n";
	std::cout << "Energy: " << this->getEnergyPoints() << "\n";
	std::cout << "Attack: " << this->getAttackDamage() << "\n";
	std::cout << "=================\n";
}
