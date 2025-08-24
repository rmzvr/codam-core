#include "FragTrap.hpp"

const unsigned int	FragTrap::_defaultHitPoints = 100;
const unsigned int	FragTrap::_defaultEnergyPoints = 100;
const unsigned int	FragTrap::_defaultAttackDamage = 30;

const unsigned int&	FragTrap::getDefaultHitPoints()
{
	return FragTrap::_defaultHitPoints;
}

const unsigned int&	FragTrap::getDefaultEnergyPoints()
{
	return FragTrap::_defaultEnergyPoints;
}

const unsigned int&	FragTrap::getDefaultAttackDamage()
{
	return FragTrap::_defaultAttackDamage;
}

FragTrap::FragTrap() : ClapTrap("fragTrap")
{
	this->setHitPoints(this->getDefaultHitPoints());
	this->setEnergyPoints(this->getDefaultEnergyPoints());
	this->setAttackDamage(this->getDefaultAttackDamage());
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	this->setHitPoints(this->getDefaultHitPoints());
	this->setEnergyPoints(this->getDefaultEnergyPoints());
	this->setAttackDamage(this->getDefaultAttackDamage());
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
