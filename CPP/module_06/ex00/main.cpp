#include "Convert.hpp"
#include <math.h>

int main(int ac, char **av){

  if (ac == 2){

    Convert conv = Convert(av[1]);
    double value;

    try {
      value = conv.Parsing();
    }
    catch (std::exception const &e){
      std::cout << "ERROR : " << e.what() << std::endl;
      return (1);
    }



    // -------- char ----------- //
    try {
      if (isnan(value)
      || -std::numeric_limits<double>::infinity() == value
      || +std::numeric_limits<double>::infinity() == value)
        throw std::string("impossible");
      if (!isprint(conv.toChar(value)))
        throw std::string("Non displayable");
      std::cout << "char: " << "'" << conv.toChar(value) << "'" << std::endl;
    }
    catch (std::string const &e){
      std::cout << "char: " << e << std::endl;
    }



    // -------- int ----------- //

    try {
      if (isnan(value)
        || -std::numeric_limits<double>::infinity() == value
        || +std::numeric_limits<double>::infinity() == value)
        throw std::string("impossible");
      std::cout << "int: " << conv.toInt(value) << std::endl;
    }
    catch (std::string const &e){
      std::cout << "int: " << e << std::endl;
    }



    // -------- float ---------- //

    float result_float = conv.toFloat(value);
    if (result_float - (int)result_float == (float)0)
      std::cout << "float: " << result_float << ".0f" << std::endl;
    else
      std::cout << "float: " << result_float << "f" << std::endl;




    // ------- double ---------- //

    double result_double = value;
    if (result_double - (int)result_double == (double)0)
      std::cout << "double: " << result_double << ".0" << std::endl;
    else
      std::cout << "double: " << result_double << std::endl;

  }
  else
    std::cout << "Wrong number of arguments" << std::endl;
  return (0);
}
