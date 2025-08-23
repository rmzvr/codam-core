#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	private:
		static const int	_defaultHitPoints;
		static const int	_defaultEnergyPoints;
		static const int	_defaultAttackDamage;
	public:
		FragTrap();
		~FragTrap();

		FragTrap( std::string name );
		FragTrap( FragTrap const &other );
		FragTrap&	operator=(FragTrap const &other);

		void	highFivesGuys( void );

		static const int&	getDefaultHitPoints();
		static const int&	getDefaultEnergyPoints();
		static const int&	getDefaultAttackDamage();
};

#endif