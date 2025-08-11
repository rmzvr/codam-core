/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:15:28 by rmzvr             #+#    #+#             */
/*   Updated: 2025/08/11 14:19:59 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iomanip>
#include "UI.hpp"
#include "PhoneBook.hpp"

std::string	get_prompt(std::string message)
{
	std::string	prompt;

	do
	{
		std::cout << message;
		std::getline(std::cin, prompt);
		if (prompt.empty() == true)
		{
			std::cout << "Field can't be empty." << std::endl;
		}
	} while (prompt.empty() == true);
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

int	get_contact_index()
{
	std::string	prompt;
	char		*str_end;
	int			contactIndex;

	std::cout << "Please enter contact's index: ";
	std::getline(std::cin, prompt);
	contactIndex = strtol(prompt.c_str(), &str_end, 10);
	if (prompt.empty() || *str_end != '\0')
	{
		std::cout << "Invalid index." << std::endl;
		return (-1);
	}
	return (contactIndex);
}

int	main(void)
{
	UI			ui;
	std::string	prompt;
	Contact		*contacts;
	Contact		*contact;
	int			contactIndex;

	PhoneBook	phoneBook;
	std::cout << "Hi, it's a crappy awesome phonebook!" << std::endl;
	while (prompt.compare("EXIT") != 0)
	{
		std::cout << "Waiting for command..." << std::endl;
		std::getline(std::cin, prompt);
		if (prompt.compare("ADD") == 0)
		{
			add_contact(phoneBook);
		}
		else if (prompt.compare("SEARCH") == 0)
		{
			contacts = phoneBook.getContacts();
			if (contacts == nullptr)
				continue ;
			ui.printTable(contacts);
			contactIndex = get_contact_index();
			if (contactIndex == -1)
				continue ;
			contact = phoneBook.getContact(contactIndex);
			if (contact != nullptr)
				ui.printContactInfo(*contact);
		}
	}
	std::cout << "Bye!" << std::endl;
	return (0);
}
