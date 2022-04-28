#include <iostream>
#include <string>
#include "FragTrap.hpp"


typedef void(FragTrap::*attacks)(std::string const & target);

//Constructor
FragTrap::FragTrap() :
ClapTrap("", 0, 0, 0, 0, 0, 0, 0, 0)
{
  srand (time(NULL));
  _whoami(_Name, _HitPoints);
  std::cout <<  "I'm ready for War" << std::endl;
}

FragTrap::FragTrap(std::string name) :
ClapTrap(
  name,
  100,
  100,
  100,
  100,
  1,
  30,
  20,
  5
)
{
  srand(time(NULL));
  _whoami(_Name, _HitPoints);
  std::cout <<  "I'm ready for War" << std::endl;
}

//Destructor
FragTrap::~FragTrap(){
  std::cout << "Déstuctor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) :
ClapTrap(other)
{
	srand(time(NULL));
	_whoami(_Name, _HitPoints);
	std::cout << "Je vais me cloner en FragTrap : " << other._Name << std::endl;
}

//Operator
FragTrap &FragTrap::operator=(const FragTrap &other){
  ClapTrap::operator=(other);
  srand(time(NULL));
  return (*this);
}

//Méthodes

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
