#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	private:
		bool						_isInGateKeeperMode;
		static const unsigned int	_defaultHitPoints;
		static const unsigned int	_defaultEnergyPoints;
		static const unsigned int	_defaultAttackDamage;
	public:
		ScavTrap();
		~ScavTrap();

		ScavTrap( std::string name );
		ScavTrap(ScavTrap const &other);
		ScavTrap&	operator=(ScavTrap const &other);

		void	attack( const std::string & target );
		void	guardGate();

		static const unsigned int&	getDefaultHitPoints();
		static const unsigned int&	getDefaultEnergyPoints();
		static const unsigned int&	getDefaultAttackDamage();
};

#endif