#pragma once
#include <iostream>

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
 private:
  AMateria* slot[4];
  int index;

 public:
  MateriaSource(/* args */);
  ~MateriaSource();

  MateriaSource(const MateriaSource& ref);
  MateriaSource& operator=(const MateriaSource& ref);

  void learnMateria(AMateria* a);
  AMateria* createMateria(std::string const& type);
};
