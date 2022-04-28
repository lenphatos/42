#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

	public:
		//constructeur
		FragTrap();
    FragTrap(std::string name);
		FragTrap(const FragTrap &other);
		FragTrap &operator=(const FragTrap &other);
		~FragTrap();

		// methodes
    void vaulthunter_dot_exe(std::string const & target);
		void attack_ninja(std::string const &target);
		void attack_samourai(std::string const &target);
		void attack_sel(std::string const &target);
		void attack_supreme(std::string const &target);
		void attack_gun(std::string const &target);




	private:
		// atributs

};

#endif
