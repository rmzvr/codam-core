#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"
// # include "ICharacter.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(std::string const & type);

		~Cure();

		AMateria*			clone() const;
		virtual void		use(ICharacter& target);
};


#endif