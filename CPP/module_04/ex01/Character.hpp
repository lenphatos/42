#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>
#include <string>
#include "Enemy.hpp"
#include "AWeapon.hpp"

class Character {

  public:
    // Constructor
    Character(std::string const& name);
    Character(Character const& other);
    virtual ~Character();
    Character &operator=(Character const& other);

    // Methodes
    void recoverAP();
    void equip(AWeapon *weapon);
    void attack(Enemy *enemy);
    int           getAP() const;
    int           getequip() const;
    std::string   getName() const;
    std::string   getWeapon() const;

  protected:
    std::string   _Name;
    int           _AP;
    AWeapon *     _Weapon;
    int           _Equip;
};

std::ostream &operator<<(std::ostream &flux, Character const &other);

#endif
