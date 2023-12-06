#pragma once
#include "ClapTrap.hpp"


class ScavTrap: virtual public ClapTrap
{   
    public:
        ScavTrap();
        ~ScavTrap();
 
        ScavTrap(std::string name);
        ScavTrap(ScavTrap& ref);
        ScavTrap& operator=(ScavTrap& ref);
        
        virtual void guardGate();
        void attack(const std::string& target);
};
