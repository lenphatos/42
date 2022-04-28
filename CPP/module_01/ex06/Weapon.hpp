#ifndef WEAPON_HPP
# define WEAPON_HPP
#include <iostream>
#include "Weapon.hpp"

class Weapon {

  public:
  //constructeur
   Weapon();
   Weapon(std::string type);
   ~Weapon();

  // methodes
  void          setType(std::string type);
  std::string   &getType();




  private:
    // atributs
    std::string m_type;
};

#endif
