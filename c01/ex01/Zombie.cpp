#include "Zombie.hpp"

Zombie::Zombie(){}
Zombie::~Zombie(){}

void Zombie::announce()
{
    std::cout<<name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}