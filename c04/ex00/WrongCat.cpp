#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
  std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat desctructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& ref) {
  std::cout << "WrongCat Copy constructor called" << std::endl;
  *this = ref;
}

WrongCat& WrongCat::operator=(const WrongCat& ref) {
  std::cout << "WrongCat Copy assignment constructor called" << std::endl;
  if (this != &ref) {
    WrongAnimal::operator=(ref);
  }
  return *this;
}

void WrongCat::makeSound() const { std::cout << "mae" << std::endl; }
