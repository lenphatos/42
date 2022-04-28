#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"



class Character : public ICharacter {

  public:
    Character(std::string name);
    Character(Character const &other);
    virtual ~Character();
    Character &operator=(Character const &other);
    virtual std::string const & getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);

  private:
    std::string  _Name;
    AMateria*    _Inventory[4];
};

#endif
