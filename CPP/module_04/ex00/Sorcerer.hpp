#ifndef SORCERER_HPP
#define SORCERER_HPP
#include <iostream>
#include <ostream>
#include "Victim.hpp"

class Sorcerer {

  public:
  // Constructor & Destructor
    Sorcerer(std::string name, std::string title);
    Sorcerer(Sorcerer const& other);
    ~Sorcerer();

  // Operators
    Sorcerer &operator=(Sorcerer const& other);

  //Methodes
    void presentation_flux(std::ostream& flux) const;
    void polymorph(Victim const &other) const;


  //Attributs
  private:
    std::string _Name;
    std::string _Title;

};

std::ostream &operator<<(std::ostream &flux, Sorcerer const &other);

#endif
