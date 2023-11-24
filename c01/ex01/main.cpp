#include <iostream>
#include "Zombie.hpp"

int main()
{
    int	zombie = 10;

	Zombie* zb = zombieHorde(zombie, "Foooooo~");
	if (!zb)
	{
		std::cout<<"Check argument"<<std::endl;
		return 1;
	}
	for(int i = 0; i < zombie; i++)
		zb[i].announce();

	delete[] zb;
}