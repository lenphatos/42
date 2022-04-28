#include <iostream>
#include <string>
#include <cstdlib>
#include "ZombieEvent.hpp"
#include "Zombie.hpp"

ZombieEvent::ZombieEvent(){}

ZombieEvent::~ZombieEvent(){}

void ZombieEvent::setZombieType(std::string type){
  m_type = type;
}

Zombie *ZombieEvent::newZombie(std::string name){
  return (new Zombie(name, m_type));
}

Zombie *ZombieEvent::randomChump(){
  std::string random_name[5] =
  {
    "Charle",
    "John",
    "Richard",
    "Tonny",
    "Rufus"
  };
  srand ( time(NULL) );
  return (new Zombie(random_name[rand() % 5], m_type));
}
