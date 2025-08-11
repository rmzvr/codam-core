/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:15:25 by rmzvr             #+#    #+#             */
/*   Updated: 2025/08/11 14:15:51 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include "Contact.hpp"

# define MAX_CONTACTS 8

class PhoneBook
{
	private:
		int	index;
		int	addedContacts;
		Contact _contacts[MAX_CONTACTS];

		bool	_isContactsEmpty();
		bool	_isContactExist(int index);
	public:

		PhoneBook();
		~PhoneBook();

		Contact*	getContacts();
		Contact*	getContact(int index);
		void		addContact(const Contact& contact);
};

#endif
