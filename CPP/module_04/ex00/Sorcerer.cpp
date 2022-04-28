#include "Sorcerer.hpp"

// Constructor & Destructor
Sorcerer::Sorcerer(std::string name, std::string title) : _Name(name), _Title(title){
  std::cout << _Name << ", " << _Title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer(){
  std::cout << _Name << ", " << _Title << ", is dead. Consequences will never be the same!" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const &other) : _Name(other._Name), _Title(other._Title){
  std::cout << _Name << ", " << _Title << ", is born!" << std::endl;
}

// Operator
Sorcerer &Sorcerer::operator=(Sorcerer const &other){
  if (this != &other){
    _Name = other._Name;
    _Title = other._Title;
  }
  return(*this);
}

std::ostream &operator<<(std::ostream &flux, Sorcerer const &other){
  other.presentation_flux(flux);
  return (flux);
}


// Methodes

void Sorcerer::presentation_flux(std::ostream &flux) const{
  flux << "I am " << _Name << ", " << _Title << ", and i like ponies!" << std::endl;
}

void Sorcerer::polymorph(Victim const &other) const{
  other.getPolymorphed();
}
