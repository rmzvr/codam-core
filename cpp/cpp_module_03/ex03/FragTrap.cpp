#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("fragTrap")
{
	std::cout << "FragTrap before - attackDamage: " << this->getAttackDamage() << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << "FragTrap after - attackDamage: " << this->getAttackDamage() << std::endl;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << "FragTrap parameterized constructor called" << std::endl;
}

FragTrap::FragTrap( FragTrap const &other ) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const &other)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->setName(other.getName());
		this->setHitPoints(other.getHitPoints());
		this->setEnergyPoints(other.getEnergyPoints());
		this->setAttackDamage(other.getAttackDamage());
	}
	return (*this);
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << this->getName() << " requests a positive high five!" << std::endl;
}

const int	FragTrap::_defaultHitPoints = 100;
const int	FragTrap::_defaultEnergyPoints = 100;
const int	FragTrap::_defaultAttackDamage = 30;

const int&	FragTrap::getDefaultHitPoints()
{
	return FragTrap::_defaultHitPoints;
}

const int&	FragTrap::getDefaultEnergyPoints()
{
	return FragTrap::_defaultEnergyPoints;
}

const int&	FragTrap::getDefaultAttackDamage()
{
	return FragTrap::_defaultAttackDamage;
}
