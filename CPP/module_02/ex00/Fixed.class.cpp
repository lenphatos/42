#include <iostream>
#include <string>
#include "Fixed.class.hpp"

Fixed::Fixed() : m_fixed(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &other){
	std::cout << "Copy constructor called" << std::endl;
  m_fixed = other.getRawBits();
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other){
	std::cout << "Assignation operator called" << std::endl;
  if (this == &other)
    return (*this);
  m_fixed = other.getRawBits();
  return (*this);
}

int   Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
    return (m_fixed);
}

void  Fixed::setRawBits(int const raw){
  m_fixed = raw;
}
