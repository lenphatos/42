#include "SuperTrap.hpp"

//Constructor
SuperTrap::SuperTrap() :
ClapTrap("", 0, 0, 0, 0, 0, 0, 0, 0)
{
  srand (time(NULL));
  _whoami(_Name, _HitPoints);
  std::cout <<  "Super trap has been create" << std::endl;
}

SuperTrap::SuperTrap(std::string name) :
ClapTrap(
  name,
  100,
  100,
  120,
  120,
  1,
  60,
  30,
  5
)
{
  srand(time(NULL));
  _whoami(_Name, _HitPoints);
  std::cout <<  "Super trap has been create" << std::endl;
}

//Destructor
SuperTrap::~SuperTrap(){
  std::cout << "Déstuctor called" << std::endl;
}

SuperTrap::SuperTrap(SuperTrap const &other) :
ClapTrap(other)
{
	srand(time(NULL));
	_whoami(_Name, _HitPoints);
	std::cout << "Je vais me cloner en SuperTrap : " << other._Name << std::endl;
}

//Operator
SuperTrap &SuperTrap::operator=(SuperTrap const &other){
  ClapTrap::operator=(other);
  srand(time(NULL));
  return (*this);
}
