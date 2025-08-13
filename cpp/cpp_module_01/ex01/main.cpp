#include "Zombie.hpp"

int	main( void )
{
	Zombie *horde;
	horde = zombieHorde(5, "Zombie");
	for (size_t i = 0; i < 5; i++)
	{
		(horde + i)->announce();
	}
	delete [] horde;
	return (0);
}