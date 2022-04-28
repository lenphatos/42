#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{

	public:
		//constructeur
		ScavTrap();
    ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other);
		ScavTrap &operator=(ScavTrap const &other);
		~ScavTrap();

		// methodes
    void challengeNewcomer(std::string const & target);




	private:
		// atributs
};

#endif
