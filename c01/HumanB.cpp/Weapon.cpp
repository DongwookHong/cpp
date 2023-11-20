#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(std::string _str): str(_str){}

Weapon::~Weapon(){}


std::string Weapon::getType () const{
	return this->str;
};
void Weapon::setType(std::string str){
	this->str = str;
}
