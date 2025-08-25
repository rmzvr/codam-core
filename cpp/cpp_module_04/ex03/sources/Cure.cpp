#include "Cure.hpp"
#include "Character.hpp"

Cure::Cure() : AMateria("cure")
{
	#ifdef DEBUG
		std::cout << "Cure default constructor called" << std::endl;
	#endif
}

Cure::Cure(std::string const &type) : AMateria(type)
{
	#ifdef DEBUG
		std::cout << "Cure parameterized constructor called" << std::endl;
	#endif
}

Cure::Cure(Cure const &other) : AMateria(other)
{
	#ifdef DEBUG
		std::cout << "Cure copy constructor called" << std::endl;
	#endif
	*this = other;
}

Cure &Cure::operator=(const Cure &other)
{
	#ifdef DEBUG
		std::cout << "Cure copy assignment operator called" << std::endl;
	#endif
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

Cure::~Cure()
{
	#ifdef DEBUG
		std::cout << "Cure destructor called" << std::endl;
	#endif
}

AMateria* Cure::clone() const
{
	AMateria*	materia = new Cure(this->_type);
	return materia;
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
