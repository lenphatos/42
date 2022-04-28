#include <iostream>
#include <string>
#include "ZombieEvent.hpp"
#include "Zombie.hpp"

int main()
{
  ZombieEvent   event;
  Zombie        *zombie;

  zombie = new Zombie("Simon", "WEAK");
  zombie->advert();
  delete zombie;

  event.setZombieType("STRONG");
  zombie = event.newZombie("bob");
  zombie->advert();
  delete zombie;

  zombie = event.newZombie("felix");
  zombie->advert();
  delete zombie;

  event.setZombieType("BOSS");
  zombie = event.randomChump();
  zombie->advert();
  delete zombie;
  return (0);
}
