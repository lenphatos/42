#include <iostream>
#include <string>
#include "Pony.hpp"

Pony::Pony() {}

Pony::~Pony() {}

Pony::Pony(int age, int size, std::string color, std::string name) {
  m_age = age;
  m_color = color;
  m_name = name;
  m_size = size;
}

void Pony::describe(){
  std::cout << "Hello, my name is " << m_name << std::endl;
  std::cout << "I'm " << m_age << " years old" << std::endl;
  std::cout << "My color is " << m_color << std::endl;
  std::cout << "And my size : " << m_size << "cm" << std::endl;
}
