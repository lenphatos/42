#include <iostream>
#include <string>
#include "Human.hpp"
#include "Brain.hpp"

Human::Human() : m_brain(new Brain()){}

Human::~Human(){
}

std::string Human::identify(){
  return (m_brain->identify());
}

Brain &Human::getBrain(){
  return (*m_brain);
}
