#pragma once

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB{
	private:
		std::string name;
		Weapon*		weapon;
	public:
		HumanB(std::string _name);
		~HumanB();

		void attack();
		void setWeapon(Weapon &weapontype);
};
