#include "Convert.hpp"

Convert::Convert(char *string) : _String(string){}

Convert::~Convert(){}

Convert::Convert(Convert const &other){
  _String = other._String;
}

Convert &Convert::operator=(Convert const &other){(void)other; return (*this);}

double  Convert::Parsing(){
 	
	double value;
    
	if (_String[0] == '\'' && _String[2] == '\'' && strlen(_String) == 3)
        	return (static_cast<double>(_String[1]));
    	value = std::atof(_String);
  	if (_String[0] != '0' && value == 0)
	       throw Convert::Error();
  	return (value);
}

char    Convert::toChar(double value){

  return (static_cast<char>(value));
}

int     Convert::toInt(double value){

  return (static_cast<int>(value));
}

float   Convert::toFloat(double value){

  return (static_cast<float>(value));
}

double  Convert::toDouble(double value){
  return (value);
}


// EXCEPTION


Convert::Error::Error() throw (){}
Convert::Error::~Error() throw (){}
Convert::Error::Error(Error const &other) throw (){(void)other;}

Convert::Error &Convert::Error::operator=(Error const &other) throw (){(void)other;return (*this);}

const char* Convert::Error::what() const throw() {return ("Invalid Argument");}
