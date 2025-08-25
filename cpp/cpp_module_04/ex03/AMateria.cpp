#include "AMateria.hpp"
#include "Character.hpp"

AMateria::AMateria(
	std::string const &type) : _type(type)
{
	std::cout << "AMateria parameterized constructor called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
	return this->_type;
}

void AMateria::use(ICharacter &target)
{
	(void) target;
}
