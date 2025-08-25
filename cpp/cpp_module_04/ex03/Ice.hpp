#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

class ICharacter;

class Ice : public AMateria
{
	public:
		Ice();
		Ice(std::string const & type);
		// Ice( Ice const &other );

		~Ice();

		// Ice&	operator=( Ice const &other );

		AMateria* 			clone() const;
		virtual void		use(ICharacter& target);
};

#endif
