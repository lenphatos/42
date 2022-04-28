#ifndef AWEAPON_HPP
#define AWEAPON_HPP
#include <iostream>
#include <string>

class AWeapon {

  public:
    // Constructor
    AWeapon(std::string const& name, int apcost, int damage);
    AWeapon(AWeapon const& other);
    virtual ~AWeapon();
    AWeapon &operator=(AWeapon const& other);

    // Methodes
    std::string   getName() const;
    int           getAPCost() const;
    int           getDamage() const;
    virtual void  attack() const = 0;

  protected:
    std::string   _Name;
    int           _APCost;
    int           _Damage;

};

#endif
