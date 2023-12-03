#pragma once
#include "ClapTrap.hpp"


class ScavTrap: public ClapTrap
{   
    public:
        ScavTrap();
        ~ScavTrap();
 
        ScavTrap(std::string name);
        ScavTrap(ScavTrap& ref);
        ScavTrap& operator=(ScavTrap& ref);
        
        void guardGate();
        void attack(const std::string& target);
};
