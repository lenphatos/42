#ifndef BIRD_HPP
#define BIRD_HPP
#include <iostream>
#include <ostream>
#include "Victim.hpp"

class Bird : public Victim {

  public:
  // Constructor & Destructor
    Bird(std::string name);
    Bird(Bird const& other);
    virtual ~Bird();

  // Operators
    Bird &operator=(Bird const& other);

  //Methodes
    void presentation_flux(std::ostream& flux) const;
    virtual void getPolymorphed() const;


  //Attributs
  private:

};

std::ostream &operator<<(std::ostream &flux, Bird const &other);

#endif
