#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongAnimal();
		virtual	~WrongAnimal();
		WrongAnimal( WrongAnimal const &other );
		WrongAnimal&	operator=( WrongAnimal const &other );

		void		makeSound() const;
		virtual std::string	getType() const;
};

#endif