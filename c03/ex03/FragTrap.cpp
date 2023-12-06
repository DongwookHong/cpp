#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout<<"FragTrap Default constructor called"<<std::endl;
}

FragTrap::FragTrap(std::string _name): ClapTrap(_name){
	std::cout<<"FragTrap Constructor called"<<std::endl;
	Hp = 100;
	Ep = 100;
	Ad = 30;
}


FragTrap::~FragTrap(){
	std::cout<<"FragTrap destructor called"<<std::endl;
}

FragTrap::FragTrap(FragTrap& ref)
{
	std::cout<<"FragTrap Copy constructor called" <<std::endl;
	*this = ref;
}


FragTrap& FragTrap::operator=(FragTrap& ref)
{
	 std::cout<<"FragTrap Copy assignment operator called"<<std::endl;
	if(this != &ref)
	{
		ClapTrap::operator=(ref);
	}
	return *this;
}

void FragTrap::attack(const std::string& target)
{
    if(this->name.empty())
        return ;
    if (this->Hp == 0)
         std::cout << "I'm already Dead" << std::endl;
    else if (this->Ep == 0)
         std::cout<<"I need Ep"<<std::endl;
    else
    {
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->Ad << " points of damage!" << std::endl;
	    Ep--;
    }
}

 void FragTrap::highFivesGuys(void){
	std::cout<< this->name <<" highFive with you"<<std::endl;
 } 