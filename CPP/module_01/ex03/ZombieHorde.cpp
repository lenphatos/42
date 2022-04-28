#include <iostream>
#include <string>
#include <vector>
#include "Zombie.hpp"
#include "ZombieHorde.hpp"

using namespace std;

ZombieHorde::ZombieHorde(int n){
  srand(time(NULL));
  m_N = n;
  std::string m_listName[10] = {
    "BOB",
    "PETER",
    "JACK",
    "JOHN",
    "HENRY",
    "RACHID",
    "SPOK",
    "SPUK",
    "SPIK",
    "MARCEL"
  };
  m_Horde = new Zombie[n];
for (int i = 0; i < n; i++ ){
    m_Horde[i].setName(m_listName[rand() % 10]);
    m_Horde[i].setType("BOSS");
  }
}

ZombieHorde::~ZombieHorde(){
  delete [] m_Horde;
}

void ZombieHorde::announce(){
  for (int i = 0; i < m_N; i++){
    m_Horde[i].announce();
  }
}
