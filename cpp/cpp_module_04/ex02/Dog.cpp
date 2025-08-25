#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->_brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

Dog::Dog(Dog const &other) : AAnimal(other), _brain(nullptr)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
}

Dog&	Dog::operator=(Dog const &other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		if (this->_brain != nullptr)
			delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return (*this);
}

std::string const &	Dog::getType() const
{
	return this->type;
}

void	Dog::makeSound() const
{
	std::cout << "Dog making sound..." << std::endl;
}

Brain const *	Dog::getBrain() const
{
	return this->_brain;
}

void	Dog::setType( std::string type )
{
	this->type = type;
}
