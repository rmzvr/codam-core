#include "Contact.hpp"

#ifndef CONTACT_HPP
# define CONTACT_HPP

Contact::Contact() :
index(-1),
firstName(""),
lastName(""),
nickname(""),
phoneNumber(""),
darkestSecret("")
{
	// std::cout << "Contact's default constructor called" << std::endl;
	return;
};

Contact::Contact(
	const std::string&	firstName,
	const std::string&	lastName,
	const std::string&	nickname,
	const std::string&	phoneNumber,
	const std::string&	darkestSecret
) :
	index(0),
	firstName(firstName),
	lastName(lastName),
	nickname(nickname),
	phoneNumber(phoneNumber),
	darkestSecret(darkestSecret)
{
	// std::cout << "Contact's custom constructor called" << std::endl;
	return;
}

Contact::~Contact()
{
	// std::cout << this->index << std::endl;
	// std::cout << this->firstName << std::endl;
	// std::cout << this->lastName << std::endl;
	// std::cout << this->nickname << std::endl;
	// std::cout << this->phoneNumber << std::endl;
	// std::cout << this->darkestSecret << std::endl;
	// std::cout << "Contact's destructor called" << std::endl;
	return;
}

#endif