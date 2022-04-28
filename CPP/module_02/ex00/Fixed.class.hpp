#ifndef FIXED_CLASSE_HPP
#define FIXED_CLASSE_HPP
#include <iostream>

class Fixed {

	public:
		//constructeur
		Fixed();
    Fixed(Fixed const &other);
		Fixed &operator=(const Fixed &other);
		~Fixed();

		// methodes
    int   getRawBits(void) const;
    void  setRawBits(int const raw);




	private:
		// atributs
    int               m_fixed;
    const static int  m_bits = 8;

};

#endif
