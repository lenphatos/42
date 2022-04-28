#include "Peon.hpp"

// Constructor & Destructor
Peon::Peon(std::string name) : Victim(name){
  std::cout << "Zog zog." << std::endl;
}

Peon::~Peon(){
  std::cout << "Bleuark..." << std::endl;
}

Peon::Peon(Peon const &other) : Victim(other){
  std::cout << "Zog zog." << std::endl;
}

// Operator
Peon &Peon::operator=(Peon const &other){
  if (this != &other){
    Victim::operator=(other);
  }
  return(*this);
}

std::ostream &operator<<(std::ostream &flux, Peon const &other){
  other.presentation_flux(flux);
  return (flux);
}


// Methodes

void Peon::getPolymorphed() const{
  std::cout << _Name << " has been turned into a pink pony!" << std::endl;
}

void Peon::presentation_flux(std::ostream &flux) const{
  flux << "I'm " << _Name << " and I like otters!" << std::endl;
}
