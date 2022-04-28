#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include <iostream>

class FragTrap {

	public:
		//constructeur
		FragTrap();
    FragTrap(std::string name);
		FragTrap &operator=(const FragTrap &other);
		~FragTrap();

		// methodes
    void rangedAttack(std::string const &target);
    void meleeAttack(std::string const &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void vaulthunter_dot_exe(std::string const & target);

		void attack_ninja(std::string const &target);
		void attack_samourai(std::string const &target);
		void attack_sel(std::string const &target);
		void attack_supreme(std::string const &target);
		void attack_gun(std::string const &target);




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
