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
		~Fixed();
		Fixed &operator=(const Fixed &other);

		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);

		// Operator Comparaison
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;

		// Operator arithmétique
		Fixed operator+(const Fixed &other);
		Fixed operator-(const Fixed &other);
		Fixed operator*(const Fixed &other);
		Fixed operator/(const Fixed &other);
		const static Fixed &min(const Fixed &a, const Fixed &b);
		const static Fixed &max(const Fixed &a, const Fixed &b);

		// methodes
    float 	toFloat(void) const;
		int 		toInt(void) const;
    int   	getRawBits(void) const;
    void  	setRawBits(int const raw);




	private:
		// atributs
    int               m_convert_value;
    int               m_fixed;
    const static int  m_bits = 8;

};

std::ostream &operator<<(std::ostream& os, const Fixed &other);


#endif
