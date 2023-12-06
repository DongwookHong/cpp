#pragma once

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{   
    public:
        FragTrap();
        ~FragTrap();
 
        FragTrap(std::string name);
        FragTrap(FragTrap& ref);
        FragTrap& operator=(FragTrap& ref);
        
        void attack(const std::string& target);
        void highFivesGuys(); 
};
