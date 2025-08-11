/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:15:38 by rmzvr             #+#    #+#             */
/*   Updated: 2025/08/11 14:15:40 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

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
	return;
}
