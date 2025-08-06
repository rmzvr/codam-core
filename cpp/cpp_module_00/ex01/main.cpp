#include "Contact.hpp"

int	main(void)
{
	std::string	input;

	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;
	
	std::cout << "Enter first name: ";
	std::getline(std::cin, firstName);

	std::cout << "Enter last name: ";
	std::getline(std::cin, lastName);

	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickname);

	std::cout << "Enter phone number: ";
	std::getline(std::cin, phoneNumber);

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, darkestSecret);

	Contact contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	return (0);
}
