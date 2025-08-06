#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void )
{
	std::cout << "PhoneBook's constructor called" << std::endl;
	return;
}

PhoneBook::~PhoneBook( void )
{
	std::cout << "PhoneBook's destructor called" << std::endl;
	return;
}

// void	PhoneBook::add(const Contact& contact)
// {
// 	this->contacts[0] = contact;
// }

// void	PhoneBook::print( void )
// {
// 	std::cout << "contact: " << this->contacts[0].firstName << std::endl;
// }
