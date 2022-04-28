#ifndef PEON_HPP
#define PEON_HPP
#include <iostream>
#include <ostream>
#include "Victim.hpp"

class Peon : public Victim {

  public:
  // Constructor & Destructor
    Peon(std::string name);
    Peon(Peon const& other);
    virtual ~Peon();

  // Operators
    Peon &operator=(Peon const& other);

  //Methodes
    void presentation_flux(std::ostream& flux) const;
    virtual void getPolymorphed() const;


  //Attributs
  private:

};

std::ostream &operator<<(std::ostream &flux, Peon const &other);

#endif
