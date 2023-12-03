#include "ClapTrap.hpp"


ClapTrap::ClapTrap(){
    std::cout<<"Default constructor called"<<std::endl;
   
    this->Hp = 10;
    this->Ep = 10;
    this->Ad = 0;
     if(this->name.empty())
    {
        std::cout <<"you need type name"<<std::endl;
        return ;
    }
}

ClapTrap::~ClapTrap(){
    std::cout<<"Destructor called"<<std::endl;
}

ClapTrap::ClapTrap(std::string _name): name(_name){
   std::cout<<"Default constructor called"<<std::endl;
    
   this->Hp = 10;
   this->Ep = 10;
   this->Ad = 0;
   if(this->name.empty())
    {
        std::cout <<"you need type name"<<std::endl;
        return ;
    }
}



ClapTrap::ClapTrap(const ClapTrap& ref){
    
    std::cout<<"Copy constructor called" <<std::endl;
    *this = ref;
}



ClapTrap&  ClapTrap::operator=(const ClapTrap& ref){
    
    std::cout<<"Copy assignment operator called"<<std::endl;
    if (this != &ref)
    {
        this->name=ref.name;
        this->name=ref.Hp;
        this->name=ref.Ep;
        this->name=ref.Ad;
    }
    return *this;
}


void ClapTrap::attack(const std::string& target)
{
    if(this->name.empty())
        return ;
    if (this->Hp == 0)
         std::cout << "I'm already Dead" << std::endl;
    else if (this ->Ep == 0)
         std::cout<<"I need Ep"<<std::endl;
    else
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->Ad << " points of damage!" << std::endl;
	    Ep--;
    }
}
void ClapTrap::takeDamage(unsigned int amount){
    if(this->name.empty())
        return ;
    if (this->Hp ==0)
        std::cout << "I'm already Dead" << std::endl;
    else
    {
        std::cout << this->name << " got attacked by enemy, lose " << amount << "hp" << std::endl;
        if (this->Hp <= 0 || amount >= 10)
            this->Hp =0;
        else
            this->Hp -= amount;
    }
    std::cout << "My  hp " << this->Hp <<" left, "<< "Ep "<< this->Ep<<" left!!"<<std::endl;
}
void ClapTrap::beRepaired(unsigned int amount){
    if(this->name.empty())
        return ;
    if (this->Hp ==0)
        std::cout <<"I'm already Dead" << std::endl;
    else if (this ->Ep == 0)
         std::cout<<"I need Ep"<<std::endl;
    else{
        std::cout << "ClapTrap " << this->name << " got healed, get " << amount << " hp" << std::endl;
		this->Ep--;
        if (this ->Hp + amount >= 10)
            this->Hp = 10;
        else
		    this->Hp += amount;
    }
    std::cout << "My  hp " << this->Hp <<" left, "<< "Ep "<< this->Ep<<" left!!"<<std::endl;
}