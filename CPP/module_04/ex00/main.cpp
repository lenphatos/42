#include <iostream>
#include <string>
#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "Bird.hpp"

int main()
{
  Sorcerer robert("Robert", "the Magnificent");

  Victim jim("Jimmy");
  Peon joe("Joe");

  std::cout << robert << jim << joe;

  robert.polymorph(jim);
  robert.polymorph(joe);


  std::cout << "---------------------" << std::endl;

  Sorcerer robart("Robart", "The BEST");
  Bird bird("Marius");
  Bird other(bird);

  std::cout << bird;

  robart.polymorph(bird);

  robert = robart;
  std::cout << robert << robart;

  std::cout << "---------------------" << std::endl;


  return 0;
}
