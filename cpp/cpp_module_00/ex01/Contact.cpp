/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:15:38 by rmzvr             #+#    #+#             */
/*   Updated: 2025/08/13 10:42:39 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() :
_index(-1),
_firstName(""),
_lastName(""),
_nickname(""),
_phoneNumber(""),
_darkestSecret("")
{
	return;
};

Contact::Contact(
	const std::string&	firstName,
	const std::string&	lastName,
	const std::string&	nickname,
	const std::string&	phoneNumber,
	const std::string&	darkestSecret
) :
	_index(0),
	_firstName(firstName),
	_lastName(lastName),
	_nickname(nickname),
	_phoneNumber(phoneNumber),
	_darkestSecret(darkestSecret)
{
	return;
}

int	Contact::getIndex()
{
	return (this->_index);
}

std::string	Contact::getFirstName()
{
	return (this->_firstName);
}

std::string	Contact::getLastName()
{
	return (this->_lastName);
}

std::string	Contact::getNickname()
{
	return (this->_nickname);
}

void	Contact::setIndex(int index)
{
	this->_index = index;
}

void	Contact::printFullInformation()
{
	std::cout << "First name: " << this->_firstName << std::endl;
	std::cout << "Last name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->_darkestSecret << std::endl;
}

Contact::~Contact()
{
	return;
}
