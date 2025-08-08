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

std::string	get_prompt(std::string message)
{
	std::string	prompt;

	std::cout << message;
	std::getline(std::cin, prompt);
	while (prompt.empty() == true)
	{
		std::cout << "\nField can't be empty." << std::endl;
		std::cout << message;
		std::getline(std::cin, prompt);
	}
	return (prompt);
}

void	add_contact(PhoneBook& phoneBook)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;

	std::cout << "Let's add new contact." << std::endl;

	firstName = get_prompt("Enter first name: ");
	lastName = get_prompt("Enter last name: ");
	nickname = get_prompt("Enter nickname: ");
	phoneNumber = get_prompt("Enter phone number: ");
	darkestSecret = get_prompt("Enter darkest secret: ");

	Contact	contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	phoneBook.addContact(contact);
	std::cout << "New contact has been added." << std::endl;
}

void	display_contacts_table(PhoneBook& phoneBook)
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

void	display_contact_info(const Contact& contact)
{
	std::cout << "\nFirst name: " << contact.firstName << std::endl;
	std::cout << "Last name: " << contact.lastName << std::endl;
	std::cout << "Nickname: " << contact.nickname << std::endl;
	std::cout << "Phone number: " << contact.phoneNumber << std::endl;
	std::cout << "Darkest secret: " << contact.darkestSecret << std::endl;
}

int	main(void)
{
	std::string	prompt;
	int			contactIndex;
	Contact		currentContact;

	PhoneBook	phoneBook;
	std::cout << "Hi, it's crappy awesome phonebook!" << std::endl;
	std::cout << "Waiting for command....." << std::endl;
	while (prompt.compare("EXIT") != 0)
	{
		std::getline(std::cin, prompt);
		if (prompt.compare("ADD") == 0)
		{
			add_contact(phoneBook);
		}
		else if (prompt.compare("SEARCH") == 0)
		{
			display_contacts_table(phoneBook);
			do
			{
				std::cout << "Enter contact index: ";
				std::getline(std::cin, prompt);
				// while (prompt.empty() == true)
				// {
				// 	std::cout << "Index invalid." << std::endl;
				// 	std::cout << "Enter contact index: ";
				// 	std::getline(std::cin, prompt);
				// }
				contactIndex = atoi(prompt.c_str());
			} while (phoneBook.checkContactExistence(contactIndex) == false);
			
			currentContact = phoneBook.getContact(contactIndex);
			display_contact_info(currentContact);
		}
	}
	std::cout << "Bye!" << std::endl;
	return (0);
}
