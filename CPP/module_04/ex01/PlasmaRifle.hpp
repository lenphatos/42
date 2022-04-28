#ifndef PLASMARIFLE_HPP
#define PLASMARIFLE_HPP
#include "AWeapon.hpp"
#include <iostream>
#include <string>

class PlasmaRifle : public AWeapon {

  public:
    // Constructor
    PlasmaRifle();
    PlasmaRifle(PlasmaRifle const& other);
    ~PlasmaRifle();
    PlasmaRifle &operator=(PlasmaRifle const& other);

    // Methodes
    virtual void attack() const;

  private:

};

#endif
