#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP
#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class NinjaTrap : virtual public ClapTrap{

	public:
		//constructeur
		NinjaTrap();
    NinjaTrap(std::string name);
		NinjaTrap(const NinjaTrap &other);
		NinjaTrap &operator=(const NinjaTrap &other);
		~NinjaTrap();

		// methodes
    void ninjaShoebox(const ScavTrap &target);
    void ninjaShoebox(const NinjaTrap &target);
    void ninjaShoebox(const FragTrap &target);





	private:
		// atributs
};

#endif
