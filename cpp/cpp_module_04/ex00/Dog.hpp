#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog : public Animal
{
	protected:
		std::string	type;
	public:
		Dog();
		~Dog();
		Dog( Dog const &other );
		Dog&	operator=( Dog const &other );

		void		makeSound() const;
		std::string	getType() const;
};

#endif