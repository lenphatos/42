#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const &type) :
_Type(type),
_Hp(hp)
{}

Enemy::Enemy(Enemy const& other) :
_Type(other._Type),
_Hp(other._Hp)
{}

Enemy::~Enemy(){}

Enemy &Enemy::operator=(Enemy const& other) {
  if (this != &other){
    _Type = other._Type;
    _Hp = other._Hp;
  }
  return (*this);
}

std::string Enemy::getType() const {return (_Type);}
int    Enemy::getHP() const {return (_Hp);}

void Enemy::takeDamage(int nb) {
  (nb > 0) ? _Hp -= nb : 0;
  (_Hp < 0) ? _Hp = 0 : 0;
}
