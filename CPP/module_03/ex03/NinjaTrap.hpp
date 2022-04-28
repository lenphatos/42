#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP
#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

class NinjaTrap : public ClapTrap{

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
