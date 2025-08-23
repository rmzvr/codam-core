#include "FragTrap.hpp"

int	main( void )
{
	FragTrap	fragTrap1("fragTrap1");
	FragTrap	fragTrap2("fragTrap2");

	do
	{
		fragTrap1.showInfo();
		fragTrap2.showInfo();

		fragTrap1.attack("fragTrap2");
		fragTrap2.takeDamage(fragTrap1.getAttackDamage());
		fragTrap1.beRepaired(1);

		if (fragTrap1.getHitPoints() != 0)
		{
			fragTrap1.highFivesGuys();
		}

		fragTrap1.showInfo();
		fragTrap2.showInfo();

		fragTrap2.attack("fragTrap1");
		fragTrap1.takeDamage(fragTrap2.getAttackDamage());
		fragTrap2.beRepaired(1);

		if (fragTrap2.getHitPoints() != 0)
		{
			fragTrap2.highFivesGuys();
		}
	} while (fragTrap1.getHitPoints() != 0 || fragTrap2.getHitPoints() != 0);
	return (0);
}