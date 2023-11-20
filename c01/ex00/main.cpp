#include "Zombie.hpp"


int main()
{
    Zombie *zb = newZombie("Bzombie");
    zb->anouce();

    randomChump("Rzombie");

    delete zb;
    return 0;
}