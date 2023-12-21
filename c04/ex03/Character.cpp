#include "Character.hpp"
#define max_num 4


Character::Character(){
	std::cout << "Character default constructor called"<<std::endl;
}

Character::Character(std::string _name) : name(_name) ,cnt(0){
  std::cout << "Character constructor called"<<std::endl;
  for (int i = 0; i < max_num; i++) {
    inventory[i] = NULL;
  }
};

Character::~Character() {
  std::cout << "Character destructor called"<<std::endl;
  for (int i = 0; i < max_num; i++) {
    delete inventory[i];
  }
};

Character::Character(const Character& ref) {
  std::cout << "AMateria copy constructor called"<<std::endl;
  for (int i = 0; i < max_num; ++i) {
    inventory[i] = NULL;
  }

  *this = ref;
}

Character& Character::operator=(const Character& ref) {
  std::cout << "Character copy assignment operator called"<<std::endl;
  if (this != &ref) {
    this->name = ref.getName();
    for (int i = 0; ref.inventory[i]; i++) {
      if (this->inventory[i] != NULL) {
        delete inventory[i];
      }
      this->inventory[i] = ref.inventory[i]->clone();
    }
  }
  return *this;
}


std::string const& Character::getName() const { return this->name; }

void Character::equip(AMateria* m) {
  if (this->cnt ==max_num)
    std::cout<<"equip not available anymore"<<std::endl;
  if (m == NULL) std::cout << "Check equip" << std::endl;
  for (int i = 0; i < max_num; i++) {
    if (this->inventory[i]== m){
      std::cout<<"skill is already filled"<<std::endl;
      break;
    }
    else if (this->inventory[i] == NULL) { 
      std::cout<<"Character learned "<<m->getType()<<std::endl;
      this->inventory[i] = m;
      this->cnt++;
      break;
      }
  }
}

void Character::unequip(int idx) {
  if (this->inventory[idx] != NULL) remove(idx);
}

void Character::remove(int idx) { delete this->inventory[idx]; }

void Character::use(int idx, ICharacter& target) {
  if(idx >= max_num)
		std::cout << "Error: Slot[" << idx << "] is empty"<<std::endl;
  else if (this->inventory[idx] == NULL)
  {
    std::cout<<"check skills" <<std::endl;
  } 
	else
		this->inventory[idx]->use(target);
}