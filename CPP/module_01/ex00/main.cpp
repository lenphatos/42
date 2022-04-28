#include <iostream>
#include <string>
#include "Pony.hpp"

void ponyOnTheHeap()
{
  Pony *bob = new Pony(18, 1, "jaune", "BOB");
  bob->describe();
  delete bob;
  std::cout << "End of BOB ;'(" << std::endl;
}

void ponyOnTheStack()
{
  Pony jcvd(36, 2, "rouge", "JCVD");
  jcvd.describe();
}

int main()
{
  std::cout << "\n--------HEAP--------" << std::endl;
  ponyOnTheHeap();
  std::cout << "\n--------STACK--------" << std::endl;
  ponyOnTheStack();
  std::cout << "\n--------LEAKS--------" << std::endl;
  system("leaks a.out");
  return (0);
}
