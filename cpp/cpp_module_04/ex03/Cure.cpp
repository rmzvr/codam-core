#include "Cure.hpp"
#include "Character.hpp"

Cure::Cure
() : AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure
(std::string const &type) : AMateria(type)
{
	std::cout << "Cure parameterized constructor called" << std::endl;
}

Cure::~Cure
()
{
	std::cout << "Cure destructor called" << std::endl;
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
