#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	private:
		bool	_isInGateKeeperMode;
		static const int	_defaultHitPoints;
		static const int	_defaultEnergyPoints;
		static const int	_defaultAttackDamage;
	public:
		ScavTrap();
		~ScavTrap();

		ScavTrap( std::string name );
		ScavTrap(ScavTrap const &other);
		ScavTrap&	operator=(ScavTrap const &other);

		void	attack( const std::string & target );
		void	guardGate();

		static const int&	getDefaultHitPoints();
		static const int&	getDefaultEnergyPoints();
		static const int&	getDefaultAttackDamage();
};

#endif