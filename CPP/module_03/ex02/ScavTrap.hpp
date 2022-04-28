#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{

	public:
		//constructeur
		ScavTrap();
    ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other);
		ScavTrap &operator=(const ScavTrap &other);
		~ScavTrap();

		// methodes
    void challengeNewcomer(std::string const & target);




	private:
		// atributs
};

#endif
