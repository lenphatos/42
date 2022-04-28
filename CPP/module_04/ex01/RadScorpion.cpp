#include "RadScorpion.hpp"

RadScorpion::RadScorpion() :
Enemy(80, "RadScorpion")
{
  std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(RadScorpion const& other) :
Enemy(other)
{}

RadScorpion::~RadScorpion(){
  std::cout << "* SPROTCH *" << std::endl;
}

RadScorpion &RadScorpion::operator=(RadScorpion const& other) {
  if (this != &other){
    Enemy::operator=(other);
  }
  return (*this);
}

void RadScorpion::takeDamage(int nb) {
  (nb > 0) ? _Hp -= nb : 0;
  (_Hp < 0) ? _Hp = 0 : 0;
}
