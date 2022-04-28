#include "Victim.hpp"

// Constructor & Destructor
Victim::Victim(std::string name) : _Name(name){
  std::cout << "Some random victim called " << _Name << " just appeared!" << std::endl;
}

Victim::~Victim(){
  std::cout << "The victim " << _Name << " just died for no apparent reasons!" << std::endl;
}

Victim::Victim(Victim const &other) : _Name(other._Name){
  std::cout << "Some random victim called " << _Name << " just appeared!" << std::endl;
}

// Operator
Victim &Victim::operator=(Victim const &other){
  if (this != &other){
    _Name = other._Name;
  }
  return(*this);
}

std::ostream &operator<<(std::ostream &flux, Victim const &other){
  other.presentation_flux(flux);
  return (flux);
}


// Methodes

void Victim::presentation_flux(std::ostream &flux) const{
  flux << "I'm " << _Name << " and I like otters!" << std::endl;
}

void Victim::getPolymorphed() const{
  std::cout << _Name << " has been turned into a cute little sheep!" << std::endl;
}
