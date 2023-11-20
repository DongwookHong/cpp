#pragma once
#include <iostream>

class Zombie
{
    private:
        std::string name;
    public:
        Zombie();
        ~Zombie();

        void setZombie(std::string str);
        std::string getZombie();
        void announce();
};

Zombie* zombieHorde(int N, std::string name);