#include <iostream>
#include <string>
#include "AssaultTerminator.hpp"
#include "ISpaceMarine.hpp"
#include "TacticalMarine.hpp"
#include "Squad.hpp"
#include "ISquad.hpp"

int main(){

  ISpaceMarine *bob = new TacticalMarine;
  ISpaceMarine *jim = new AssaultTerminator;

  ISquad *vlc = new Squad;
  vlc->push(bob);
  vlc->push(jim);
  for (int i = 0; i < vlc->getCount(); i++){
    ISpaceMarine* cur = vlc->getUnit(i);
    cur->battleCry();
    cur->rangedAttack();
    cur->meleeAttack();
  }
  delete vlc;

std::cout << "---------------------------------------------" << std::endl;

  AssaultTerminator	  *john = new AssaultTerminator;
  ISpaceMarine		    *felix = new AssaultTerminator(*john);

  TacticalMarine		  *simon = new TacticalMarine;
  ISpaceMarine		    *isma = new TacticalMarine(*simon);

  Squad				      *squad = new Squad;
  Squad				      *copy = new Squad;

  squad->push(felix);
  squad->push(isma);
  std::cout << squad->getCount() << std::endl;


  std::cout << "Copy :" << std::endl;
  *copy = *squad;
  std::cout << copy->getCount() << std::endl;
  std::cout << "END Copy" << std::endl;


  std::cout << std::endl;

  std::cout << "Delete :" << std::endl << std::endl;

  std::cout << std::endl << "Delete Squad :" << std::endl << std::endl;
  delete squad;
  return 0;
}
