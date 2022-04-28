#include <iostream>
#include <string>
#include "ZombieHorde.hpp"
#include "Zombie.hpp"

int main()
{
  std::cout << "---------HORDE--------" << std::endl;
  //Creation Horde
  ZombieHorde horde = ZombieHorde(5);
  horde.announce();

  std::cout << "-----EMPTY_HORDE------" << std::endl;

  //Creation Horde vide
  ZombieHorde horde2 = ZombieHorde(0);
  horde2.announce();
  return (0);
}
