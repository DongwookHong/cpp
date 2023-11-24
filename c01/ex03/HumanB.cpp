#include "HumanB.hpp"

HumanB::HumanB(std::string _name):name(_name),weapon(NULL){

}
HumanB::~HumanB(){};


void HumanB::setWeapon(Weapon &weapontype)
{
    this->weapon = &weapontype;
}

void HumanB::attack()
{   
    if (this->weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " attacks with their " << "hands"<<std::endl;
}