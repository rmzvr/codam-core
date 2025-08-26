#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain*		_brain;
	public:
		Dog();
		Dog( Dog const &other );

		~Dog();

		Dog&				operator=( Dog const &other );

		void				makeSound() const;
		Brain const *		getBrain() const;
		std::string const &	getType() const;
		virtual void		setType( std::string type );
};

#endif