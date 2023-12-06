#pragma once
#include <iostream>
#include <string>

class ClapTrap
{
    protected:
    /* data */
        std::string     name;
        unsigned int    Hp;
        unsigned int    Ep;
        unsigned int    Ad;
    public:
        ClapTrap();
        virtual ~ClapTrap();
        ClapTrap(std::string _name);
        ClapTrap(const ClapTrap& ref);
        
        ClapTrap& operator=(const ClapTrap& ref);

        virtual void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

};

