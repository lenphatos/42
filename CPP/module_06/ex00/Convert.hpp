#ifndef CONVERT_HPP
#define CONVERT_HPP
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <limits>


class Convert {

  // Constructor & Operator & Destructor
  public:
  Convert(char *target);
  ~Convert();
  Convert(Convert const &other);
  double Parsing(void);
  Convert &operator=(Convert const &other);

  // Getters & Setters

  // Methodes
  int     toInt(double value);
  char    toChar(double value);
  float   toFloat(double value);
  double  toDouble(double value);
  
  private:
    char *_String;


      class Error : public std::exception {
      public:
        // Constructor & Operator & Destructor
        Error() throw ();
        virtual ~Error() throw ();
        Error(Error const &other) throw ();
        Error &operator=(Error const &other) throw ();
        // Methodes
        virtual const char* what() const throw();

    };
};

#endif
