#ifndef SQUAD_HPP
#define SQUAD_HPP
#include <iostream>
#include <vector>
#include "ISpaceMarine.hpp"
#include "ISquad.hpp"

class Squad : public ISquad {

  public:
    Squad();
    Squad(Squad const& other);
    ~Squad();
    Squad &operator=(Squad const& other);



    int           getCount() const;
    int           push(ISpaceMarine* IS_Marine);
    ISpaceMarine* getUnit(int unity_X) const;

  private:
    std::vector<ISpaceMarine*> _ListMarine;
};

#endif
