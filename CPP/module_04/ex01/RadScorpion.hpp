#ifndef RADSCORPION_HPP
#define RADSCORPION_HPP
#include <iostream>
#include <string>
#include "Enemy.hpp"

class RadScorpion : public Enemy {

  public:
    // Constructor
    RadScorpion();
    RadScorpion(RadScorpion const& other);
    virtual ~RadScorpion();
    RadScorpion &operator=(RadScorpion const& other);

    // Methodes
    virtual void  takeDamage(int nb);

  private:
};

#endif
