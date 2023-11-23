#include <iostream>
#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
    Weapon wea = Weapon("crude spiked club");
    HumanA bob("bob",wea);
    bob.attack();

    wea.setType("some other tpye of club");
    bob.attack();


    Weapon pon = Weapon("crude spiked club");
    HumanB jim("jim");
    jim.attack();
    jim.setWeapon(pon);
    jim.attack();
    wea.setType("some other tpye of club");
    jim.attack();
}