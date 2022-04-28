#ifndef TACTICALMARINE_HPP
#define TACTICALMARINE_HPP
#include <iostream>
#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine {

  public:
    // Constructor & Destrucor
    TacticalMarine();
    TacticalMarine(TacticalMarine const &other);
    virtual ~TacticalMarine();
    TacticalMarine &operator=(TacticalMarine const &other);

    // Methodes
    TacticalMarine* clone() const;
    void battleCry() const;
    void rangedAttack() const;
    void meleeAttack() const;
};

#endif
