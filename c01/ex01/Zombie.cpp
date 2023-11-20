#include "Zombie.hpp"

Zombie::Zombie(){}
Zombie::~Zombie(){}


void Zombie::setZombie(std::string str)
{
    this->name = str;
}

std::string Zombie::getZombie()
{
    return this->name;
}

void Zombie::announce()
{
    std::cout<<name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}