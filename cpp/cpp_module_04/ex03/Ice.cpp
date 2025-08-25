#include "Ice.hpp"
# include "Character.hpp"

Ice::Ice
() : AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice
(std::string const &type) : AMateria(type)
{
	std::cout << "Ice parameterized constructor called" << std::endl;
}

Ice::~Ice
()
{
	std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone() const
{
	AMateria*	materia = new Ice(this->_type);
	return materia;
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
