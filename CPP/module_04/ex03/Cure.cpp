#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& other) : AMateria(other) {}

Cure::~Cure() {}

Cure &Cure::operator=(Cure const &other) {
  if (this != &other) {
    AMateria::operator=(other);
  }
  return (*this);
}

AMateria* Cure::clone() const {return (new Cure(*this));}

void Cure::use(ICharacter& target) {
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
  AMateria::use(target);
}
