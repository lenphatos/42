#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : m_name(name){}

HumanB::~HumanB(){}

void HumanB::attack(){
	std::cout << m_name << " attacks with his " << m_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &club){
  m_weapon = &club;
}
