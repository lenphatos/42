#ifndef HUMAN_HPP
#define HUMAN_HPP
#include "Human.hpp"
#include "Brain.hpp"

class Human {

  public:
    //constructeur
     Human();
     ~Human();

    // methodes
    std::string identify();
    Brain       &getBrain();




  private:
    // atributs
    Brain *m_brain;

};

#endif
