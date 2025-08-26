#include "Character.hpp"
#include "AMateria.hpp"

ICharacter::~ICharacter()
{}

Character::Character() : _name("defaultName"), _materiasAmount(0), _unequipedMateriasAmount(0), _unequipedMateriasMaxAmount(4)
{
	#ifdef DEBUG
		std::cout << "Character default constructor called" << std::endl;
	#endif
	for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
	{
		this->_materias[i] = nullptr;
	}
	this->_unequipedMaterias = new AMateria*[this->_unequipedMateriasMaxAmount];
	for (size_t i = 0; i < this->_unequipedMateriasMaxAmount; i++)
	{
		this->_unequipedMaterias[i] = nullptr;
	}
}

Character::Character( std::string const &name ) : _name(name), _materiasAmount(0), _unequipedMateriasAmount(0), _unequipedMateriasMaxAmount(4)
{
	#ifdef DEBUG
		std::cout << "Character parameterized constructor called" << std::endl;
	#endif
	for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
	{
		this->_materias[i] = nullptr;
	}
	this->_unequipedMaterias = new AMateria*[this->_unequipedMateriasMaxAmount];
	for (size_t i = 0; i < this->_unequipedMateriasMaxAmount; i++)
	{
		this->_unequipedMaterias[i] = nullptr;
	}
}

Character::Character(Character const &other)
:
	_name(other._name),
	_materiasAmount(other._materiasAmount),
	_unequipedMaterias(nullptr),
	_unequipedMateriasAmount(other._unequipedMateriasAmount),
	_unequipedMateriasMaxAmount(other._unequipedMateriasMaxAmount)
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
	this->_name = other._name;
	this->_materiasAmount = other._materiasAmount;
	this->_unequipedMateriasAmount = other._unequipedMateriasAmount;
	this->_unequipedMateriasMaxAmount = other._unequipedMateriasMaxAmount;
	for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
	{
		this->_materias[i] = nullptr;
	}
	if (this->_unequipedMaterias != nullptr)
		delete [] this->_unequipedMaterias;
	this->_unequipedMaterias = new AMateria*[this->_unequipedMateriasMaxAmount];
	for (size_t i = 0; i < this->_unequipedMateriasMaxAmount; i++)
	{
		this->_unequipedMaterias[i] = nullptr;
	}
	if (this != &other)
	{
		for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
		{
			if (other._materias[i] != nullptr)
				this->_materias[i] = other._materias[i]->clone();
		}
		for (size_t i = 0; i < this->_unequipedMateriasAmount; i++)
		{
			if (other._unequipedMaterias[i] != nullptr)
				this->_unequipedMaterias[i] = other._unequipedMaterias[i]->clone();
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
			delete this->_materias[i];
			this->_materias[i] = nullptr;
		}
	}
	if (this->_unequipedMaterias != nullptr)
	{
		for (size_t i = 0; i < this->_unequipedMateriasAmount; i++)
		{
			if (this->_unequipedMaterias[i] != nullptr)
			{
				delete this->_unequipedMaterias[i];
				this->_unequipedMaterias[i] = nullptr;
			}
		}
		delete [] this->_unequipedMaterias;
		this->_unequipedMaterias = nullptr;
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
			this->_materias[this->_materiasAmount] = m->clone();
			this->_materiasAmount++;
		}
	}
}

void Character::unequip(int idx)
{
	if (this->_unequipedMateriasAmount >= this->_unequipedMateriasMaxAmount)
	{
		this->_unequipedMateriasMaxAmount *= 2;
		AMateria**	resizedClonedMaterias = new AMateria*[this->_unequipedMateriasMaxAmount];
		for (size_t i = 0; i < this->_unequipedMateriasMaxAmount; i++)
		{
			if (i < this->_unequipedMateriasAmount)
			{
				resizedClonedMaterias[i] = this->_unequipedMaterias[i];
			}
			else
			{
				resizedClonedMaterias[i] = nullptr;
			}
		}
		delete [] this->_unequipedMaterias;
		this->_unequipedMaterias = nullptr;
		this->_unequipedMaterias = resizedClonedMaterias;
	}
	this->_unequipedMaterias[this->_unequipedMateriasAmount] = this->_materias[idx];
	this->_unequipedMateriasAmount++;
	this->_materias[idx] = nullptr;
}

void Character::use(int idx, ICharacter &target)
{
	if (this->_materias[idx] != nullptr)
	{
		this->_materias[idx]->use(target);
	}
}
