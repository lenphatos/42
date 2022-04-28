#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "ClapTrap.hpp"

using namespace std;


int main(void) {

  std::cout << std::endl;
    ScavTrap clap("John");
    ScavTrap trap("Simon");
    FragTrap frag("Felix");
    NinjaTrap ninj("Denis");


	std::cout << std::endl;
    clap.rangedAttack("Pavlov");
    std::cout << "------------------------------------" << std::endl;
    trap.takeDamage(20);
    std::cout << "------------------------------------" << std::endl;
    clap.meleeAttack("Pavlov");
    std::cout << "------------------------------------" << std::endl;
    trap.takeDamage(30);
    std::cout << "------------------------------------" << std::endl;
    trap.beRepaired(35);
    std::cout << "------------------------------------" << std::endl;
    frag.rangedAttack("Michel");
    std::cout << "------------------------------------" << std::endl;
    trap.beRepaired(80);
    std::cout << "------------------------------------" << std::endl;
    trap.takeDamage(120);
    std::cout << "------------------------------------" << std::endl;
    frag.beRepaired(7);
    std::cout << "------------------------------------" << std::endl;
    trap.beRepaired(33);
    std::cout << "------------------------------------" << std::endl;
    frag.takeDamage(10);
    std::cout << "------------------------------------" << std::endl;
    frag.vaulthunter_dot_exe("Michel");
    std::cout << "------------------------------------" << std::endl;
    clap.challengeNewcomer("Pavlov");
    std::cout << "------------------------------------" << std::endl;
    clap.challengeNewcomer("Pavlov");
    std::cout << "------------------------------------" << std::endl;
    clap.challengeNewcomer("Pavlov");
    std::cout << "------------------------------------" << std::endl;
    ninj.ninjaShoebox(clap);
    std::cout << "------------------------------------" << std::endl;
    ninj.ninjaShoebox(frag);
    std::cout << "------------------------------------" << std::endl;
    ninj.ninjaShoebox(ninj);

 return 0;
}
