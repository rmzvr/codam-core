#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain*		_brain;
	protected:
		std::string type;
	public:
		Dog();
		Dog( Dog const &other );

		~Dog();

		Dog&				operator=( Dog const &other );

		void				makeSound() const;
		std::string const &	getType() const;
		Brain*				getBrain();
};

#endif