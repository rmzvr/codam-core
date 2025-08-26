#include "AMateria.hpp"
#include "Character.hpp"

AMateria::AMateria() : _type("")
{
	#ifdef DEBUG
		std::cout << "AMateria default constructor called" << std::endl;
	#endif
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	#ifdef DEBUG
		std::cout << "AMateria parameterized constructor called" << std::endl;
	#endif
}

AMateria::AMateria(const AMateria &other)
{
	#ifdef DEBUG
		std::cout << "AMateria copy constructor called" << std::endl;
	#endif
	*this = other;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	#ifdef DEBUG
		std::cout << "AMateria copy assignment operator called" << std::endl;
	#endif
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

AMateria::~AMateria()
{
	#ifdef DEBUG
		std::cout << "AMateria destructor called" << std::endl;
	#endif
}

std::string const & AMateria::getType() const
{
	return this->_type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "* do materia stuff at " << target.getName() << " *" << std::endl;
}
