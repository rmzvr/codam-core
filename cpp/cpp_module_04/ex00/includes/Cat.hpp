#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		~Cat();
		Cat( Cat const &other );
		Cat&	operator=( Cat const &other );

		void		makeSound() const;
		std::string	getType() const;
};

#endif