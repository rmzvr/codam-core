#include "Ice.hpp"
# include "Character.hpp"

Ice::Ice() : AMateria("ice")
{
	#ifdef DEBUG
		std::cout << "Ice default constructor called" << std::endl;
	#endif
}

Ice::Ice(std::string const &type) : AMateria(type)
{
	#ifdef DEBUG
		std::cout << "Ice parameterized constructor called" << std::endl;
	#endif
}

Ice::Ice(Ice const &other) : AMateria(other)
{
	#ifdef DEBUG
		std::cout << "Ice copy constructor called" << std::endl;
	#endif
	*this = other;
}

Ice &Ice::operator=(const Ice &other)
{
	#ifdef DEBUG
		std::cout << "Ice copy assignment operator called" << std::endl;
	#endif
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

Ice::~Ice()
{
	#ifdef DEBUG
		std::cout << "Ice destructor called" << std::endl;
	#endif
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
