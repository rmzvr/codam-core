/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UI.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:15:52 by rmzvr             #+#    #+#             */
/*   Updated: 2025/08/11 14:15:53 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "UI.hpp"

UI::UI()
{
	return;
}

UI::~UI()
{
	return;
}

void	UI::printTable(Contact contacts[MAX_CONTACTS])
{
	this->_printTableHeader();
	this->_printTableBody(contacts);
}

void	UI::printContactInfo(Contact contact)
{
	std::cout << "First name: " << contact.firstName << std::endl;
	std::cout << "Last name: " << contact.lastName << std::endl;
	std::cout << "Nickname: " << contact.nickname << std::endl;
	std::cout << "Phone number: " << contact.phoneNumber << std::endl;
	std::cout << "Darkest secret: " << contact.darkestSecret << std::endl;
}

void	UI::_printTableHeader()
{
	this->_printHorizontalSeparator();
	this->_printTableRow("Index", "First name", "Last name", "Nickname");
}

void	UI::_printTableBody(Contact contacts[MAX_CONTACTS])
{
	for (size_t i = 0; contacts[i].index != -1 && contacts[i].index < MAX_CONTACTS; i++)
	{
		this->_printTableRow(
			std::to_string(contacts[i].index),
			contacts[i].firstName,
			contacts[i].lastName,
			contacts[i].nickname
		);
	}
}

void	UI::_printTableRow(
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

void	UI::_printHorizontalSeparator()
{
	std::cout << std::setfill('-') << std::setw(45) << "" << std::setfill(' ') << std::endl;
}
