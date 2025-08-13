#include "Zombie.hpp"

int	main( void )
{
	randomChump("Bar");

	Zombie	*zombie = newZombie("Foo");
	zombie->announce();
	delete zombie;
	return (0);
}