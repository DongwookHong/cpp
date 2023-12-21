#include "Cure.hpp"

Cure::Cure():AMateria("cure") {std::cout << "Cure default constructor called"<<std::endl; }
Cure::~Cure() {std::cout << "Cure destructor constructor called"<<std::endl;}

Cure::Cure(const Cure& ref): AMateria("cure") { 
  std::cout << "Cure copy constructor called"<<std::endl;
  *this = ref; 
}

Cure& Cure::operator=(const Cure& ref) {
  if (this != &ref) {
    std::cout<<"Cure Copy assignment constructor called"<<std::endl;
    this->type = ref.getType();
  }
  return *this;
}

AMateria* Cure::clone() const { return new Cure(); }

void Cure::use(ICharacter& target) {
  std::cout << this->type << ": \" * heals "<< target.getName()<<"'s wounds *\""<< std::endl;
}
