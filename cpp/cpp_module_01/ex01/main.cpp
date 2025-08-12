#include "Zombie.hpp"

int	main( void )
{
	Zombie *horde;
	Zombie *currentZombie;
	horde = zombieHorde(5, "Zombie");
	currentZombie = horde;
	currentZombie->announce();
	// currentZombie++;
	// currentZombie++;
	// currentZombie++;
	// currentZombie++;
	// delete [] horde;
	return (0);
}