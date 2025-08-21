#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap	trap1("trap1");
	ClapTrap	trap2("trap2");

	trap1.attack("trap2");
	trap2.takeDamage(0);
	trap1.attack("trap2");
	trap2.takeDamage(0);
	trap1.attack("trap2");
	trap1.beRepaired(1);
	trap2.attack("trap1");
	trap2.beRepaired(1);
	return (0);
}