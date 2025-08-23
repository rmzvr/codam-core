#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("clapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
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
	if (this->_hitPoints == 0)
	{
		std::cout
				<< "ClapTrap " << this->_name
				<< " destroyed!"
				<< std::endl;
		return;
	}
	if (this->_energyPoints == 0)
	{
		std::cout
				<< "ClapTrap " << this->_name
				<< " don't have enough energy to attack!"
				<< std::endl;
		return;
	}
	std::cout
			<< "ClapTrap " << this->_name
			<< " attacks " << target
			<< ", causing " << this->_attackDamage
			<< " points of damage!"
			<< std::endl;
	this->_energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout
				<< "ClapTrap " << this->_name
				<< " destroyed!"
				<< std::endl;
		return;
	}
	std::cout
			<< "ClapTrap " << this->_name
			<< " took " << amount
			<< " damage and lost health points!"
			<< std::endl;
	if (this->_hitPoints < amount)
	{
		this->_hitPoints = 0;
	}
	else
	{
		this->_hitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout
				<< "ClapTrap " << this->_name
				<< " destroyed!"
				<< std::endl;
		return;
	}
	if (this->_energyPoints == 0)
	{
		std::cout
				<< "ClapTrap " << this->_name
				<< " don't have enough energy for being repaired!"
				<< std::endl;
		return;
	}
	std::cout
			<< "ClapTrap " << this->_name
			<< " repaired itself, restoring "
			<< amount << " health points!"
			<< std::endl;
	this->_energyPoints -= 1;
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
	std::cout << "\n=== " << this->_name << " ===\n";
	std::cout << "HP:     " << this->_hitPoints << "\n";
	std::cout << "Energy: " << this->_energyPoints << "\n";
	std::cout << "Attack: " << this->_attackDamage << "\n";
	std::cout << "=================\n";
}
