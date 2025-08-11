/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:15:48 by rmzvr             #+#    #+#             */
/*   Updated: 2025/08/11 14:15:49 by rmzvr            ###   ########.fr       */
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
	contact_copy.index = this->index % MAX_CONTACTS;
	this->_contacts[contact_copy.index] = contact_copy;
	this->index++;
	this->addedContacts++;
}

bool	PhoneBook::_isContactExist(int index)
{
	if (index < 0 || index > 7 || this->_contacts[index].index == -1)
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
