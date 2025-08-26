#include "MateriaSource.hpp"

IMateriaSource::~IMateriaSource()
{}

MateriaSource::MateriaSource()
:
	_clonedMaterias(nullptr),
	_materiasAmount(0),
	_clonedMateriasAmount(0),
	_clonedMateriasMaxAmount(MAX_MATERIAS_AMOUNT)
{
	#ifdef DEBUG
		std::cout << "MateriaSource default constructor called" << std::endl;
	#endif
	for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
	{
		this->_materias[i] = nullptr;
	}
	this->_clonedMaterias = new AMateria*[this->_clonedMateriasMaxAmount];
	for (size_t i = 0; i < this->_clonedMateriasMaxAmount; i++)
	{
		this->_clonedMaterias[i] = nullptr;
	}
}

MateriaSource::MateriaSource(const MateriaSource &other)
:
	_clonedMaterias(nullptr),
	_materiasAmount(0),
	_clonedMateriasAmount(0),
	_clonedMateriasMaxAmount(4)
{
	#ifdef DEBUG
		std::cout << "MateriaSource copy constructor called" << std::endl;
	#endif
	for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
	{
		this->_materias[i] = nullptr;
	}
	*this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	#ifdef DEBUG
		std::cout << "MateriaSource copy assignment operator called" << std::endl;
	#endif
	// if (this == &other)
	// 	return *this;

	this->_materiasAmount = other._materiasAmount;
	this->_clonedMateriasAmount = other._clonedMateriasAmount;
	this->_clonedMateriasMaxAmount = other._clonedMateriasMaxAmount;

	for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
	{
		if (this->_materias[i] != nullptr)
		{
			delete this->_materias[i];
			this->_materias[i] = nullptr;
		}
	}

	if (this->_clonedMaterias != nullptr)
	{
		for (size_t i = 0; i < this->_clonedMateriasAmount; i++)
		{
			if (this->_clonedMaterias[i] != nullptr)
			{
				delete this->_clonedMaterias[i];
				this->_clonedMaterias[i] = nullptr;
			}
		}
		delete [] this->_clonedMaterias;
		this->_clonedMaterias = nullptr;
	}

	this->_clonedMaterias = new AMateria*[this->_clonedMateriasMaxAmount];
	for (size_t i = 0; i < this->_clonedMateriasMaxAmount; i++)
	{
		this->_clonedMaterias[i] = nullptr;
	}

	if (this != &other)
	{
		for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
		{
			if (other._materias[i] != nullptr)
			{
				this->_materias[i] = other._materias[i]->clone();
			}
		}
	}

	for (size_t i = 0; i < this->_clonedMateriasAmount; i++)
	{
		if (other._clonedMaterias[i] != nullptr)
			this->_clonedMaterias[i] = other._clonedMaterias[i];
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
			this->_materias[i] = nullptr;
		}
	}

	if (this->_clonedMaterias != nullptr)
	{
		for (size_t i = 0; i < this->_clonedMateriasAmount; i++)
		{
			if (this->_clonedMaterias[i] != nullptr)
			{
				delete this->_clonedMaterias[i];
				this->_clonedMaterias[i] = nullptr;
			}
		}
		delete [] this->_clonedMaterias;
	}
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (m != nullptr && this->_materiasAmount < MAX_MATERIAS_AMOUNT)
	{
		this->_materias[this->_materiasAmount] = m;
		this->_materiasAmount++;
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	if (this->_clonedMateriasAmount >= this->_clonedMateriasMaxAmount)
	{
		this->_clonedMateriasMaxAmount *= 2;

		AMateria**	resizedClonedMaterias = new AMateria*[this->_clonedMateriasMaxAmount];
		for (size_t i = 0; i < this->_clonedMateriasMaxAmount; i++)
		{
			if (i < this->_clonedMateriasAmount)
				resizedClonedMaterias[i] = this->_clonedMaterias[i];
			else
				resizedClonedMaterias[i] = nullptr;
		}
		delete [] this->_clonedMaterias;
		this->_clonedMaterias = resizedClonedMaterias;
	}

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
