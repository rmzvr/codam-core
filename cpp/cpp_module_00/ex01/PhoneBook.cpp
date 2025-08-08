#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void ) : index(0)
{
	// std::cout << "PhoneBook's constructor called" << std::endl;
	return;
}

PhoneBook::~PhoneBook( void )
{
	// std::cout << "PhoneBook's destructor called" << std::endl;
	return;
}

void	PhoneBook::addContact(const Contact& contact)
{
	Contact contact_copy = contact;
	contact_copy.index = this->index % 8;
	this->contacts[contact_copy.index] = contact_copy;
	this->index++;
}

bool	PhoneBook::checkContactExistence(int index)
{
	if (index < 0 || index > 7 || this->contacts[index].index == -1)
	{
		std::cout << "Contact not exist. Try another one." << std::endl;
		return (0);
	}
	return (1);
}

Contact	PhoneBook::getContact(int index)
{
	return (this->contacts[index]);
}
