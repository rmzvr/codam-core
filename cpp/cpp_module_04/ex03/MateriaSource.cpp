#include "MateriaSource.hpp"

IMateriaSource::~IMateriaSource()
{
}

MateriaSource::MateriaSource() : _materiasAmount(0)
{
	for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
	{
		this->_materias[i] = nullptr;
	}
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
	{
		if (this->_materias[i] != nullptr)
		{
			delete this->_materias[i];
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
			return this->_materias[i]->clone();
		}
	}
	return 0;
}
