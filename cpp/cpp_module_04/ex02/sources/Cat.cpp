#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->_brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

Cat::Cat(Cat const &other) : AAnimal(other), _brain(nullptr)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = other;
}

Cat& Cat::operator=(Cat const &other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		if (this->_brain != nullptr)
			delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return (*this);
}

std::string const & Cat::getType() const
{
	return this->type;
}

void Cat::makeSound() const
{
	std::cout << "Cat making sound..." << std::endl;
}

Brain const *	Cat::getBrain() const
{
	return this->_brain;
}

void	Cat::setType( std::string type )
{
	this->type = type;
}
