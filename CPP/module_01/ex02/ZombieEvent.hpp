#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

#include "Zombie.hpp"

class ZombieEvent {

  public:
    //constructeur
     ZombieEvent();
     ZombieEvent(std::string type);
     ~ZombieEvent();

    // methodes
    void setZombieType(std::string type);
    Zombie *newZombie(std::string name);
    Zombie *randomChump();




  private:
    // atributs
    std::string m_type;

};

#endif
