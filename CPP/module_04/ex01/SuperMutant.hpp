#ifndef SUPERMUTANT_HPP
#define SUPERMUTANT_HPP
#include <iostream>
#include <string>
#include "Enemy.hpp"

class SuperMutant : public Enemy {

  public:
    // Constructor
    SuperMutant();
    SuperMutant(SuperMutant const& other);
    virtual ~SuperMutant();
    SuperMutant &operator=(SuperMutant const& other);

    // Methodes
    virtual void  takeDamage(int nb);

  private:
};

#endif
