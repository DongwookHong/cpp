#pragma once
#include <iostream>
#include <string>

class ClapTrap
{
    private:
    /* data */
        std::string     name;
        unsigned int    Hp;
        unsigned int    Ep;
        unsigned int    Ad;
    public:
        ClapTrap();
        ~ClapTrap();
        ClapTrap(std::string _name);
        ClapTrap(const ClapTrap& ref);
        
        ClapTrap& operator=(const ClapTrap& ref);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

};

