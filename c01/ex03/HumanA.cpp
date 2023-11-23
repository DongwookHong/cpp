#include "HumanA.hpp"


HumanA::HumanA(std::string nameA,Weapon& weaponA): name(nameA),weapon(weaponA){
}

HumanA::~HumanA(){};


void HumanA::attack()
{
    std::cout<<name<<" attacks with their " << weapon.getType()<< std::endl;
}

