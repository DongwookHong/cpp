#include <iostream>
#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"

int main()
{
//    DiamondTrap a("Erick");


// 	a.attack("amumu");

// 	a.guardGate();
// 	a.highFivesGuys();
// 	a.whoAmI();



	ClapTrap *clap = new DiamondTrap("Oriana");

	clap->takeDamage(20);

	std::cout<<"---------------------------------"<<std::endl;
	std::cout<<std::endl;

	FragTrap* frag = new DiamondTrap("Oriana");

	frag->beRepaired(10);
	frag->highFivesGuys();
	std::cout<<"---------------------------------"<<std::endl;
	std::cout<<std::endl;

	ScavTrap* scav = new DiamondTrap("Oriana");

	scav->attack("amumu");
	scav->guardGate();
	std::cout<<"---------------------------------"<<std::endl;
	std::cout<<std::endl;

	DiamondTrap *dia = new DiamondTrap("dia");

	dia->beRepaired(19);
	dia->highFivesGuys();
	dia->guardGate();
	dia->whoAmI();


	
	delete clap;
	delete frag;
	delete scav;
	delete dia;
	return 0;

}