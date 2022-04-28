#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include <iostream>

class ScavTrap {

	public:
		//constructeur
		ScavTrap();
    ScavTrap(std::string name);
		ScavTrap &operator=(const ScavTrap &other);
		~ScavTrap();

		// methodes
    void rangedAttack(std::string const &target);
    void meleeAttack(std::string const &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void challengeNewcomer(std::string const & target);




	private:
		// atributs
    std::string _Name;
    int         _HitPoints;
    int         _MaxhitPoints;
    int         _EnergyPoints;
    int         _MaxEnergyPoints;
    int         _Level;
    int         _MeleeAttackDamage;
    int         _RangedAttackDamage;
    int         _ArmorDamageReduction;

};

#endif
