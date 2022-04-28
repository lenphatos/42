#include <iostream>
#include <string>
#include "Fixed.class.hpp"

// Constructor
Fixed::Fixed() : m_fixed(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nb){
  m_fixed = nb * 256;
}

Fixed::Fixed(const float nb){
  m_fixed = nb * 256;
}

Fixed::Fixed(Fixed const &other){
	std::cout << "Copy constructor called" << std::endl;
 	m_fixed = other.getRawBits();
}

// Destructor
Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

// Operator
Fixed &Fixed::operator=(const Fixed &other){
  m_fixed = other.getRawBits();
  return (*this);
}

// Methodes
int   Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
    return (m_fixed);
}

void  Fixed::setRawBits(int const raw){
  m_fixed = raw;
}

int Fixed::toInt(void) const{
  return ((int)(m_fixed / 256));
}

float Fixed::toFloat(void) const{
  return ((float)m_fixed / 256);
}

std::ostream &operator<<(std::ostream& os, const Fixed &other)
{
    os << other.toFloat();
    return os;
}
