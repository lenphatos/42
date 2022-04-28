#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {

  std::cout << std::endl;
    ScavTrap scav1("John");
    ScavTrap scav2("Felix");
    FragTrap frag("Michel");

	std::cout << std::endl;
    scav1.rangedAttack("Felix");
    scav2.takeDamage(15);
    scav1.meleeAttack("Felix");
    scav2.takeDamage(20);
    scav2.beRepaired(35);
    frag.rangedAttack("John");
    scav2.beRepaired(80);
    scav2.takeDamage(120);
    frag.beRepaired(7);
    scav2.beRepaired(33);


	std::cout << "------------------"<<std::endl;

    frag.vaulthunter_dot_exe("John");
    scav1.challengeNewcomer("Felix");
    scav1.challengeNewcomer("Felix");
    scav1.challengeNewcomer("Felix");

	std::cout << std::endl;
 return 0;
}
