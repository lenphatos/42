#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const& name, int apcost, int damage) :
_Name(name),
_APCost(apcost),
_Damage(damage)
{}

AWeapon::AWeapon(AWeapon const& other) :
_Name(other._Name),
_APCost(other._APCost),
_Damage(other._Damage)
{}

AWeapon::~AWeapon(){}

AWeapon &AWeapon::operator=(AWeapon const& other){
  if (this != &other){
    _Name = other._Name;
    _APCost = other._APCost;
    _Damage = other._Damage;
  }
  return (*this);
}

std::string AWeapon::getName() const {return (_Name);}
int    AWeapon::getAPCost() const {return (_APCost);}
int    AWeapon::getDamage() const {return (_Damage);}
