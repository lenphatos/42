#include <iostream>
#include <string>
#include "ScavTrap.hpp"

using namespace std;

//Constructor
ScavTrap::ScavTrap() :
ClapTrap("", 0, 0, 0, 0, 0, 0, 0, 0)
{
  srand (time(NULL));
  _whoami(_Name, _HitPoints);
  std::cout <<  "Vous ne passerez pas !" << std::endl;
}

ScavTrap::ScavTrap(std::string name) :
ClapTrap(
  name,
  100,
  100,
  50,
  50,
  1,
  20,
  15,
  3
)
{
  srand (time(NULL));
  _whoami(_Name, _HitPoints);
  std::cout <<  "Vous ne passerez pas !" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) :
ClapTrap(other)
{
	srand(time(NULL));
	_whoami(_Name, _HitPoints);
	std::cout << "Je vais me cloner en ScavTrap : " << other._Name << std::endl;
}

//Operator
ScavTrap &ScavTrap::operator=(const ScavTrap &other){
  ClapTrap::operator=(other);
  srand (time(NULL));
  return (*this);
}

//Destructor
ScavTrap::~ScavTrap(){
  std::cout << "Déstuctor called" << std::endl;
}

//Méthodes
void ScavTrap::challengeNewcomer(std::string const & target){
  _whoami(_Name, _HitPoints);
  std::string random_defi[5] =
  {
    "d'essayer de me battre en duel jusqu'à la mort ?",
    "d'essayer de réussire a manger plus de Boulons que moi ?",
    "d'essayer de me battre au bras de fer ?",
    "d'essayer de me battre dans un partie d'echec ?",
    "d'essayer de sauter plus haut que moi ? "
  };
  if (_EnergyPoints < 25)
    std::cout << "Il me manque de l'energie, tchao pas d'heure supp pour ma part." << std::endl;
  else{
    std::cout << target  << " ! Bienvenue j'ai plusieur défie pour toi... que dirais tu " << random_defi[rand() % 5] << std::endl;
    this->_EnergyPoints -= 25;
  }
}
