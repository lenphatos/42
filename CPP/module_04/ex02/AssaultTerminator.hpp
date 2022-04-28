#ifndef ASSAULTTERMINATOR_HPP
#define ASSAULTTERMINATOR_HPP
#include <iostream>
#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine {

  public:
    // Constructor & Destrucor
    AssaultTerminator();
    AssaultTerminator(AssaultTerminator const& other);
    virtual ~AssaultTerminator();
    AssaultTerminator &operator=(AssaultTerminator const& other);

    // Methodes
    AssaultTerminator* clone() const;
    void battleCry() const;
    void rangedAttack() const;
    void meleeAttack() const;
};

#endif
