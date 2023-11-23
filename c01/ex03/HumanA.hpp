#pragma once
#include <iostream>
#include "Weapon.hpp"

class HumanA{
	private:
		std::string name;
		Weapon &weapon;
	public:
		HumanA(std::string nameA,Weapon& weaponA);
		~HumanA();

		void attack();
};
