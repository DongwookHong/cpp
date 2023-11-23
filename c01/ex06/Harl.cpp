#include <iostream>
#include "Harl.hpp"

Harl::Harl(){
	cmd[0] = &Harl::debug;
	cmd[1] = &Harl::info;
	cmd[2] = &Harl::warning;
	cmd[3] = &Harl::error;
}
Harl::~Harl(){}


void Harl::complain(std::string level)
{
	std::string lvl[4] = {"DEBUG","INFO","WARNING","ERROR"};
	int value = -1;

	for(int i = 0; i<4 ; i++)
	{
		if(level == lvl[i])
		{
			value = i;
		}
	}

	switch (value)
	{
		case 0:
			(this->*cmd[0])();
			__attribute__((fallthrough));
		case 1:
			(this->*cmd[1])();
			__attribute__((fallthrough));
		case 2:
			(this->*cmd[2])();
			__attribute__((fallthrough));
		case 3:
			(this->*cmd[3])();
			break;
		default:
			std::cout<<"[ Probably complaining about insignificant problems ]"<<std::endl;
	}	
}


void Harl::debug(void){
	std::cout << "[ DEBUG ]"<<std::endl;
	std::cout<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger."<<std::endl;
	std::cout<<"I really do!"<<std::endl;
}

void Harl::info(void){
	std::cout << "[ INFO ]"<<std::endl;
	std::cout<<"I cannot believe adding extra bacon costs more money."<<std::endl; 
	std::cout<<"You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"<<std::endl;
}

void Harl::warning(void){
	std::cout << "[ WARNING ]"<<std::endl; 
	std::cout<<"I think I deserve to have some extra bacon for free."<<std::endl;
	std::cout<<"I’ve been coming for years whereas you started working here since last month."<<std::endl;
}

void Harl::error(void){
	std::cout << "[ ERROR ]"<<std::endl; 
	std::cout<< "This is unacceptable! I want to speak to the manager now."<<std::endl;
}	