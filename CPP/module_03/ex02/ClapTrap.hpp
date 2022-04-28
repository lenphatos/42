#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap {

	public:
		//constructeur
		ClapTrap();
    ClapTrap(
			std::string _Name,
    	int         _HitPoints,
    	int         _MaxhitPoints,
    	int         _EnergyPoints,
    	int         _MaxEnergyPoints,
    	int         _Level,
    	int         _MeleeAttackDamage,
    	int         _RangedAttackDamage,
    	int         _ArmorDamageReduction
		);
		ClapTrap(const ClapTrap& other);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap();
		void _whoami(std::string& name, unsigned int hp);
    void rangedAttack(std::string const &target);
    void meleeAttack(std::string const &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

		// methodes




	protected:
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
