#include "AMateria.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main(){

  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());

  Character* moi = new Character("moi");

  AMateria* tmp = NULL;
  AMateria* tmp2 = NULL;
  tmp = src->createMateria("ice");
  moi->equip(tmp);
  std::cout << "ICE = " << tmp->getType() << std::endl;

  tmp2 = src->createMateria("cure");
  moi->equip(tmp2);
  std::cout << "CURE = " << tmp2->getType() << std::endl;

  ICharacter* bob = new Character("bob");

  moi->use(0, *bob);
  moi->use(1, *bob);
  std::cout  << tmp->getType() << " XP : " << tmp->getXP() << std::endl;
  std::cout  << tmp2->getType() << " XP : " << tmp2->getXP() << std::endl;


  moi->use(0, *bob);
  std::cout << tmp->getType() << " xp = " << tmp->getXP() << std::endl;
  std::cout << tmp2->getType() << " xp = " << tmp2->getXP() << std::endl;


  std::cout << "-------------COPY-----------------" << std::endl;

  Character copy = Character(*moi);

  AMateria* one = new Ice();
  AMateria* two = new Cure();
  copy.equip(one);


  copy.equip(two);
  copy.equip(two);
  copy.equip(two);
  copy.equip(two);





  copy.use(0, *bob);
  copy.use(2, *bob);


  std::cout << tmp->getType() << " xp = " << tmp->getXP() << std::endl;
  std::cout << one->getType() << " xp = " << one->getXP() << std::endl;
  delete bob;
  delete src;
  return 0;
}
