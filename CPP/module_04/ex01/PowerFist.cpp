#include "PowerFist.hpp"

PowerFist::PowerFist() :
AWeapon("Power Fist", 8, 50)
{}

PowerFist::PowerFist(PowerFist const& other) :
AWeapon(other)
{}

PowerFist::~PowerFist(){}

PowerFist &PowerFist::operator=(PowerFist const& other){
  if (this != &other){
    AWeapon::operator=(other);
  }
  return (*this);
}

void PowerFist::attack() const {
  std::cout << "* pschhh... SBAM ! *" << std::endl;
}
