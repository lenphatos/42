#ifndef SUPERTRAP_HPP
#define SUPERTRAP_HPP
#include <iostream>
#include "NinjaTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"


class SuperTrap : public NinjaTrap, public FragTrap
{

	public:
		//constructeur
		SuperTrap();
    SuperTrap(std::string name);
		SuperTrap(const SuperTrap &other);
		SuperTrap &operator=(const SuperTrap &other);
		~SuperTrap();

		// methodes





	private:
		// atributs
};

#endif
