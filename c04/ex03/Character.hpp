#include "ICharacter.hpp"

class Character : public ICharacter {
 private:
  AMateria* inventory[4];
  std::string name;
  int cnt;

  Character();
 public:
  Character(std::string _name);
  ~Character();

  Character(const Character& ref);
  Character& operator=(const Character& ref);

  std::string const& getName() const;
  void equip(AMateria* m);
  void unequip(int idx);
  void use(int idx, ICharacter& target);
  void remove(int idx);
};