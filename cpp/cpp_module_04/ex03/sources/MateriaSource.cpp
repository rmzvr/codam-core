#include "MateriaSource.hpp"

IMateriaSource::~IMateriaSource()
{
}

MateriaSource::MateriaSource() : _materiasAmount(0), _clonedMateriasAmount(0)
{
	#ifdef DEBUG
		std::cout << "MateriaSource default constructor called" << std::endl;
	#endif
	for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
	{
		this->_materias[i] = nullptr;
		this->_clonedMaterias[i] = nullptr;
	}
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	#ifdef DEBUG
		std::cout << "MateriaSource copy constructor called" << std::endl;
	#endif
	*this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	#ifdef DEBUG
		std::cout << "MateriaSource copy assignment operator called" << std::endl;
	#endif
	if (this != &other)
	{
		this->_materiasAmount = other._materiasAmount;
		for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
		{
			this->_materias[i] = other._materias[i];
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	#ifdef DEBUG
		std::cout << "MateriaSource destructor called" << std::endl;
	#endif
	for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
	{
		if (this->_materias[i] != nullptr)
		{
			delete this->_materias[i];
		}
		if (this->_clonedMaterias[i] != nullptr)
		{
			delete this->_clonedMaterias[i];
		}
	}
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (this->_materiasAmount < MAX_MATERIAS_AMOUNT)
	{
		this->_materias[this->_materiasAmount] = m;
		this->_materiasAmount++;
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
	{
		if (this->_materias[i] != nullptr && this->_materias[i]->getType() == type)
		{
			AMateria*	clonedMateria = this->_materias[i]->clone();
			this->_clonedMaterias[this->_clonedMateriasAmount] = clonedMateria;
			this->_clonedMateriasAmount++;
			return clonedMateria;
		}
	}
	return 0;
}
