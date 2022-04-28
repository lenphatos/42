#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"
class HumanA {

  public:
  //constructeur
   HumanA();
   HumanA(std::string name , Weapon &weapon);
   ~HumanA();

  // methodes
  void attack();



  private:
    // atributs
    std::string   m_name;
    Weapon        &m_weapon;

};

#endif
