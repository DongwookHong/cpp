#pragma  once

#include <iostream>
#include <string>
class Weapon{
	private:
		std::string str;
	public:

		Weapon();
		Weapon(std::string weapon);
		~Weapon();

		std::string getType () const;
		void setType(std::string str);
};