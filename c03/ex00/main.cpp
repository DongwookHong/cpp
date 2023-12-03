#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("tomy");

	a.attack("James");
	std::cout << std::endl;

	a.takeDamage(3);
    std::cout << std::endl;
	
	a.beRepaired(4);
	std::cout << std::endl;
	
	return 0;
}