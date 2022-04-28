#include <iostream>
#include <string>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

static void _whoami(std::string& name, unsigned int hp)
{
	std::cout << "SC4V-TP \033[1;34m" << name << "\033[0m(\033[1;32m" << hp << "\033[0m) : " << std::endl;
}

//Constructor
ScavTrap::ScavTrap(){
  srand(time(NULL));
}

ScavTrap::ScavTrap(std::string name) :
  _Name(name),
  _HitPoints(100),
  _MaxhitPoints(100),
  _EnergyPoints(50),
  _MaxEnergyPoints(50),
  _Level(1),
  _MeleeAttackDamage(20),
  _RangedAttackDamage(15),
  _ArmorDamageReduction(3)
{
  srand(time(NULL));
  std::cout << "Bien le bonsoir, je me présente " << _Name << " je vais protéger cette endroit jusqu'à la mort" << std::endl;
}

//Destructor
ScavTrap::~ScavTrap(){
  std::cout << "Déstuctor called" << std::endl;
}

//Operator
ScavTrap &ScavTrap::operator=(const ScavTrap &other){
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

void ScavTrap::rangedAttack(std::string const &target){
  _whoami(_Name, _HitPoints);
  std::cout << "Attaque " << target << " à distance, causant " << _RangedAttackDamage << " points de dégats !" << std::endl;
}

void ScavTrap::meleeAttack(std::string const &target){
  _whoami(_Name, _HitPoints);
  std::cout << "Attaque " << target << " à distance, causant " << _RangedAttackDamage << " points de dégats !" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount){
  _whoami(_Name, _HitPoints);
  amount -= _ArmorDamageReduction;
  _HitPoints -= amount;
  std::cout << "Noo j'ai beau être matinale mais " << amount << " de dommage ça fait mal..." << std::endl;
  if (_HitPoints <= 0){
    std::cout << "Réparais moi vite ma vie est fini" << std::endl;
    _HitPoints = 0;
  }
}

void ScavTrap::beRepaired(unsigned int amount){
  _whoami(_Name, _HitPoints);
  std::cout << "Bsss Pshhhh tac tac.. Je suis de retour fort comme jamais" << std::endl;
  _HitPoints += amount;
  if (_HitPoints >= _MaxhitPoints){
    std::cout << "Je me suis rarement senti aussi bien je suis full vie quel plaisir" << std::endl;
    _HitPoints = _MaxhitPoints;
  }
}

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
  else {
    std::cout << target  << " ! Bienvenue j'ai plusieur défie pour toi... que dirait tu " << random_defi[rand() % 5] << std::endl;
    this->_EnergyPoints -= 25;
  }
}
