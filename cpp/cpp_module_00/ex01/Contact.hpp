/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:15:41 by rmzvr             #+#    #+#             */
/*   Updated: 2025/08/13 10:43:05 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
	private:
		int			_index;
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
	public:
		Contact();
		Contact(
				const std::string&	firstName,
				const std::string&	lastName,
				const std::string&	nickname,
				const std::string&	phoneNumber,
				const std::string&	darkestSecret
				);
		~Contact();
		void			printFullInformation();
		void			setIndex(int index);
		int				getIndex();
		std::string		getFirstName();
		std::string		getLastName();
		std::string		getNickname();
};

#endif