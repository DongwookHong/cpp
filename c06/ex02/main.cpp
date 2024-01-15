#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

Base* generate(void) {
  Base* base;
  srand(time(NULL));

  int random = rand() % 3;
  if (random == 0)
    base = new A();
  else if (random == 1)
    base = new B();
  else
    base = new C();
  return base;
}

void identify(Base* p) {
  if (dynamic_cast<A*>(p)) {
    std::cout << "Pointer is A" << std::endl;
  }
  if (dynamic_cast<B*>(p)) {
    std::cout << "Pointer is B" << std::endl;
  }
  if (dynamic_cast<C*>(p)) {
    std::cout << "Pointer is C" << std::endl;
  }
}

void identify(Base& p) {
  try {
    A& test1 = dynamic_cast<A&>(p);
    (void)test1;
    std::cout << "reference is A" << std::endl;

  } catch (std::exception& e) {
  }
  try {
    B& test2 = dynamic_cast<B&>(p);
    (void)test2;
    std::cout << "reference is B" << std::endl;
  } catch (std::exception& e) {
  }
  try {
    C& test3 = dynamic_cast<C&>(p);
    std::cout << "reference is C" << std::endl;
    (void)test3;
  } catch (std::exception& e) {
  }
}

int main(void) {
  Base* random = generate();
  identify(random);
  identify(*random);

  delete random;
}
