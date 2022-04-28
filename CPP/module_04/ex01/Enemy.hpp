#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <iostream>
#include <string>

class Enemy {

  public:
    // Constructor
    Enemy(int hp, std::string const &type);
    Enemy(Enemy const& other);
    virtual ~Enemy();
    Enemy &operator=(Enemy const& other);

    // Methodes
    std::string   getType() const;
    int           getHP() const;
    virtual void  takeDamage(int nb);

  protected:
    std::string   _Type;
    int           _Hp;
};

#endif
