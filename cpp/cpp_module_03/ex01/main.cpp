#include "ScavTrap.hpp"

int	main( void )
{
	ScavTrap	scavTrap1("scavTrap1");
	ScavTrap	scavTrap2("scavTrap2");

	do
	{
		scavTrap1.showStatistics();
		scavTrap2.showStatistics();

		scavTrap1.attack("scavTrap2");
		scavTrap2.takeDamage(scavTrap1.getAttackDamage());
		scavTrap1.beRepaired(1);

		scavTrap1.showStatistics();
		scavTrap2.showStatistics();

		scavTrap2.attack("scavTrap1");
		scavTrap1.takeDamage(scavTrap2.getAttackDamage());
		scavTrap2.beRepaired(1);
	} while (scavTrap1.getHitPoints() != 0 || scavTrap2.getHitPoints() != 0);
	return (0);
}