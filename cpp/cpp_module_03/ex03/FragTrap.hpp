#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	private:
		static const unsigned int	_defaultHitPoints;
		static const unsigned int	_defaultEnergyPoints;
		static const unsigned int	_defaultAttackDamage;
	public:
		FragTrap();
		~FragTrap();

		FragTrap( std::string name );
		FragTrap( FragTrap const &other );
		FragTrap&	operator=(FragTrap const &other);

		void	highFivesGuys( void );

		static const unsigned int&	getDefaultHitPoints();
		static const unsigned int&	getDefaultEnergyPoints();
		static const unsigned int&	getDefaultAttackDamage();
};

#endif