#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP
#include "Zombie.hpp"



class ZombieHorde {

  public:
    //constructeur
     ZombieHorde(int n);
     ZombieHorde(std::string name, std::string type);
     ~ZombieHorde();

    // methodes
    void announce();




  private:
    // atributs
    int         m_N;
    Zombie      *m_Horde;

};

#endif
