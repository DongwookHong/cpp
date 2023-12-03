#pragma once

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


class DiamondTrap: public ScavTrap, public FragTrap , public ClapTrap
{   
    private:
        std::string name;
    public:
        DiamondTrap();
        ~DiamondTrap();
 
        DiamondTrap(std::string name);
        DiamondTrap(DiamondTrap& ref);
        DiamondTrap& operator=(DiamondTrap& ref);
        
        void guardGate();
        void DiamondTrap::attack(const std::string& target);
        void highFivesGuys();
        
    DiamondTrap::DiamondTrap(std::string _name):  ClapTrap(_name){
	std::cout<<"DiamondTrap Constructor called"<<std::endl;
	
}
 
};
