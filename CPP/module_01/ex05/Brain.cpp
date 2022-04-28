#include <iostream>
#include <sstream>
#include "Brain.hpp"

Brain::Brain(): m_nbQi(95), m_age(36){}

Brain::~Brain(){}

std::string  Brain::identify()
{
  std::stringstream address;
  address << this;
  return (address.str());
}

// SETTER
void Brain::setQI(int qi){this->m_nbQi = qi;}
void Brain::setAge(int age){this->m_age = age;}
// GETTER
int Brain::getQI(void){return (this->m_nbQi);}
int Brain::getAge(void){return (this->m_age);}
