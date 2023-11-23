#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(std::string _weapon):str(_weapon){}
Weapon::~Weapon(){}


std::string Weapon::getType () const{
	return this->str;
};
void Weapon::setType(std::string str){
	this->str = str;
}
