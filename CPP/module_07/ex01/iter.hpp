#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void iter(T *adr, size_t size, void (*fnc)(T const &)){
  for (size_t i = 0; i < size ; i++){
    fnc(adr[i]);
  }
}

template<typename T>
void print_something(T &nb){
  std::cout  << nb << std::endl;
}

#endif
