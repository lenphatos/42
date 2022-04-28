#include <iostream>
#include <string>
#include "FragTrap.hpp"

typedef void(FragTrap::*attacks)(std::string const & target);

static void _whoami(std::string& name, unsigned int hp)
{
	std::cout << "FR4G-TP \033[1;31m" << name << "\033[0m(\033[1;32m" << hp << "\033[0m) : " << std::endl;
}

//Constructor
FragTrap::FragTrap(){
  srand ( time(NULL) );
}

FragTrap::FragTrap(std::string name) :
  _Name(name),
  _HitPoints(100),
  _MaxhitPoints(100),
  _EnergyPoints(100),
  _MaxEnergyPoints(100),
  _Level(1),
  _MeleeAttackDamage(30),
  _RangedAttackDamage(20),
  _ArmorDamageReduction(5)
{
  srand ( time(NULL) );
  _whoami(_Name, _HitPoints);
  std::cout <<  "I'm ready for War" << std::endl;
}

//Destructor
FragTrap::~FragTrap(){
  std::cout << "Déstuctor called" << std::endl;
}

//Operator
FragTrap &FragTrap::operator=(const FragTrap &other){
  srand ( time(NULL) );
  _Name = other._Name;
  _HitPoints = other._HitPoints;
  _MaxhitPoints = other._MaxhitPoints;
  _EnergyPoints = other._EnergyPoints;
  _MaxEnergyPoints = other._MaxEnergyPoints;
  _Level = other._Level;
  _MeleeAttackDamage = other._MeleeAttackDamage;
  _RangedAttackDamage = other._RangedAttackDamage;
  _ArmorDamageReduction = other._ArmorDamageReduction;
  return (*this);
}

//Méthodes

void FragTrap::rangedAttack(std::string const &target){
  _whoami(_Name, _HitPoints);
  std::cout << "Attaque " << target << " à distance, causant " << _RangedAttackDamage << " points de dégats !" << std::endl;
}

void FragTrap::meleeAttack(std::string const &target){
  _whoami(_Name, _HitPoints);
  std::cout << "Attaque " << target << " au corps à corps, causant " << _MeleeAttackDamage << " points de dégats !" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount){
  _whoami(_Name, _HitPoints);
  amount -= _ArmorDamageReduction;
  _HitPoints -= amount;
  if (_HitPoints <= 0){
    std::cout << "Help I'm dying.." << std::endl;
    _HitPoints = 0;
  }
  std::cout << "Dam i took " << amount << " of damage..." << std::endl;
}

void FragTrap::beRepaired(unsigned int amount){
  _whoami(_Name, _HitPoints);
  std::cout <<"I repairing..." << std::endl;
  _HitPoints += amount;
  if (_HitPoints >= _MaxhitPoints){
    std::cout << "Im full life" << std::endl;
    _HitPoints = _MaxhitPoints;
  }
}

void FragTrap::attack_ninja(std::string const &target){
   _whoami(_Name, _HitPoints);
  std::cout <<  "Attaque " << target << " avec les 100 frappes de Nunchaku" << std::endl;
}

void FragTrap::attack_samourai(std::string const &target){
  std::cout <<  "Attaque " << target << " avec un coup de sabre fatale" << std::endl;
}

void FragTrap::attack_sel(std::string const &target){
  std::cout <<  "Attaque " << target << " avec un lancé de sel" << std::endl;
}

void FragTrap::attack_supreme(std::string const &target){
 std::cout <<  "Attaque " << target << " avec amour" << std::endl;
}

void FragTrap::attack_gun(std::string const &target){
  std::cout <<  "Attaque " << target << " à grand coup de machine-gun" << std::endl;
}

void FragTrap::vaulthunter_dot_exe(std::string const & target){
  attacks attack[] =
  {
    &FragTrap::attack_ninja,
    &FragTrap::attack_samourai,
    &FragTrap::attack_sel,
    &FragTrap::attack_supreme,
    &FragTrap::attack_gun
  };
  _whoami(_Name, _HitPoints);
  if (_EnergyPoints < 25)
    std::cout << "No enought Energy for attack " << target << std::endl;
  else {
    (this->*attack[rand() % 5])(target);
    this->_EnergyPoints -= 25;
  }
}
