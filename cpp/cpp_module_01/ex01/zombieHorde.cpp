#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	(void) name;
	Zombie*	zombies = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		zombies[i] = Zombie(name.append(std::to_string()));
	}
	return (zombies);
}