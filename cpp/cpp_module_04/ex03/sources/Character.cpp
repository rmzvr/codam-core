#include "Character.hpp"
#include "AMateria.hpp"

ICharacter::~ICharacter()
{
	
}

Character::Character() : _name("defaultName"), _materiasAmount(0)
{
	#ifdef DEBUG
		std::cout << "Character default constructor called" << std::endl;
	#endif
	for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
	{
		this->_materias[i] = nullptr;
	}
}

Character::Character( std::string const &name ) : _name(name), _materiasAmount(0)
{
	#ifdef DEBUG
		std::cout << "Character parameterized constructor called" << std::endl;
	#endif
	for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
	{
		this->_materias[i] = nullptr;
	}
}

Character::Character(Character const &other)
{
	#ifdef DEBUG
		std::cout << "Character copy constructor called" << std::endl;
	#endif
	*this = other;
}

Character &Character::operator=(const Character & other)
{
	#ifdef DEBUG
		std::cout << "Character copy assignment operator called" << std::endl;
	#endif
	if (this != &other)
	{
		this->_name = other._name;
		this->_materiasAmount = other._materiasAmount;
		for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
		{
			this->_materias[i] = other._materias[i];
		}
	}
	return (*this);
}

Character::~Character()
{
	#ifdef DEBUG
		std::cout << "Character destructor called" << std::endl;
	#endif
	for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
	{
		if (this->_materias[i] != nullptr)
		{
			this->_materias[i] = nullptr;
		}
	}
}

std::string const &Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria *m)
{
	if (m != nullptr)
	{
		if (this->_materiasAmount < MAX_MATERIAS_AMOUNT)
		{
			this->_materias[this->_materiasAmount] = m;
			this->_materiasAmount++;
		}
	}
	std::cout << "ERROR" << std::endl;
}

void Character::unequip(int idx)
{
	this->_materias[idx] = nullptr;
}

void Character::use(int idx, ICharacter &target)
{
	if (this->_materias[idx] != nullptr)
	{
		this->_materias[idx]->use(target);
	}
}
