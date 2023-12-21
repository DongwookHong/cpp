#pragma once

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria{
protected:
	std::string type;

public:
	AMateria(void);
	AMateria(const AMateria& ref);
	AMateria(std::string _type);
	virtual ~AMateria(void);

	AMateria& operator =(const AMateria& ref);

	std::string const & getType() const;
	
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

};