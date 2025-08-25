#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	protected:
		std::string type;
	public:	
		WrongCat();
		~WrongCat();
		WrongCat( WrongCat const &other );
		WrongCat&	operator=( WrongCat const &other );

		void		makeSound() const;
		std::string	getType() const;
};

#endif