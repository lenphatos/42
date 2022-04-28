#include "Character.hpp"

Character::Character(std::string const& name) :
_Name(name),
_AP(40),
_Equip(0)
{}

Character::Character(Character const& other) :
_Name(other._Name),
_AP(other._AP),
_Weapon(other._Weapon),
_Equip(other._Equip)
{}

Character::~Character(){}

Character &Character::operator=(Character const& other){
  if (this != &other){
    _Name = other._Name;
    _AP = other._AP;
    _Weapon = other._Weapon;
    _Equip = other._Equip;
  }
  return (*this);
}

void Character::recoverAP(){
  _AP += 10;
  (_AP > 40) ? _AP = 40 : 0;
}

void Character::equip(AWeapon *weapon){
  _Weapon = weapon;
  _Equip = 1;
}

void Character::attack(Enemy *enemy) {
  int cost_ap = _Weapon->getAPCost();

  if (_AP < cost_ap)
    std::cout << "Not enough AP." << std::endl;
  else if (enemy->getHP() == 0)
    std::cout << "You tried to attack a dead target." << std::endl;
  else if (_Weapon) {
    enemy->takeDamage(_Weapon->getDamage());
    std::cout << _Name << " attaque " << enemy->getType() << " with a " << _Weapon->getName() << std::endl;
    _Weapon->attack();
    if (enemy->getHP() <= 0){
      delete enemy;
    }
    _AP -= cost_ap;
  }
}

int      Character::getAP() const {return (_AP);}
int      Character::getequip() const {return (_Equip);}
std::string   Character::getName() const {return (_Name);}
std::string   Character::getWeapon() const {return (_Weapon->getName());}

std::ostream &operator<<(std::ostream &flux, Character const &other){
  if (other.getequip() == 1)
    flux << other.getName() << " has " << other.getAP() << " and carries a " << other.getWeapon() << std::endl;
  else
    flux << other.getName() << " has " << other.getAP() << " and is unarmed" << std::endl;
  return (flux);
}
