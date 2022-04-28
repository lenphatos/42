#include "SuperMutant.hpp"

SuperMutant::SuperMutant() :
Enemy(170, "Super Mutant")
{
  std::cout << "Gaaah. Break everything!" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const& other) :
Enemy(other)
{}

SuperMutant::~SuperMutant(){
  std::cout << "Aaargh ..." << std::endl;
}

SuperMutant &SuperMutant::operator=(SuperMutant const& other) {
  if (this != &other){
    Enemy::operator=(other);
  }
  return (*this);
}

void SuperMutant::takeDamage(int nb) {
  ((nb - 3) > 0) ? _Hp -= (nb - 3) : 0;
  (_Hp < 0) ? _Hp = 0 : 0;
}
