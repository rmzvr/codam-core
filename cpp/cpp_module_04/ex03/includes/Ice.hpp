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
		Ice( Ice const &other );
		Ice&	operator=( Ice const & );
		~Ice();


		AMateria* 			clone() const;
		virtual void		use(ICharacter& target);
};

#endif
