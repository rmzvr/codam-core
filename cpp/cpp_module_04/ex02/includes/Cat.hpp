#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain*		_brain;
	public:
		Cat();
		Cat( Cat const &other );

		~Cat();

		Cat&				operator=( Cat const &other );

		void				makeSound() const;
		Brain const *		getBrain() const;
		std::string const &	getType() const;
		virtual void		setType( std::string type );
};

#endif