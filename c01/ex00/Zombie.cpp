#include "Zombie.hpp"

Zombie::Zombie(std::string _name): name(_name){}

Zombie::~Zombie(){

}



void Zombie::anouce(){
    std::cout<<name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}