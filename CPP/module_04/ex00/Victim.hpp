#ifndef VICTIM_HPP
#define VICTIM_HPP
#include <iostream>
#include <ostream>

class Victim {

  public:
  // Constructor & Destructor
    Victim(std::string name);
    Victim(Victim const& other);
    virtual ~Victim();

  // Operators
    Victim &operator=(Victim const& other);

  //Methodes
    void presentation_flux(std::ostream& flux) const;
    virtual void getPolymorphed() const;


  //Attributs
  protected:
    std::string _Name;

};

std::ostream &operator<<(std::ostream &flux, Victim const &other);

#endif
