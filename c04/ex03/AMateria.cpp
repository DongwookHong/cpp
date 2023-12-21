#include "AMateria.hpp"

AMateria::AMateria(){
	std::cout << "AMateria default constructor called"<<std::endl;
}

AMateria::AMateria(const AMateria& ref){
	std::cout << "AMateria copy constructor called"<<std::endl;
	*this = ref;
}

AMateria::AMateria(std::string _type) : type(_type){
	std::cout << "AMateria constructor called"<<std::endl;
}

AMateria::~AMateria(void){
	std::cout << "AMateria destructor called"<<std::endl;
}

AMateria& AMateria::operator =(const AMateria& ref){
	std::cout << "AMateria copy assignment operator called"<<std::endl;
	if(this != &ref)
		this->type = ref.getType();
	return *this;
}

std::string const & AMateria::getType() const{
	return type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "Use at " << target.getName() << std::endl;
}