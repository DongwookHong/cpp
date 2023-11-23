#include <iostream>
#include "Zombie.hpp"

int main()
{
    int	zombie = 3;
	Zombie* zb = zombieHorde(zombie, "Foooooo~");

	for(int i = 0; i < zombie; i++)
		zb[i].announce();

	delete[] zb;
}