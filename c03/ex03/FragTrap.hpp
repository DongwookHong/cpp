#pragma once

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{   
    public:
        FragTrap();
        ~FragTrap();
 
        FragTrap(std::string name);
        FragTrap(FragTrap& ref);
        FragTrap& operator=(FragTrap& ref);
        
        void guardGate();
        void FragTrap::attack(const std::string& target);
        void highFivesGuys(); 
};
