#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::Zombie(std::string name, std::string type) : m_name(name), m_type(type) {}

Zombie::~Zombie(){}

void Zombie::advert(){
  std::cout << "<" << m_name << " (" << m_type << ")>  Braiiiiiiinnnssss ..." << std::endl;
}
