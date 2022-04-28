#include "Squad.hpp"

Squad::Squad() {}

Squad::Squad(Squad const& other) : _ListMarine(other._ListMarine){}

Squad::~Squad() {
  for (int i = 0; i < getCount(); i++) {
    delete _ListMarine[i];
  }
}

Squad &Squad::operator=(Squad const& other) {
  if (this != &other) {
    for (int i = 0; i < other.getCount(); i++) {
      _ListMarine.push_back(other._ListMarine[i]);
    }
  }
  return (*this);
}

int  Squad::getCount() const {
  return (_ListMarine.size());
}
int  Squad::push(ISpaceMarine* IS_Marine) {
  if (!IS_Marine)
    return (1);
  _ListMarine.push_back(IS_Marine);
  return (0);
}
ISpaceMarine* Squad::getUnit(int unity_X) const{
  return (_ListMarine[unity_X]);
}
