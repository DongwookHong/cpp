
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main() {
  IMateriaSource* src = new MateriaSource();
  std::cout << "\n";

  src->learnMateria(new Ice());
  std::cout << "\n";

  src->learnMateria(new Cure());
  std::cout << "\n";

  // std::cout << "-----Attempt equip with overlaped materia type-----\n";
  // src->learnMateria(new Cure());
  // std::cout << "\n";


  ICharacter* me = new Character("me");
  std::cout << "\n";
  AMateria* tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  std::cout << "\n";

  tmp = src->createMateria("cure");
  me->equip(tmp);
  std::cout << "\n";

  // std::cout << "-----Attempt equip with same address materia-----\n";
  // me->equip(tmp);
  // std::cout << "\n";

  // std::cout << "--------Attempt equip materias more than 4-------\n";
  // tmp = src->createMateria("cure");
  // me->equip(tmp);
  // std::cout << "\n";

  // tmp = src->createMateria("cure");
  // me->equip(tmp);
  // std::cout << "\n";

  // tmp = src->createMateria("cure");
  // me->equip(tmp);
  // std::cout << "\n";

  ICharacter* bob = new Character("bob");
  std::cout << "\n";

  me->use(0, *bob);
  me->use(1, *bob);
  std::cout << "\n";

  // std::cout << "---------------Use none equip slot---------------\n";
  // me->use(2, *bob);
  // std::cout << "\n";

  delete bob;
  std::cout << "\n";
  delete me;
  std::cout << "\n";
  delete src;
  std::cout << "\n";

  // system("leaks a.out");

  return 0;
}