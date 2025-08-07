#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void ) : index(0)
{
	std::cout << "PhoneBook's constructor called" << std::endl;
	return;
}

PhoneBook::~PhoneBook( void )
{
	std::cout << "PhoneBook's destructor called" << std::endl;
	return;
}

void	PhoneBook::add(const Contact& contact)
{
	Contact contact_copy = contact;
	std::cout << this->index << std::endl;
	contact_copy.index = this->index % 8;
	this->contacts[contact_copy.index] = contact_copy;
	this->index++;
}

void	PhoneBook::print( void )
{
	for (size_t i = 0; i < 8; i++)
	{
		std::cout << "contact: " << this->contacts[i].firstName << std::endl;
	}
}
