#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	private:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
	public:
		ClapTrap( std::string name );
		~ClapTrap();

		void	attack( const std::string& targe t);
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );
};

#endif