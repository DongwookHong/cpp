#include "MateriaSource.hpp"
#define max_slot 4

MateriaSource::MateriaSource() : index(0) {
  std::cout << "MateriaSource default constructor called"<<std::endl;
  for (int i = 0; i < max_slot; i++) {
    slot[i] = NULL;
  }
}
MateriaSource::~MateriaSource() {
  std::cout << "MateriaSource destructor called"<<std::endl;
  for (int i = 0; i < max_slot; i++) {
    delete slot[i];
  }
}

MateriaSource::MateriaSource(const MateriaSource& ref) { 
  std::cout << "MateriaSource copy constructor called"<<std::endl;
  *this = ref; 
  }

MateriaSource& MateriaSource::operator=(const MateriaSource& ref) {
  std::cout << "MateriaSource copy assignment operator called"<<std::endl;
  if(this != &ref){
		for(int i = 0; i < max_slot; i++) delete(slot[i]);		
	  this->index = ref.index;
		for(int i = 0; i < max_slot; i++)
			slot[i] = ref.slot[i]->clone();
	}
  return *this;
}

void MateriaSource::learnMateria(AMateria* a) {
  if  (index == max_slot) {
    std::cout << "Slot is full now " << std::endl;
    delete(a);
  } else {
    for (int i = 0; i < max_slot; i++) {
      if (this->slot[i] != NULL&& this->slot[i]->getType() == a->getType()) {
        std::cout << "It's already in Materia"<<std::endl;
        delete a;
        return;
      }
    }
    slot [index++] = a;
  }
}

AMateria* MateriaSource::createMateria(std::string const& type) {
  for (int i = 0; i < max_slot; i++) {
    if (this->slot[i]->getType() == type) return slot[i]->clone();
  }
  return NULL;
}