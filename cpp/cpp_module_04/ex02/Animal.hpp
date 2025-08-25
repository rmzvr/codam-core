#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class AAnimal
{
	protected:
		std::string	type;
	public:
		AAnimal();
		virtual	~AAnimal();
		AAnimal( AAnimal const &other );
		AAnimal&	operator=( AAnimal const &other );

		virtual void				makeSound() const = 0;
		virtual const std::string &	getType() const = 0;
		virtual void				setType( std::string type ) = 0;
};

#endif