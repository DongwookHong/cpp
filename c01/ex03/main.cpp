#include <iostream>
#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
    Weapon wea = Weapon("crude spiked club");
    HumanA bob("bob",wea);
    bob.attack();

    wea.setType("some other type of club");
    bob.attack();


    Weapon pon = Weapon("crude spiked club");
    HumanB jim("jim");
    jim.attack();
    jim.setWeapon(pon);
    jim.attack();
    pon.setType("some other type of club");
    jim.attack();
}