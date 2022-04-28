#include <iostream>
#include <string>
#include "Zombie.hpp"

using namespace std;

Zombie::Zombie(){}

Zombie::Zombie(std::string name, std::string type) : m_name(name), m_type(type) {}

Zombie::~Zombie(){}

// SETTER
void Zombie::setType(std::string type){this->m_type = type;}
void Zombie::setName(std::string name){this->m_name = name;}
// GETTER
std::string Zombie::getType(){return (m_type);}
std::string Zombie::getName(){return (m_name);}

void Zombie::announce(){
  cout << "<" << m_name << " (" << m_type << ")>  Braiiiiiiinnnssss ..." << endl;
}
