#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
int main() {

  ClapTrap a("A");

  a.attack("tomson");

  ScavTrap b("B");

  b.attack("amumu");
  b.guardGate();

  FragTrap c("C");
  c.attack("amumu");
  c.highFivesGuys();


  ClapTrap * frag = new FragTrap("oriana");

  frag->attack("amumu");

  FragTrap *trap = new FragTrap("oriana");

  trap->highFivesGuys();
  delete frag; 
  delete trap;
  return 0;
}