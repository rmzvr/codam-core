/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UI.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:15:54 by rmzvr             #+#    #+#             */
/*   Updated: 2025/08/11 14:15:55 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_HPP
# define UI_HPP

#include "Contact.hpp"
#include "PhoneBook.hpp"

class UI
{
	private:
		void	_printHorizontalSeparator();
		void	_printTableHeader();
		void	_printTableBody(Contact contacts[MAX_CONTACTS]);
		void	_printTableRow(
				const std::string index,
				const std::string firstName,
				const std::string lastName,
				const std::string nickname
				);
	public:
		UI();
		~UI();
		void	printTable(Contact contacts[MAX_CONTACTS]);
		void	printContactInfo(Contact contact);
};

#endif