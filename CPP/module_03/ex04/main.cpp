#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "ClapTrap.hpp"
#include "SuperTrap.hpp"

int main(void) {

  std::cout << std::endl;
    ScavTrap clap("John");
    std::cout << "------------------------------------" << std::endl;

    FragTrap frag("Felix");
    std::cout << "------------------------------------" << std::endl;

    SuperTrap sup("Simon");
    sup.ninjaShoebox(frag);
    sup.vaulthunter_dot_exe("Denis");
    std::cout << "------------------------------------" << std::endl;


	std::cout << std::endl;



 return 0;
}
