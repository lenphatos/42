#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
  for (int i = 0; i < 4; i++)
    _Template[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &other) {
  for (int i = 0; i < 4; i++)
    _Template[i] = other._Template[i];
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other) {
  if (this != &other) {
    for (int i = 0; i < 4; i++)
      _Template[i] = other._Template[i];
  }
  return (*this);
}

MateriaSource::MateriaSource::~MateriaSource(){
  for (int i = 0; i < 4; i++)
    if (_Template[i])
      delete _Template[i];
}

void MateriaSource::learnMateria(AMateria* m) {
  int i;
  for (i = 0; i < 4 && _Template[i]; i++);
  _Template[i] = m;
}
AMateria *MateriaSource::createMateria(std::string const & type){
  for (int i = 0; i < 4; i++)
    if (_Template[i] != NULL && _Template[i]->getType() == type){
      return (_Template[i]->clone());
    }
  return (0);
}
