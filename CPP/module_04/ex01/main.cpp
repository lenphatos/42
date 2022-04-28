#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "Character.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include "Enemy.hpp"
#include <iostream>
#include <string>

int main(){

  Character* moi = new Character("moi");

  std::cout << *moi;

  Enemy* b = new RadScorpion();
  Enemy* a = new SuperMutant();

  AWeapon* pr = new PlasmaRifle();
  AWeapon* pf = new PowerFist();

  moi->equip(pr);
  std::cout << *moi;
  moi->equip(pf);

  moi->attack(b);
  std::cout << *moi;
  moi->equip(pr);
  std::cout << *moi;
  moi->attack(b);
  std::cout << *moi;
  moi->attack(b);
  std::cout << *moi;
  std::cout << "Target HP : " << b->getHP() << std::endl;
  moi->attack(b);
  std::cout << "Target HP : " << b->getHP() << std::endl;
  std::cout << *moi;
  moi->attack(a);
  std::cout << *moi;
  moi->attack(a);
  std::cout << *moi;
  moi->attack(a);
  std::cout << *moi;
  moi->attack(a);
  std::cout << *moi;
  moi->attack(a);
  std::cout << *moi;
  moi->attack(a);
  moi->recoverAP();
  std::cout << *moi;
  moi->attack(a);
  std::cout << *moi;
  moi->attack(a);
  std::cout << *moi;
  moi->attack(a);
  return 0;
}
