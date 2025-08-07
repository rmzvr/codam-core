#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include "Contact.hpp"

class PhoneBook {
	public:
		Contact contacts[8];

		PhoneBook( void );
		~PhoneBook( void );

		void	add(const Contact& contact);
		void	print( void );
	private:
		int	index;
};

#endif
