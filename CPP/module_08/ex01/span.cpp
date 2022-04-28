#include "span.hpp"
Span::Span(unsigned int N) : _NbValue(N){}

Span::Span(const Span &other){
  this->_Min = other._Min;
  this->_Max = other._Max;
  this->_NbValue = other._NbValue;
  this->_Values = other._Values;
}

Span::~Span(){}


Span &Span::operator=(const Span &other){(void)other;return (*this);}

int ABS(int nb){
  return ((nb < 0) ? (nb * -1) : nb);
}

int  Span::shortestSpan(void){
  int result = _Max;
  size_t a;
  size_t i = 0;
  if (_Values.size() <= 1)
    throw Span::NoEnoughNumbers();
  while (i < _Values.size())
  {
    a = i + 1;
    while (a < _Values.size()){
      if (ABS((_Values[i] - _Values[a])) < result){
        result = ABS(_Values[i] - _Values[a]);
      }
        a++;
    }
    i++;
  }
  return (result);
}

int  Span::longestSpan(void){
  if (_Values.size() <= 1)
    throw Span::NoEnoughNumbers();
  return (_Max - _Min);
}

void Span::addNumber(int nb){

  if (_Values.size() == 0){
    _Min = nb;
    _Max = nb;
  }
  if (nb > _Max)
    _Max = nb;
  if (nb < _Min)
    _Min = nb;

  if (_Values.size() < _NbValue)
    _Values.push_back(nb);
  else
    throw Span::NoEnoughSpace();
}
