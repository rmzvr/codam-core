#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include "Contact.hpp"

class PhoneBook {
	public:
		Contact contacts[8];

		PhoneBook( void );
		~PhoneBook( void );

		void	addContact(const Contact& contact);
		bool	checkContactExistence(int index);
		Contact	getContact(int index);

	private:
		int	index;
};

#endif
