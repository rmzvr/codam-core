#include <string>
#include <iomanip>
#include "PhoneBook.hpp"

void	print_horizontal_separator()
{
	std::cout << std::setfill('-') << std::setw(45) << "" << std::setfill(' ') << std::endl;
}

void	print_table_row(
	const std::string index,
	const std::string firstName,
	const std::string lastName,
	const std::string nickname
)
{
	std::string firstNameCopy = firstName;
	if (firstNameCopy.size() > 10)
	{
		firstNameCopy = firstNameCopy.substr(0, 9);
		firstNameCopy.append(".");
	}
	std::cout
		<< '|'
		<< std::setw(10) << std::right << index
		<< '|'
		<< std::setw(10) << std::right << firstNameCopy
		<< '|'
		<< std::setw(10) << std::right << lastName
		<< '|'
		<< std::setw(10) << std::right << nickname
		<< '|'
		<< std::endl;
	print_horizontal_separator();
}

void	print_table_header()
{
	print_horizontal_separator();
	print_table_row("Index", "First name", "Last name", "Nickname");
}

int	main(void)
{
	std::string	prompt;

	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;

	PhoneBook	phoneBook;
	std::cout << "Hi, it's crappy awesome phonebook!" << std::endl;
	std::cout << "Waiting for command....." << std::endl;
	while (prompt.compare("EXIT") != 0)
	{
		std::getline(std::cin, prompt);
		if (prompt.compare("ADD") == 0)
		{
			std::cout << "Let's add new contact." << std::endl;

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

			Contact	contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
			phoneBook.add(contact);
			std::cout << "New contact has been added." << std::endl;
		}
		else if (prompt.compare("SEARCH") == 0)
		{
			print_table_header();
			for (size_t i = 0; phoneBook.contacts[i].index != -1 && phoneBook.contacts[i].index < 8; i++)
			{
				print_table_row(
					std::to_string(phoneBook.contacts[i].index),
					phoneBook.contacts[i].firstName,
					phoneBook.contacts[i].lastName,
					phoneBook.contacts[i].nickname
				);
			}
		}
	}
	std::cout << "Bye!" << std::endl;
	return (0);
}
