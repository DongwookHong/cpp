#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout<<"DiamondTrap Default constructor called"<<std::endl;
}

DiamondTrap::DiamondTrap(std::string _name):  ClapTrap(_name + "_clap_name"),FragTrap(_name),ScavTrap(_name){
	std::cout<<"DiamondTrap Constructor called"<<std::endl;
	this->name =_name;
}


DiamondTrap::~DiamondTrap(){
	std::cout<<"DiamondTrap destructor called"<<std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap& ref)
{
	std::cout<<"DiamondTrap Copy constructor called" <<std::endl;
	*this = ref;
}


DiamondTrap& DiamondTrap::operator=(DiamondTrap& ref)
{
	 std::cout<<"DiamondTrap Copy assignment operator called"<<std::endl;
	if(this != &ref)
	{
		ClapTrap::operator=(ref);
	}
	return *this;
}


void DiamondTrap::guardGate()
{
	std::cout<<"DiamondTrap is now in Gate keeper mode"<<std::endl;
};

void DiamondTrap::attack(const std::string& target)
{
    if(this->name.empty())
        return ;
    if (this->Hp == 0)
         std::cout << "I'm already Dead" << std::endl;
    else if (this->Ep == 0)
         std::cout<<"I need Ep"<<std::endl;
    else
    {
        std::cout << "DiamondTrap " << this->name << " attacks " << target << ", causing " << this->Ad << " points of damage!" << std::endl;
	    Ep--;
    }
}