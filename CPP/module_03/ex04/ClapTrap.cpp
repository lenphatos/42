#include <iostream>
#include <string>
#include "ClapTrap.hpp"

using namespace std;

void _whoami(std::string& name, unsigned int hp)
{
	std::cout << "-> FR4G-TP \033[1;31m" << name << "\033[0m(\033[1;32m" << hp << "\033[0m) : " << std::endl;
}

//Constructor
ClapTrap::ClapTrap(){
  srand(time(NULL));
}

ClapTrap::ClapTrap(
	std::string 	name,
	int 		HitPoints,
	int 		MaxhitPoints,
	int 		EnergyPoints,
	int 		MaxEnergyPoints,
	int 		Level,
	int 		MeleeAttackDamage,
	int 		RangedAttackDamage,
	int 		ArmorDamageReduction
) :

	_Name(name),
	_HitPoints(HitPoints),
	_MaxhitPoints(MaxhitPoints),
	_EnergyPoints(EnergyPoints),
	_MaxEnergyPoints(MaxEnergyPoints),
	_Level(Level),
	_MeleeAttackDamage(MeleeAttackDamage),
	_RangedAttackDamage(RangedAttackDamage),
	_ArmorDamageReduction(ArmorDamageReduction)
{
	srand(time(NULL));
	std::cout << "Un nouveau ClapTrap est né !" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& other) :
	_Name(other._Name),
	_HitPoints(other._HitPoints),
	_MaxhitPoints(other._MaxhitPoints),
	_EnergyPoints(other._EnergyPoints),
	_MaxEnergyPoints(other._MaxEnergyPoints),
	_Level(other._Level),
	_MeleeAttackDamage(other._MeleeAttackDamage),
	_RangedAttackDamage(other._RangedAttackDamage),
	_ArmorDamageReduction(other._ArmorDamageReduction)
{
	srand(time(NULL));
}

//Destructor
ClapTrap::~ClapTrap(){
  std::cout << "Déstuctor called" << std::endl;
}

//Operator
ClapTrap &ClapTrap::operator=(const ClapTrap &other){
  _Name = other._Name;
  _HitPoints = other._HitPoints;
  _MaxhitPoints = other._MaxhitPoints;
  _EnergyPoints = other._EnergyPoints;
  _MaxEnergyPoints = other._MaxEnergyPoints;
  _Level = other._Level;
  _MeleeAttackDamage = other._MeleeAttackDamage;
  _RangedAttackDamage = other._RangedAttackDamage;
  _ArmorDamageReduction = other._ArmorDamageReduction;
  std::cout << "Copie parfaite de " << other._Name << " vien d'être faite !" << std::endl;
  srand(time(NULL));
  return (*this);
}

//Méthodes
void ClapTrap::rangedAttack(std::string const &target){
  _whoami(_Name, _HitPoints);
  std::cout << "Attaque " << target << " à distance, causant " << _RangedAttackDamage << " points de dégats !" << std::endl;
}

void ClapTrap::meleeAttack(std::string const &target){
  _whoami(_Name, _HitPoints);
  std::cout << "Attaque " << target << " à distance, causant " << _MeleeAttackDamage << " points de dégats !"<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
  _whoami(_Name, _HitPoints);
  amount -= _ArmorDamageReduction;
  _HitPoints -= amount;
  if (_HitPoints <= 0){
    std::cout << "Help I'm dying.." << std::endl;
    _HitPoints = 0;
  }
  std::cout << "Dam i took " << amount << " of damage..." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
  _whoami(_Name, _HitPoints);
  std::cout <<"I repairing..." << std::endl;
  _HitPoints += amount;
  if (_HitPoints >= _MaxhitPoints){
    std::cout << "Im full life" << std::endl;
    _HitPoints = _MaxhitPoints;
  }
}

std::string ClapTrap::getName(void) const{return (this->_Name);}

