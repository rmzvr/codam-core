/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:15:41 by rmzvr             #+#    #+#             */
/*   Updated: 2025/08/11 14:15:42 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
	public:
		int	index;
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;

		Contact();
		Contact(
				const std::string&	firstName,
				const std::string&	lastName,
				const std::string&	nickname,
				const std::string&	phoneNumber,
				const std::string&	darkestSecret
				);
		~Contact();
		void	printFullInformation();
};

#endif