#include "Array.hpp"

int main() {

  std::cout << "//-----INT_ARRAY------\\\\\n" << std::endl;

  Array<int> int_array(5);

  try {
      int_array[0] = 42;
      int_array[1] = 41;
      int_array[2] = 40;
      int_array[3] = 0;
      int_array[4] = 1;
      //ERROR
      int_array[18] = 1;    
  }
  catch(std::exception &e){std::cout << "ERROR : " << e.what() << std::endl;}


  std::cout  << "index[0] : " << int_array[0] << std::endl;
  std::cout  << "index[1] : " << int_array[1] << std::endl;

  std::cout << "\n//----INT_ARRAY_COPY----\\\\" << std::endl;


  Array<int> int_array_copy(int_array);

  std::cout  << "index[0] : " << int_array[0] << std::endl;
  std::cout  << "index[1] : " << int_array[1] << std::endl;

  std::cout << "Modif first array" << std::endl;

      int_array[0] = -1;

  std::cout  << "(first array) index[0] : " << int_array[0] << std::endl;
  std::cout  << "(copy array)  index[0] : " << int_array_copy[0] << std::endl;




  std::cout << "\n//-----STRING_ARRAY------\\\\" << std::endl;


  Array<std::string> string_array(2);

  string_array[0] = "bonjour";
  string_array[1] = "Aurevoir";

  std::cout  <<"index[0] : " << string_array[0] << std::endl;
  std::cout  <<"index[1] : " << string_array[1] << std::endl;

  try {

        std::cout  <<"index[0] : " << string_array[0] << std::endl;
        std::cout  <<"index[1] : " << string_array[1] << std::endl;
        std::cout  <<"index[2] : " << string_array[3] << std::endl;

  }
  catch(std::exception &e){std::cout << "ERROR : " << e.what() << std::endl;}
  return 0;
}
