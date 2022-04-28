#ifndef HUMANB_HPP
#define HUMANB_HPP

class HumanB {

public:
//constructeur
 HumanB(std::string name);
 ~HumanB();

// methodes
void setWeapon(Weapon &club);
void attack();



private:
  // atributs
  Weapon        *m_weapon;
  std::string   m_name;

};

#endif
