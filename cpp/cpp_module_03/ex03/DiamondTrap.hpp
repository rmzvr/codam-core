#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	_name;
	public:
		DiamondTrap();
		DiamondTrap( std::string name );
		DiamondTrap( DiamondTrap const &other );

		~DiamondTrap();

		DiamondTrap&	operator=(DiamondTrap const &other);

		void			setName( std::string name );
		std::string		getName() const;

		void			whoAmI();
		void			showInfo();

		using			ScavTrap::attack;
};

#endif