/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:15:48 by rmzvr             #+#    #+#             */
/*   Updated: 2025/08/13 11:29:47 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0), addedContacts(0)
{
	return;
}

PhoneBook::~PhoneBook()
{
	return;
}

void	PhoneBook::addContact(const Contact& contact)
{
	Contact contact_copy = contact;
	contact_copy.setIndex(this->index % MAX_CONTACTS);
	this->_contacts[contact_copy.getIndex()] = contact_copy;
	this->index++;
	this->addedContacts++;
}


bool	PhoneBook::_isContactExist(int index)
{
	if (index < 0 || index > (MAX_CONTACTS - 1) || this->_contacts[index].getIndex() == -1)
	{
		return (false);
	}
	return (true);
}

bool	PhoneBook::_isContactsEmpty()
{
	if (this->addedContacts == 0)
	{
		return (true);
	}
	return (false);
}

Contact*	PhoneBook::getContacts()
{
	if (this->_isContactsEmpty())
	{
		std::cout << "No contacts." << std::endl;
		return (nullptr);
	}
	return (this->_contacts);
}

Contact*	PhoneBook::getContact(int index)
{
	if (this->_isContactExist(index) == false)
	{
		std::cout << "Contact not found." << std::endl;
		return (nullptr);
	}
	return (&this->_contacts[index]);
}

void	PhoneBook::printTable()
{
	this->_printHorizontalSeparator();
	this->_printTableRow("Index", "First name", "Last name", "Nickname");
	this->_printTableBody();
}

void	PhoneBook::_printTableBody()
{
	for (
		size_t i = 0;
		i < MAX_CONTACTS && this->_contacts[i].getIndex() != -1;
		i++
	)
	{
		Contact	&contact = this->_contacts[i];
		this->_printTableRow(
			std::to_string(contact.getIndex()),
			contact.getFirstName(),
			contact.getLastName(),
			contact.getNickname()
		);
	}
}

void	PhoneBook::_printTableRow(
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
	this->_printHorizontalSeparator();
}

void	PhoneBook::_printHorizontalSeparator()
{
	std::cout << std::setfill('-') << std::setw(45) << "" << std::setfill(' ') << std::endl;
}
