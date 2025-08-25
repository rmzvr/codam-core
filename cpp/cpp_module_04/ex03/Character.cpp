#include "Character.hpp"
#include "AMateria.hpp"

ICharacter::~ICharacter()
{
	
}

Character::Character( std::string const &name ) : _name(name), _materiasAmount(0)
{
	std::cout << "Character parameterized constructor called" << std::endl;
	for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
	{
		this->_materias[i] = nullptr;
	}
}

std::string const &Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria *m)
{
	if (this->_materiasAmount < MAX_MATERIAS_AMOUNT)
	{
		this->_materias[this->_materiasAmount] = m;
		this->_materiasAmount++;
	}
}

void Character::unequip(int idx)
{
	(void) idx; //! TODO
}

void Character::use(int idx, ICharacter &target)
{
	this->_materias[idx]->use(target);
}

Character::~Character()
{
	for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
	{
		if (this->_materias[i] != nullptr)
		{
			delete this->_materias[i];
		}
	}
}
