#include <iostream>
#include <string>
#include "NinjaTrap.hpp"

//Constructor
NinjaTrap::NinjaTrap() :
ClapTrap("", 0, 0, 0, 0, 0, 0, 0, 0)
{
  srand (time(NULL));
  _whoami(_Name, _HitPoints);
  std::cout <<  "I'm ready for War" << std::endl;
}

NinjaTrap::NinjaTrap(std::string name) :
ClapTrap(
  name,
  60,
  60,
  120,
  120,
  1,
  60,
  5,
  0
)
{
  srand (time(NULL));
  _whoami(_Name, _HitPoints);
  std::cout <<  "I'm ready for War" << std::endl;
}

NinjaTrap::NinjaTrap(const NinjaTrap &other) :
ClapTrap(other)
{
	srand(time(NULL));
	_whoami(_Name, _HitPoints);
	std::cout << "Je vais me cloner en NinjaTrap : " << other._Name << std::endl;
}

//Operator
NinjaTrap &NinjaTrap::operator=(const NinjaTrap &other){
  ClapTrap::operator=(other);
  srand (time(NULL));
  return (*this);
}

//Destructor
NinjaTrap::~NinjaTrap(){
  std::cout << "Déstuctor called" << std::endl;
}

// Méthodes


void NinjaTrap::ninjaShoebox(const ScavTrap &target){
  _whoami(_Name, _HitPoints);
  std::cout <<  "Attaque " << target.getName() << " avec deux baguettes" << std::endl;
}
void NinjaTrap::ninjaShoebox(const NinjaTrap &target){
  _whoami(_Name, _HitPoints);
  std::cout <<  "Attaque " << target.getName() << " avec le Sabre volant" << std::endl;
}
void NinjaTrap::ninjaShoebox(const FragTrap &target){
  _whoami(_Name, _HitPoints);
  std::cout <<  "Attaque " << target.getName() << " avec le  Dragon de Feux" << std::endl;
}
