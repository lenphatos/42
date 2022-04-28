#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>


template <typename T>
int easyfind(T &tab, int nb) {

  typename T::iterator it;

  it = find(tab.begin(), tab.end(), nb);
  if (it == tab.end())
    throw std::exception();
  return (*it);
}

#endif
