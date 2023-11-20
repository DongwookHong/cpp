#pragma  once
#include <iostream>

class Weapon{
	private:
		std::string str;
	public:
		Weapon(std::string str);
		~Weapon();

		std::string getType () const;
		void setType(std::string str);
};