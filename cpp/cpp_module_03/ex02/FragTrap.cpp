#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("fragTrap")
{
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
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