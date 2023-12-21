#pragma once

#include <iostream>
#include <string>

#include "AMateria.hpp"

class Cure : public AMateria {
 public:
  Cure();
  ~Cure();
  Cure(const Cure& ref);

  Cure& operator=(const Cure& ref);
  AMateria* clone() const;
  void use(ICharacter& target);
};
