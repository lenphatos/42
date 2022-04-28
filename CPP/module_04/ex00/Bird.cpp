#include "Bird.hpp"

// Constructor & Destructor
Bird::Bird(std::string name) : Victim(name){
  std::cout << "Piou Piou." << std::endl;
}

Bird::~Bird(){
  std::cout << "Slatchhh..." << std::endl;
}

Bird::Bird(Bird const &other) : Victim(other){
  std::cout << "Piou Piou." << std::endl;
}

// Operator
Bird &Bird::operator=(Bird const &other){
  if (this != &other){
    Victim::operator=(other);
  }
  return(*this);
}

std::ostream &operator<<(std::ostream &flux, Bird const &other){
  other.presentation_flux(flux);
  return (flux);
}


// Methodes

void Bird::getPolymorphed() const{
  std::cout << _Name << " has been turned into a litte bee" << std::endl;
}

void Bird::presentation_flux(std::ostream &flux) const{
  flux << "I'm " << _Name << " and I like Fly!" << std::endl;
}
