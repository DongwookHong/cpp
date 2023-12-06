#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	/* 
  ClapTrap a("tomy");

  	a.attack("James");
	std::cout << std::endl;

	a.takeDamage(3);
    std::cout << std::endl;
	
	a.beRepaired(4);
	std::cout << std::endl;
  
  
  ScavTrap b("rew");

   b.attack("James");
	std::cout << std::endl;

	b.takeDamage(3);
    std::cout << std::endl;
	
	b.beRepaired(4);
	std::cout << std::endl;


	b.guardGate();
 */
	ClapTrap* test = new ScavTrap("test");

	test->attack("test");


	ScavTrap* test1 = new ScavTrap("test1");
	test1->guardGate();
	delete test;
	delete test1;
}

//virtual keyword // upcasting