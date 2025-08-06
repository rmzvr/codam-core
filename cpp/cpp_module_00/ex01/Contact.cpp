#include "Contact.hpp"

#ifndef CONTACT_HPP
# define CONTACT_HPP

Contact::Contact() :
	firstName("firstName"),
	lastName("lastName"),
	nickname("nickname"),
	phoneNumber("phoneNumber"),
	darkestSecret("darkestSecret")
{
	return;
};

Contact::Contact(
	const std::string& firstName,
	const std::string& lastName,
	const std::string& nickname,
	const std::string& phoneNumber,
	const std::string& darkestSecret
) :
	firstName(firstName),
	lastName(lastName),
	nickname(nickname),
	phoneNumber(phoneNumber),
	darkestSecret(darkestSecret)
{
	return;
}

Contact::~Contact()
{
	std::cout << "Contact's constructor called" << std::endl;
	std::cout << this->firstName << std::endl;
	std::cout << this->lastName << std::endl;
	std::cout << this->nickname << std::endl;
	std::cout << this->phoneNumber << std::endl;
	std::cout << this->darkestSecret << std::endl;
	std::cout << "Contact's destructor called" << std::endl;
	return;
}

#endif