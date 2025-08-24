#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <iomanip>

class ClapTrap
{
	private:
		std::string					_name;
		unsigned int				_hitPoints;
		unsigned int				_energyPoints;
		unsigned int				_attackDamage;
		static const unsigned int	_defaultHitPoints;
		static const unsigned int	_defaultEnergyPoints;
		static const unsigned int	_defaultAttackDamage;
	public:
		ClapTrap();
		~ClapTrap();

		ClapTrap( std::string name );
		ClapTrap( ClapTrap const &other );

		ClapTrap&					operator=( ClapTrap const &other );

		void						attack( const std::string & target);
		void						takeDamage( unsigned int amount );
		void						beRepaired( unsigned int amount );

		void						setName( std::string name );
		void						setHitPoints( unsigned int hitPoints );
		void						setEnergyPoints( unsigned int energyPoints );
		void						setAttackDamage( unsigned int attackDamage );

		virtual std::string			getName() const;
		unsigned int				getHitPoints() const;
		unsigned int				getEnergyPoints() const;
		unsigned int				getAttackDamage() const;

		void						showInfo();

		static const unsigned int&	getDefaultHitPoints();
		static const unsigned int&	getDefaultEnergyPoints();
		static const unsigned int&	getDefaultAttackDamage();
};

#endif