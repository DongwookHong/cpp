#pragma once

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


class DiamondTrap: public ScavTrap, public FragTrap
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
        
};
