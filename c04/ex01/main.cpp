#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

// int main() {
//   Dog* dog1 = new Dog();
//   Dog* dog2 = new Dog(*dog1);

//   std::cout << std::endl;

//   std::cout << "-----------------print start---------------" << std::endl;
//   std::cout << "Dog 1's Brain address: " << dog1->getBrain() << std::endl;
//   std::cout << "Dog 2's Brain address: " << dog2->getBrain() << std::endl;

//   std::cout << "-----------------print end---------------" << std::endl;

//   std::cout << std::endl;

//   delete dog1;
//   delete dog2;

//   return 0;
// }
int main() {
  const Dog* j = new Dog();
  const Cat* i = new Cat();

  std::string str = "Dog is cute";
  Brain* r = j->getBrain();
  Brain* qutty = i->getBrain();
  std::cout << std::endl;
  r->setIdeas(str, 0);
  qutty->setIdeas("cat is cutty", 0);
  std::cout << "-----------------print start---------------" << std::endl;

  std::cout << "str of Dog's Brain: " << j->getBrain()->getIdeas(0)
            << std::endl;
  std::cout << "str of Dog's Brain: " << i->getBrain()->getIdeas(0)
            << std::endl;
  std::cout << "Address of Dog's Brain: " << j->getBrain() << std::endl;
  std::cout << "Address of r: " << r << std::endl;
  if (j->getBrain() == r) {
    std::cout << "The addresses are the same." << std::endl;
  } else {
    std::cout << "The addresses are different." << std::endl;
  }

  std::cout << "Address of Dog's Brain: " << i->getBrain() << std::endl;
  std::cout << "Address of qutty: " << qutty << std::endl;

  if (i->getBrain() == qutty) {
    std::cout << "The addresses are the same." << std::endl;
  } else {
    std::cout << "The addresses are different." << std::endl;
  }

  std::cout << "-----------------print end---------------" << std::endl;

  std::cout << std::endl;

  delete j;
  delete i;
}
