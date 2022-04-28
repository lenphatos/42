#ifndef POWERFIST_HPP
#define POWERFIST_HPP
#include "AWeapon.hpp"
#include <iostream>
#include <string>

class PowerFist : public AWeapon {

  public:
    // Constructor
    PowerFist();
    PowerFist(PowerFist const& other);
    ~PowerFist();
    PowerFist &operator=(PowerFist const& other);

    // Methodes
    virtual void attack() const;

  private:

};

#endif
