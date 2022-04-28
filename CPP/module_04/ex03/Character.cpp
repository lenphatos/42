#include "Character.hpp"

Character::Character(std::string name) : _Name(name) {
  for (int i = 0; i < 4; i++)
		_Inventory[i] = NULL;
}

Character::Character(Character const &other) {
  _Name = other._Name;
  for (int i = 0; i < 4; i++)
    if (_Inventory[i])
      delete _Inventory[i];
  for (int i = 0; i < 4; i++)
    if (other._Inventory[i])
      _Inventory[i] = other._Inventory[i];
}

Character::~Character() {
  for (int i = 0; i < 4; i++)
		if (_Inventory[i])
			delete _Inventory[i];
}

Character &Character::operator=(Character const &other) {
  if (this != &other)
    for (int i = 0; i < 4; i++) {
      _Inventory[i] = other._Inventory[i];
    }
  return (*this);
}

std::string const &Character::getName(void) const {return(_Name);}

void Character::equip(AMateria* m) {
  int i;
  for (i = 0; i < 4 && _Inventory[i]; i++);
  if (i == 3)
    return ;
  for (i = 0; i < 4 && _Inventory[i]; i++);
  _Inventory[i] = m;
}
void Character::unequip(int idx) {
  if (idx >= 0 && idx <= 3)
    _Inventory[idx] = 0;
}
void Character::use(int idx, ICharacter& target) {
  if (idx >= 0 && idx <= 3 && _Inventory[idx])
    _Inventory[idx]->use(target);
}
