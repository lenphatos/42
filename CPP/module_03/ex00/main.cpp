#include <iostream>
#include "FragTrap.hpp"

using namespace std;


int main(void) {

  FragTrap rob1("BOB");

  rob1.takeDamage(10);
  rob1.beRepaired(10);
  rob1.vaulthunter_dot_exe("John");
  rob1.rangedAttack("TONY");
  cout << "\n\n" << endl;

  FragTrap rob2("John");
  rob2.vaulthunter_dot_exe("John");
  rob2.takeDamage(100);
  rob2.beRepaired(10);
  rob2.beRepaired(90);
  rob2.beRepaired(90);
  rob2.vaulthunter_dot_exe("John");
  rob2.vaulthunter_dot_exe("John");
  rob2.vaulthunter_dot_exe("John");
  rob2.vaulthunter_dot_exe("John");

 return 0;
}
