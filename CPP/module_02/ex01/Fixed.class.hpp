#ifndef FIXED_CLASSE_HPP
#define FIXED_CLASSE_HPP
#include <iostream>
# include <cmath>

class Fixed {

	public:
		//constructeur
		Fixed();
    Fixed(Fixed const &other);
    Fixed(const int nb);
    Fixed(const float nb);
		Fixed &operator=(const Fixed &other);
		~Fixed();

		// methodes
    int toInt(void) const;
    float toFloat(void) const;
    int   getRawBits(void) const;
    void  setRawBits(int const raw);




	private:
		// atributs
    int               m_fixed;
    const static int  m_bits = 8;

};

std::ostream &operator<<(std::ostream& os, const Fixed &other);

#endif
